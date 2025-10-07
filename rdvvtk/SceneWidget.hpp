#pragma once

#include <QVTKOpenGLNativeWidget.h>
#include <vtkSmartPointer.h>
#include <vtkRenderer.h>
#include <vtkDataSet.h>

class SceneWidget : public QVTKOpenGLNativeWidget
{
    Q_OBJECT

public:
    explicit SceneWidget(QWidget *parent = Q_NULLPTR);
    ~SceneWidget();
    void addDataSet(vtkSmartPointer<vtkDataSet> dataSet);
    void removeDataSet();

public Q_SLOTS:
    void zoomToExtent();

private:
    vtkSmartPointer<vtkRenderer> m_renderer;
};
