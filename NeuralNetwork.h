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
#include "LossFunctions/L2.h"
#include "LossFunctions/CrossEntropy.h"

template<typename T>
class NeuralNetwork {
    private:
        // Structure Variables
        std::vector<NetworkUnit<T>*> networkUnits;
        LossFunction<T>* lossFunction;
        T learningRate;
        size_t inputSize;
        // Functional Functions
        std::vector<T> forwardPropagate(std::vector<T> inputs)
        {
            for(size_t i=0;i<networkUnits.size();i++)
            {
                inputs=networkUnits[i]->forwardPropagate(inputs);
            }
            return inputs;
        }
        void backwardPropagate(std::vector<T> gradient)
        {
            for(int i=networkUnits.size()-1;i>=0;i--)
            {
                gradient=networkUnits[i]->backwardPropagate(gradient);
            }
        }
    public:
        // Structure Functions
        NeuralNetwork(){}
        void setLearningRate(T learningRate)
        {
            this->learningRate=learningRate;
        }
        void setInputSize(size_t inputs)
        {
            this->inputSize=inputs;
        }
        void addLayer(size_t perceptronsCount)
        {
            if(networkUnits.size()==0)
                networkUnits.push_back(new Layer<T>(this->inputSize,perceptronsCount,this->learningRate));
            else
            {
                networkUnits.push_back(new Layer<T>(networkUnits.back()->getOutputSize(),perceptronsCount,this->learningRate));
            }

        }
        void addActivationFunction(std::string name)
        {
            if(name=="sigmoid")
                networkUnits.push_back(new Sigmoid<T>(networkUnits.back()->getOutputSize()));
            else
                throw std::invalid_argument("Activation Function Not Found");
        }
        void setLossFunction(std::string name)
        {
            if(name=="l2")
                this->lossFunction = new L2Loss<T>();
            else if(name=="crossentropy")
                this->lossFunction = new CrossEntropy<T>();
            else
                throw std::invalid_argument("Loss Function Not Found");
        }
        // Functional Functions
        void train(std::vector<std::vector<T>> inputs,std::vector<std::vector<T>> outputs,size_t epochs)
        {
            T initialLoss=0;
            T finalLoss=0;
            for(size_t i=0;i<epochs;i++)
            {
                for(size_t j=0;j<inputs.size();j++)
                {
                    std::vector<T> result=forwardPropagate(inputs[j]);
                    if(i==0)
                        initialLoss=this->lossFunction->calculateLoss(result,outputs[j])[0];
                    if(i==epochs-1)
                        finalLoss=this->lossFunction->calculateLoss(result,outputs[j])[0];
                    std::vector<T> gradient=this->lossFunction->calculateGradient(result,outputs[j]);
                    this->backwardPropagate(gradient);
                }
            }
            std::cout<<"Initial Loss: "<<initialLoss<<std::endl;
            std::cout<<"Final Loss: "<<finalLoss<<std::endl;
        }
        std::vector<T> infer(std::vector<T> inputs)
        {
            return forwardPropagate(inputs);
        }
};

#endif