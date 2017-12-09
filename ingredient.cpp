#include <iostream>
#include <string>
#include <vector>
#include "ingredient.h"

void ingredient::setName(std::string temp_name)
{
        name = temp_name;
}

void ingredient::setAmount(double temp_amnt)
{
        amount = temp_amnt;
}

void ingredient::setMeasurement(std::string temp_measure)
{
        measurement = temp_measure;
}

std::string ingredient::getName()
{
        return name;
}

double ingredient::getAmount()
{
        return amount;
}

std::string ingredient::getMeasurement()
{
        return measurement;
}
