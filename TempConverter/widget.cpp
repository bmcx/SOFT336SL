#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    tc = new TempConverter(this);
    QObject::connect(ui->dialCelsius, SIGNAL(valueChanged(int)), tc, SLOT(setTempCelsius(int)));
    QObject::connect(ui->dialFahrenheit, SIGNAL(valueChanged(int)), tc, SLOT(setTempFahrenheit(int)));

    QObject::connect(tc, SIGNAL(tempCelsiusChanged(int)), ui->dialCelsius, SLOT(setValue(int)));
    QObject::connect(tc, SIGNAL(tempFahrenheitChanged(int)), ui->dialFahrenheit, SLOT(setValue(int)));
}

Widget::~Widget()
{
    delete ui;
}

