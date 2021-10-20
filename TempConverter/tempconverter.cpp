#include "tempconverter.h"

TempConverter::TempConverter(QObject *parent) : QObject(parent) {}

void TempConverter::setTempCelsius(int tempCelsius)
{
    if(m_tempCelsius == tempCelsius) // this is to avoid infinite loop
        return;
    m_tempCelsius = tempCelsius;
    emit tempCelsiusChanged(m_tempCelsius);
    emit tempFahrenheitChanged(tempFahrenheit());
}

void TempConverter::setTempFahrenheit(int tempFahrenheit)
{
    int tempCelsius = (5.0/9.0)*(tempFahrenheit-32);
    setTempCelsius(tempCelsius);
}

int TempConverter::tempFahrenheit()
{
    int tempFahrenheit = m_tempCelsius * (9.0/5.0) + 32;
    return tempFahrenheit;
}
