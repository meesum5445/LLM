#ifndef CROSS_ENTROPY_H
#define CROSS_ENTROPY_H
//.....BUILT-IN LIBRARIES.....
#include <cmath>
#include <vector>
#include <cstdint>
//.....CUSTOM LIBRARIES.....
#include "LossFunction.h"

template<typename T>
class CrossEntropy : public LossFunction<T> {
public:
    CrossEntropy() {
        this->loss = std::vector<T>();
    }
    std::vector<T> calculateLoss(const std::vector<T>& predicted, const std::vector<T>& actual) override {
        this->loss.clear();
        for (size_t i = 0; i < predicted.size(); i++) {
            this->loss.push_back(-actual[i] * log(predicted[i]) - (1 - actual[i]) * log(1 - predicted[i]));
        }
        return this->loss;
    }
    std::vector<T> calculateGradient(const std::vector<T>& predicted, const std::vector<T>& actual) override {
        std::vector<T> gradient(predicted.size());
        for (size_t i = 0; i < predicted.size(); i++) {
            gradient[i] = (predicted[i] - actual[i]) / (predicted[i] * (1 - predicted[i]));
        }
        return gradient;
    }
};

#endif