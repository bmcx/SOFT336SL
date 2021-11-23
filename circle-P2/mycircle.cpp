#include "mycircle.h"
#include <QPainter>

MyCircle::MyCircle(int value, QWidget *parent) : MyFigure(value, parent)
{

}

void MyCircle::drawMyFigure()
{
    int radius = width()/2;
    double factor = value()/100.0;
    QPainter p(this);
    p.setPen(Qt::black);
    p.drawEllipse(0,0,width()-1,width()-1);
    p.setBrush(Qt::black);
    p.drawEllipse((int)(radius*(1.0-factor)),
                  (int)(radius*(1.0-factor)),
                  (int)((width()-1)*factor)+1,
                  (int)((width()-1)*factor)+1);
}
