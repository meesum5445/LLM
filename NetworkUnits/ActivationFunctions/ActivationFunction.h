#ifndef ACTIVATIONFUNCTION_H
#define ACTIVATIONFUNCTION_H
//.....BUILT-IN LIBRARIES.....
#include <string>
#include <vector>
//.....CUSTOM LIBRARIES.....
#include "../NetworkUnit.h"
#include "Sigmoid.h"

template<typename T>
class ActivationFunction : public NetworkUnit<T>
{
    private:
        std::vector<T> (*function)(std::vector<T>);
        std::vector<T> (*derivative)(std::vector<T>);
    public:
        ActivationFunction()
        {
            this->function=nullptr;
            this->derivative=nullptr;
        }
        ActivationFunction(std::string name)
        {
            if(name=="sigmoid")
            {
                this->function=Sigmoid<T>::function;
                this->derivative=Sigmoid<T>::derivative;
            }
        }
        std::vector<T> forwardPropagate(std::vector<T> x)
        {
            return function(x);
        }
};
#endif

