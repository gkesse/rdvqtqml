#include "SceneWidget.hpp"
#include <vtkCamera.h>
#include <vtkRenderWindow.h>
#include <vtkDataSetMapper.h>
#include <vtkGenericOpenGLRenderWindow.h>

SceneWidget::SceneWidget(QWidget *parent)
    : QVTKOpenGLNativeWidget(parent)
{
    vtkSmartPointer<vtkGenericOpenGLRenderWindow> window =
        vtkSmartPointer<vtkGenericOpenGLRenderWindow>::New();
    setRenderWindow(window.Get());

    // Camera
    vtkSmartPointer<vtkCamera> camera = vtkSmartPointer<vtkCamera>::New();
    camera->SetViewUp(0, 1, 0);
    camera->SetPosition(0, 0, 10);
    camera->SetFocalPoint(0, 0, 0);

    // Renderer
    m_renderer = vtkSmartPointer<vtkRenderer>::New();
    m_renderer->SetActiveCamera(camera);
    m_renderer->SetBackground(0.1, 0.1, 0.1);
    renderWindow()->AddRenderer(m_renderer);
}

SceneWidget::~SceneWidget()
{
}

void SceneWidget::addDataSet(vtkSmartPointer<vtkDataSet> dataSet)
{
    // Actor
    vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();

    // Mapper
    vtkSmartPointer<vtkDataSetMapper> mapper = vtkSmartPointer<vtkDataSetMapper>::New();
    mapper->SetInputData(dataSet);
    actor->SetMapper(mapper);

    m_renderer->AddActor(actor);
    m_renderer->ResetCamera(dataSet->GetBounds());

    renderWindow()->Render();
}

void SceneWidget::removeDataSet()
{
    vtkActor *actor = m_renderer->GetActors()->GetLastActor();
    if (actor != nullptr)
    {
        m_renderer->RemoveActor(actor);
    }

    renderWindow()->Render();
}

void SceneWidget::zoomToExtent()
{
    vtkSmartPointer<vtkActor> actor = m_renderer->GetActors()->GetLastActor();
    if (actor != nullptr)
    {
        m_renderer->ResetCamera(actor->GetBounds());
    }

    renderWindow()->Render();
}
