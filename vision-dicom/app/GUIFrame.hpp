#pragma once

#include "Frameless.hpp"

namespace Ui
{
    class GUIFrame;
}

class GUIFrame final : public Frameless
{
    Q_OBJECT

public:
    explicit GUIFrame(QWidget *parent = nullptr);
    ~GUIFrame();

private:
    void initView();
    void updateMaximizeButton(const bool &maximized) const;
    void createMenuBar();

protected:
    void changeEvent(QEvent *t_event) override;

private slots:
    void onClose();
    void onMaximize();
    void onMinimize();

private:
    Ui::GUIFrame *ui;
};
