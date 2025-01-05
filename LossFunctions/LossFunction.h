#ifndef LOSSFUNCTION_H
#define LOSSFUNCTION_H
//.....BUILT-IN LIBRARIES.....
#include <string>
#include <vector>
//.....CUSTOM LIBRARIES.....
#include "L2Loss.h"

template<typename T>
class LossFunction
{
    private:
        T (*lossFunction)(std::vector<T>,std::vector<T>);
    public:
        LossFunction()
        {
            this->lossFunction=nullptr;
        }
        LossFunction(std::string name)
        {
            if(name=="l2")
            {
                this->lossFunction=L2Loss<T>::calculateLoss;
            }
        }
        T calculateLoss(std::vector<T> inputs,std::vector<T> targets)
        {
            return lossFunction(inputs,targets);
        }
};
#endif

