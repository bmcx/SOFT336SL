#include "myrect.h"
#include <QPainter>

MyRect::MyRect(int value,  QWidget *parent) : MyFigure(value, parent){};


void MyRect::drawMyFigure()
{
    double factor = value()/100.0;
    QPainter p(this);
    p.setPen(Qt::black);
    p.drawRect(QRect(0,0,width()-1,height()-1));
    p.setBrush(Qt::black);
    p.drawRect((int)((width()/2)*(1.0-factor)),
               (int)((height()/2)*(1.0-factor)),
               (int)((width()-1)*factor)+1,
               (int)((height()-1)*factor)+1);
}
