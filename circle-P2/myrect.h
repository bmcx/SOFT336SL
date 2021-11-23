#ifndef MYRECT_H
#define MYRECT_H

#include "myfigure.h"

class MyRect : public MyFigure
{
public:
    MyRect(int value, QWidget *parent = nullptr);
    void drawMyFigure();
};

#endif // MYRECT_H
