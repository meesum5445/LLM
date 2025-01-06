#ifndef LOSSFUNCTION_H
#define LOSSFUNCTION_H

//.....BUILT-IN LIBRARIES.....
#include <vector>
#include <string>
#include <stdexcept>


template<typename T>
class LossFunction {
public:
    // Structure Variables
    std::vector<T> loss;
    // Method to calculate loss
    virtual std::vector<T> calculateLoss(const std::vector<T>& predicted, const std::vector<T>& actual) = 0;
    // Method to calculate derivative of loss
    virtual std::vector<T> calculateDerivative(const std::vector<T>& predicted, const std::vector<T>& actual) = 0;
};

#endif // LOSSFUNCTION_H
