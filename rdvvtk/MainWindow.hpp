#pragma once

#include <QMainWindow>

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = Q_NULLPTR);
    ~MainWindow();

private:
    void openFile(const QString &fileName);

public slots:
    void showAboutDialog();
    void showOpenFileDialog();

private:
    Ui::MainWindow *ui;
};
