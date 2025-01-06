#ifndef ACTIVATIONFUNCTION_H
#define ACTIVATIONFUNCTION_H
//.....BUILT-IN LIBRARIES.....
#include <string>
#include <vector>
#include <cmath>
//.....CUSTOM LIBRARIES.....
#include "../NetworkUnit.h"

template<typename T>
class  Sigmoid : public NetworkUnit<T>
{
    T sigmoid(T x)
    {
        return 1.0 / (1.0 + exp(-x));
    }
    public:
        Sigmoid(size_t inputs)
        {
            this->inputs = std::vector<T>(inputs);
        }
        std::vector<T> forwardPropagate(std::vector<T> x) override
        {
            this->inputs = x;
            std::vector<T> result(x.size());
            for (size_t i = 0; i < x.size(); i++) {
                result[i] = sigmoid(x[i]);
            }
            return result;
        }
        std::vector<T> backwardPropagate(std::vector<T> gradient) override
        {
            std::vector<T> result(gradient.size());
            for (size_t i = 0; i < gradient.size(); i++) {
                result[i] = gradient[i] * (1 - sigmoid(this->inputs[i])) * sigmoid(this->inputs[i]);
            }
            return result;
        }
        size_t getOutputSize() override
        {
            return this->inputs.size();
        }
};
#endif

