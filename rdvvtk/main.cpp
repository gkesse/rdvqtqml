#include "MainWindow.hpp"
#include <QApplication>
#include <QSurfaceFormat>
#include <QVTKOpenGLNativeWidget.h>

int main(int argc, char *argv[])
{
    qDebug() << "(rdvvtk) Demarrage de l'application";
    QSurfaceFormat::setDefaultFormat(QVTKOpenGLNativeWidget::defaultFormat());

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
