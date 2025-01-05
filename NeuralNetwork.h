#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H
//.....BUILT-IN LIBRARIES.....
#include <vector>
//.....CUSTOM LIBRARIES.....
#include "NetworkUnits/NetworkUnit.h"
#include "NetworkUnits/Layer/Layer.h"
#include "NetworkUnits/ActivationFunctions/ActivationFunction.h"
#include "LossFunctions/LossFunction.h"

template<typename T>
class NeuralNetwork {
    private:
        // Structure Variables
        std::vector<NetworkUnit<T>*> networkUnits;
        LossFunction<T> lossFunction;
        // Functional Functions
        std::vector<T> forwardPropagate(std::vector<T> inputs)
        {
            for(size_t i=0;i<networkUnits.size();i++)
            {
                inputs=networkUnits[i]->forwardPropagate(inputs);
            }
            return inputs;
        }
    public:
        // Structure Functions
        NeuralNetwork()
        {
            networkUnits=std::vector<NetworkUnit<T>*>();
        }
        void addLayer(size_t inputs,size_t perceptronsCount,float learningRate)
        {
            networkUnits.push_back(new Layer<T>(inputs,perceptronsCount,learningRate));
        }
        void addActivationFunction(std::string name)
        {
            networkUnits.push_back(new ActivationFunction<T>(name));
        }
        void setLossFunction(std::string name)
        {
            lossFunction=LossFunction<T>(name);
        }
        // Functional Functions
        void train(std::vector<std::vector<T>> inputs,std::vector<std::vector<T>> outputs,size_t epochs)
        {
            for(size_t i=0;i<epochs;i++)
            {
                T loss=0;
                for(size_t j=0;j<inputs.size();j++)
                {
                    std::vector<T> result=forwardPropagate(inputs[j]);
                    loss+=lossFunction.calculateLoss(result,outputs[j]);
                }
            }
        }
        std::vector<T> infer(std::vector<T> inputs)
        {
            return forwardPropagate(inputs);
        }
};

#endif