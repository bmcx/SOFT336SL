#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    c = new MyCircle(0, this);
    r = new MyRect(0, this);
    ui->setupUi(this);
    ui->layout->addWidget(c);
    ui->layout->addWidget(r);
    QObject::connect(ui->hSlider,SIGNAL(valueChanged(int)),c,SLOT(setValue(int)));
    QObject::connect(ui->hSlider,SIGNAL(valueChanged(int)),r,SLOT(setValue(int)));
}

Widget::~Widget()
{
    delete ui;
}

