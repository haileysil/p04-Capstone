#ifndef _INGREDIENT_H_
#define _INGREDIENT_H_

#include <string>
#include <vector>

class ingredient
{
        private:
                std::string name;

                double amount;

                std::string measurement;

        public:
                void setName(std::string);
                void setAmount(double);
                void setMeasurement(std::string);

                std::string getName();
                double getAmount();
                std::string getMeasurement();
};

#endif

