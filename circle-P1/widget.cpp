#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    c = new MyCircle(0, this);
    ui->setupUi(this);
    ui->layout->addWidget(c);
    QObject::connect(ui->hSlider,SIGNAL(valueChanged(int)),c,SLOT(setValue(int)));

}

Widget::~Widget()
{
    delete ui;
}

