#include "GUIFrame.hpp"
#include "ui_GUIFrame.h"
#include "base/Tools.hpp"
#include <QIcon>
#include <QWindowStateChangeEvent>

GUIFrame::GUIFrame(QWidget *parent)
    : Frameless(parent),
      ui(new Ui::GUIFrame)
{
    initView();
}

GUIFrame::~GUIFrame()
{
    delete ui;
}

void GUIFrame::initView()
{
    ui->setupUi(this);
    setAutoFillBackground(false);
    ui->maximizeButton->setIcon(QIcon(oConfig.app_maximize_on_icon.c_str()));

    ui->icon->setPixmap(QPixmap::fromImage(
        QImage(oConfig.app_toolbar_icon.c_str())));

    updateMaximizeButton(isMaximized());
    setResizeableAreaWidth(8);
    setTitleBar(ui->widgetTopBar);
    ignoreWidget(ui->labelTitle);
    ignoreWidget(ui->icon);
    createMenuBar();
}

void GUIFrame::updateMaximizeButton(const bool &maximized) const
{
    if (maximized)
    {
        ui->maximizeButton->setIcon(QIcon(oConfig.app_maximize_on_icon.c_str()));
        ui->maximizeButton->setToolTip(tr("Restore"));
    }
    else
    {
        ui->maximizeButton->setIcon(QIcon(oConfig.app_maximize_off_icon.c_str()));
        ui->maximizeButton->setToolTip(tr("Maximize"));
    }
}

void GUIFrame::createMenuBar()
{
}

void GUIFrame::changeEvent(QEvent *t_event)
{
    if (t_event->type() == QEvent::WindowStateChange)
    {
        auto *event = dynamic_cast<QWindowStateChangeEvent *>(t_event);
        if (event->oldState() & Qt::WindowMaximized && !isMaximized())
        {
            updateMaximizeButton(false);
        }
        else if (isMaximized())
        {
            updateMaximizeButton(true);
        }
    }
    t_event->accept();
}

void GUIFrame::onClose()
{
    close();
}

void GUIFrame::onMaximize()
{
    isMaximized() ? showNormal() : showMaximized();
}

void GUIFrame::onMinimize()
{
    showMinimized();
}
