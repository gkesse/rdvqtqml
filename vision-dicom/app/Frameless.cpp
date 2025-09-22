#include "Frameless.hpp"

Frameless::Frameless(QWidget *parent)
    : QFrame(parent),
      m_bResizeable(true),
      m_borderWidth(5)
{
    setWindowFlags(
        windowFlags() | Qt::Window |
        Qt::FramelessWindowHint | Qt::WindowSystemMenuHint);
    setResizeable(m_bResizeable);
}

void Frameless::setResizeableAreaWidth(int width)
{
    if (1 > width)
        width = 1;
    m_borderWidth = width;
}

void Frameless::setTitleBar(QWidget *titlebar)
{
    m_titlebar = titlebar;
    if (!titlebar)
        return;
    connect(titlebar, SIGNAL(destroyed(QObject *)), this, SLOT(onTitleBarDestroyed()));
}

void Frameless::ignoreWidget(QWidget *widget)
{
    if (!widget)
        return;
    if (m_whiteList.contains(widget))
        return;
    m_whiteList.append(widget);
}

void Frameless::setResizeable(const bool resizeable)
{
    // const bool visible = isVisible();
    // m_bResizeable = resizeable;
    // if (m_bResizeable)
    // {
    //     setWindowFlags(windowFlags() | Qt::WindowMaximizeButtonHint);
    //     auto hwnd = reinterpret_cast<HWND>(this->winId());
    //     const DWORD style = ::GetWindowLong(hwnd, GWL_STYLE);
    //     ::SetWindowLong(hwnd, GWL_STYLE, style | WS_MAXIMIZEBOX | WS_THICKFRAME | WS_CAPTION);
    // }
    // else
    // {
    //     setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);
    //     auto hwnd = reinterpret_cast<HWND>(this->winId());
    //     const DWORD style = ::GetWindowLong(hwnd, GWL_STYLE);
    //     ::SetWindowLong(hwnd, GWL_STYLE, style & ~WS_MAXIMIZEBOX & ~WS_CAPTION);
    // }
    // const MARGINS shadow = {1, 1, 1, 1};
    // DwmExtendFrameIntoClientArea(HWND(winId()), &shadow);
    // setVisible(visible);
}

bool Frameless::nativeEvent(const QByteArray &eventType, void *message, qintptr *result)
{
#if (QT_VERSION == QT_VERSION_CHECK(5, 11, 1))
    MSG *msg = *reinterpret_cast<MSG **>(message);
#else
    MSG *msg = static_cast<MSG *>(message);
#endif

    return QFrame::nativeEvent(eventType, message, result);
}

void Frameless::onTitleBarDestroyed()
{
}
