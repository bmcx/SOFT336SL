#ifndef MYCIRCLE_H
#define MYCIRCLE_H

#include "myfigure.h"


class MyCircle : public MyFigure
{
    Q_OBJECT
public:
    explicit MyCircle(int value, QWidget *parent = nullptr);
    void drawMyFigure();

};

#endif // MYCIRCLE_H
