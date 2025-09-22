#include <iostream>
#include <QApplication>
#include <QWidget>
#include <QIcon>
#include "GUIFrame.hpp"
#include "base/Tools.hpp"

int main(int argc, char **argv)
{
    std::cout << "(rdvdicom): demarrage de l'application" << std::endl;

    QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);
    app.setWindowIcon(QIcon(oConfig.app_logo.c_str()));
    GUIFrame guiFrame;
    guiFrame.show();
    return app.exec();
}
