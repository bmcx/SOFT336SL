#include "calculator_interface.h"
#include "ui_calculator_interface.h"
#include "qregularexpression.h"

QRegularExpression rxDot("(\\d.\\d?)");
QRegularExpression rxMin("^-\\d*");
CalculatorInterface::CalculatorInterface(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CalculatorInterface)
{
    ui->setupUi(this);
}

CalculatorInterface::~CalculatorInterface()
{
    delete ui;
}

void CalculatorInterface::updateDisplay(QString num){
    ui->display->insert(num);
}

void CalculatorInterface::clearDisplay(){
    ui->display->clear();
}

void CalculatorInterface::on_btnPlus_clicked()
{
    double curValue = ui->display->text().toDouble();
    calculator.doAction(curValue, '+');
    clearDisplay();
}

void CalculatorInterface::on_btnMinus_clicked()
{
    double curValue = ui->display->text().toDouble();
    calculator.doAction(curValue, '-');
    clearDisplay();
}

void CalculatorInterface::on_btnMulti_clicked()
{
    double curValue = ui->display->text().toDouble();
    calculator.doAction(curValue, '*');
    clearDisplay();
}

void CalculatorInterface::on_btnDivi_clicked()
{
    double curValue = ui->display->text().toDouble();
    calculator.doAction(curValue, '/');
    clearDisplay();
}

void CalculatorInterface::on_btnEqual_clicked()
{
    double curValue = ui->display->text().toDouble();
    calculator.doAction(curValue, 'e');
    ui->display->setText(QString::number(calculator.getTotal()));
}

void CalculatorInterface::on_btnClear_clicked()
{
    calculator.clear();
    clearDisplay();
}

void CalculatorInterface::on_btnDot_clicked()
{
    QString display = ui->display->text();
    QRegularExpressionMatch match = rxDot.match(display);

    if(!match.hasMatch() && display != "."){
        updateDisplay(".");
    }
}

void CalculatorInterface::on_btnPlusMin_clicked()
{
    QString display = ui->display->text();
    QRegularExpressionMatch match = rxMin.match(display);
    if(match.hasMatch()){
        clearDisplay();
        updateDisplay(display.replace("-",""));
    }else{
        clearDisplay();
        updateDisplay("-"+display);
    }
}


void CalculatorInterface::on_btnOne_clicked()
{
    updateDisplay("1");
}


void CalculatorInterface::on_btnTwo_clicked()
{
    updateDisplay("2");
}


void CalculatorInterface::on_btnThree_clicked()
{
    updateDisplay("3");
}


void CalculatorInterface::on_btnFour_clicked()
{
    updateDisplay("4");
}


void CalculatorInterface::on_btnFive_clicked()
{
    updateDisplay("5");
}


void CalculatorInterface::on_btnSix_clicked()
{
    updateDisplay("6");
}


void CalculatorInterface::on_btnSeven_clicked()
{
    updateDisplay("7");
}


void CalculatorInterface::on_btnEight_clicked()
{
    updateDisplay("8");
}


void CalculatorInterface::on_btnNine_clicked()
{
    updateDisplay("9");
}


void CalculatorInterface::on_btnZero_clicked()
{
    updateDisplay("0");
}



