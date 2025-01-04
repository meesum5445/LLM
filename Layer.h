#ifndef Layer_h
#define Layer_h
//........................
#include<vector>
//........................
template<typename T>
class Layer
{
    private:
        std::vector<std::vector<T>>weights;
    public:
        Layer(uint_t inputs,uint_t perceptronsCount)
        {
            weights.resize(perceptronsCount, std::vector<T>(inputs));
        }
        std::vector<T> forwardPropagate(std::vector<T> inputs)
        {
            std::vector<T> outputs(weights.size());
            for(uint_t i=0;i<weights.size();i++)
            {
                T sum=0;
                for(uint_t j=0;j<weights[i].size();j++)
                {
                    sum+=weights[i][j]*inputs[j];
                }
                outputs[i]=sum;
            }
            return outputs;
        }
        void backwardPropagate(std::vector<T> gradients)
        {
            for(uint_t i=0;i<weights.size();i++)
            {
                for(uint_t j=0;j<weights[i].size();j++)
                {
                    weights[i][j]-=gradients[i];
                }
            }
        }
};

//........................
#endif