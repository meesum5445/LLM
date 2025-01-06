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
    private:
        std::vector<T> outputs;
    public:
        std::vector<T> forwardPropagate(std::vector<T> x) {
            std::vector<T> result(x.size());
            for (size_t i = 0; i < x.size(); i++) {
                result[i] = 1.0 / (1.0 + exp(-x[i]));
            }
            return result;
        }
        std::vector<T> backwardPropagate(std::vector<T> x) {
            std::vector<T> result(x.size());
            for (size_t i = 0; i < x.size(); i++) {
                result[i] = x[i] * (1.0 - x[i]);
            }
            return result;
        }
};
#endif

