#ifndef SIGMOID_H
#define SIGMOID_H
//.....BUILT-IN LIBRARIES.....
#include <cmath>

template<typename T>
class Sigmoid {
public:
    static std::vector<T> function(std::vector<T> x) {
        std::vector<T> result(x.size());
        for (size_t i = 0; i < x.size(); i++) {
            result[i] = 1.0 / (1.0 + exp(-x[i]));
        }
        return result;
    }
    static std::vector<T> derivative(std::vector<T> x) {
        std::vector<T> result(x.size());
        for (size_t i = 0; i < x.size(); i++) {
            result[i] = x[i] * (1.0 - x[i]);
        }
        return result;
    }
};

#endif