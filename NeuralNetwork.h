#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H

#include <vector>
#include "NetworkUnits/NetworkUnit.h"
template<typename T>
class NeuralNetwork {
    private:
        std::vector<NetworkUnit*> networkUnits;
    public:
        void addLayer(uint_t inputs,uint_t perceptronsCount,float learningRate)
        {
            networkUnits.push_back(new Layer<T>(inputs,perceptronsCount,learningRate));
        }
        void addActivationFunction(std::string name)
        {
            networkUnits.push_back(new ActivationFunction<T>(name));
        }
};

#endif // NEURALNETWORK_H