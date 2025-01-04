#ifndef SIGMOID_H
#define SIGMOID_H
//.....BUILT-IN LIBRARIES.....
#include <cmath>

template<typename T>
class Sigmoid {
public:
    static T function(T x) {
        return 1.0 / (1.0 + std::exp(-x));
    }
    static T derivative(T x) {
        return x * (1.0 - x);
    }
};

#endif