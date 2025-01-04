#ifndef NetworkUnit_h
#define NetworkUnit_h
class NetworkUnit
{
    public:
        virtual void forwardPropagate()=0;
        virtual void backwardPropagate()=0;
};
#endif