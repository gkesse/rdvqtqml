#include "MainWindow.hpp"
#include "ui_MainWindow.h"
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <vtkDataSetReader.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showAboutDialog()
{
    QMessageBox::information(
        this, "rdvVTK | About",
        "Produced By ReadyDEV\n"
        "3D Visualization with VTK");
}

void MainWindow::showOpenFileDialog()
{
    QString fileName = QFileDialog::getOpenFileName(
        this, tr("Open file"), "",
        "VTK Files (*.vtk)");

    // Open file
    QFile file(fileName);
    file.open(QIODevice::ReadOnly);

    // Return on Cancel
    if (!file.exists())
        return;

    openFile(fileName);
}

void MainWindow::openFile(const QString &fileName)
{
    ui->sceneWidget->removeDataSet();

    // Create reader
    vtkSmartPointer<vtkDataSetReader> reader = vtkSmartPointer<vtkDataSetReader>::New();
    reader->SetFileName(fileName.toStdString().c_str());

    // Read the file
    reader->Update();

    // Add data set to 3D view
    vtkSmartPointer<vtkDataSet> dataSet = reader->GetOutput();
    if (dataSet != nullptr)
    {
        ui->sceneWidget->addDataSet(reader->GetOutput());
    }
}
