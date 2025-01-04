#ifndef ACTIVATIONFUNCTION_H
#define ACTIVATIONFUNCTION_H
//.............................
#include <string>
#include "Sigmoid.h"

template<typename T>
class ActivationFunction
{
    public:
        static getActivationFunction(std::string name)
        {
            if(name=="sigmoid")
            {
                return Sigmoid<T>::function;
            }
        }
        static getActivationFunctionDerivative(std::string name)
        {
            if(name=="sigmoid")
            {
                return Sigmoid<T>::derivative;
            }
        }
};
//.............................
#endif

