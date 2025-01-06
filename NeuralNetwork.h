#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H
//.....BUILT-IN LIBRARIES.....
#include <vector>
#include <string>
#include <stdexcept>
//.....CUSTOM LIBRARIES.....
#include "NetworkUnits/NetworkUnit.h"
#include "NetworkUnits/Layer/Layer.h"
#include "NetworkUnits/ActivationFunctions/Sigmoid.h"
#include "LossFunctions/LossFunction.h"
#include "LossFunctions/L2Loss.h"

template<typename T>
class NeuralNetwork {
    private:
        // Structure Variables
        std::vector<NetworkUnit<T>*> networkUnits;
        LossFunction<T>* lossFunction;
        // Functional Functions
        std::vector<T> forwardPropagate(std::vector<T> inputs)
        {
            for(size_t i=0;i<networkUnits.size();i++)
            {
                inputs=networkUnits[i]->forwardPropagate(inputs);
            }
            return inputs;
        }
        // void backwardPropagate(std::vector<T> error)
        // {
        //     for(size_t i=networkUnits.size()-1;i>=0;i--)
        //     {
        //         error=networkUnits[i]->backwardPropagate(error);
        //     }
        // }
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
            if(name=="sigmoid")
                networkUnits.push_back(new Sigmoid<T>());
            else
                throw std::invalid_argument("Activation Function Not Found");
        }
        void setLossFunction(std::string name)
        {
            if(name=="l2")
                this->lossFunction = new L2Loss<T>();
            else
                throw std::invalid_argument("Loss Function Not Found");
        }
        // Functional Functions
        void train(std::vector<std::vector<T>> inputs,std::vector<std::vector<T>> outputs,size_t epochs)
        {
            for(size_t i=0;i<epochs;i++)
            {
                for(size_t j=0;j<inputs.size();j++)
                {
                    std::vector<T> result=forwardPropagate(inputs[j]);
                    std::vector<T> error=this->lossFunction->calculateLoss(result,outputs[j]);
                    // backwardPropagate(error);
                }
            }
        }
        std::vector<T> infer(std::vector<T> inputs)
        {
            return forwardPropagate(inputs);
        }
};

#endif