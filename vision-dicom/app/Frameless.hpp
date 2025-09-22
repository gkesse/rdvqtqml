#pragma once

#include <QFrame>

class Frameless : public QFrame
{
    Q_OBJECT

public:
    explicit Frameless(QWidget *parent = nullptr);
    ~Frameless() = default;

protected:
    void setResizeableAreaWidth(int width = 5);
    void setTitleBar(QWidget *titlebar);
    void ignoreWidget(QWidget *widget);

private:
    void setResizeable(const bool resizeable);

protected:
    bool nativeEvent(const QByteArray &eventType, void *message, qintptr *result) override;

private slots:
    void onTitleBarDestroyed();

private:
    bool m_bResizeable;
    int m_borderWidth;
    QWidget *m_titlebar;
    QList<QWidget *> m_whiteList;
};
