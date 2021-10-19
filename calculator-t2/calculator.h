#ifndef CALCULATOR_H
#define CALCULATOR_H


class Calculator
{
public:
    Calculator();
    double total;
    char lastAction;
    double getTotal();
    void doAction(double num, char action);
    void setLastValue(double num);
    void clear();
    void add(double num);
    void substract(double num);
    void multiply(double num);
    void divide(double num);
};

#endif // CALCULATOR_H
