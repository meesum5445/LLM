#ifndef SIGMOID_H
#define SIGMOID_H

#include <cmath>

class Sigmoid {
public:
    static double function(double x) {
        return 1.0 / (1.0 + std::exp(-x));
    }
    static double derivative(double x) {
        return x * (1.0 - x);
    }
};

#endif