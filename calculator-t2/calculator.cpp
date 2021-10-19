#include "calculator.h"

Calculator::Calculator()
{
    total = 0;
    lastAction = 'e'; // 'e' means no action, empty!
}

double Calculator::getTotal(){
    return total;
}

void Calculator::clear(){
    total = 0;
}

void Calculator::doAction(double num, char action = 'e'){
    if(lastAction == 'e'){
        total = num;
    }else if(lastAction == '+'){
        this->add(num);
    }else if(lastAction == '-'){
        this->substract(num);
    }else if(lastAction == '*'){
        this->multiply(num);
    }else if(lastAction == '/'){
        this->divide(num);
    }
    this->lastAction = action;
}

void Calculator::add(double num) {
    total += num;
}

void Calculator::substract(double num) {
    total -= num;
}

void Calculator::multiply(double num) {
    total *= num;
}

void Calculator::divide(double num) {
    total /= num;
}
