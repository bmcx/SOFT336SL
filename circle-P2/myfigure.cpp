#include "myfigure.h"

MyFigure::MyFigure(int value, QWidget *parent) : QWidget(parent)
{
 m_value = value;
}

int MyFigure::heightForWidth(int width) const
{
    return width;
}

QSize MyFigure::sizeHint() const
{
    return QSize(100, 100);
}

int MyFigure::value() const
{
    return m_value;
}

void MyFigure::setValue(int value)
{
    if (value < 0)
        value = 0;
    if (value > 100)
        value = 100;
    if (m_value == value)
        return;
    m_value = value;
    update();
    emit valueChanged(m_value);
}

void MyFigure::paintEvent(QPaintEvent *event)
{
    drawMyFigure();
}
