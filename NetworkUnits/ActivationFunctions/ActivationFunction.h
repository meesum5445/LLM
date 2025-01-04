#ifndef ACTIVATIONFUNCTION_H
#define ACTIVATIONFUNCTION_H
//.....BUILT-IN LIBRARIES.....
#include <string>
//.....CUSTOM LIBRARIES.....
#include "../NetworkUnit.h"
#include "Sigmoid.h"

template<typename T>
class ActivationFunction : private NetworkUnit<T>
{
    private:
        vector<T> (*function)(vector<T>);
        vector<T> (*derivative)(vector<T>);
    public:
        ActivationFunction(std::string name)
        {
            if(name=="sigmoid")
            {
                this->function=Sigmoid<T>::function;
                this->derivative=Sigmoid<T>::derivative;
            }
        }
        T forwardPropagate(vector<T> x)
        {
            return function(x);
        }
        T backwardPropagate(vector<T> x)
        {
            return derivative(x);
        }
};
#endif

