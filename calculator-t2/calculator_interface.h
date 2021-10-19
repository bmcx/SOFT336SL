#ifndef CALCULATORINTERFACE_H
#define CALCULATORINTERFACE_H

#include <QWidget>
#include "calculator.h"

QT_BEGIN_NAMESPACE
namespace Ui { class CalculatorInterface; }
QT_END_NAMESPACE

class CalculatorInterface : public QWidget
{
    Q_OBJECT

public:
    CalculatorInterface(QWidget *parent = nullptr);
    ~CalculatorInterface();
    Calculator calculator;

private:
    void updateDisplay(QString val);
    void clearDisplay();

private slots:
    void on_btnOne_clicked();
    void on_btnPlus_clicked();
    void on_btnTwo_clicked();
    void on_btnThree_clicked();
    void on_btnFour_clicked();
    void on_btnFive_clicked();
    void on_btnSix_clicked();
    void on_btnSeven_clicked();
    void on_btnEight_clicked();
    void on_btnNine_clicked();
    void on_btnZero_clicked();
    void on_btnMinus_clicked();
    void on_btnEqual_clicked();
    void on_btnClear_clicked();
    void on_btnDot_clicked();
    void on_btnMulti_clicked();
    void on_btnDivi_clicked();

    void on_btnPlusMin_clicked();

private:
    Ui::CalculatorInterface *ui;
};
#endif // CALCULATORINTERFACE_H
