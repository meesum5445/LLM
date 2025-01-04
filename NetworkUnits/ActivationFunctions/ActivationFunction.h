#ifndef ACTIVATIONFUNCTION_H
#define ACTIVATIONFUNCTION_H
//.............................
#include <string>
#include "../NetworkUnit.h"
#include "Sigmoid.h"

template<typename T>
class ActivationFunction : private NetworkUnit<T>
{
    T (*function)(T);
    T (*derivative)(T);
    public:
        ActivationFunction(std::string name)
        {
            if(name=="sigmoid")
            {
                this->function=Sigmoid<T>::function;
                this->derivative=Sigmoid<T>::derivative;
            }
        }
        T forwardPropagate(T x)
        {
            return function(x);
        }
        T backwardPropagate(T x)
        {
            return derivative(x);
        }
};
//.............................
#endif

