#ifndef SMARTFILTER_H
#define SMARTFILTER_H

class SmartFilter {
public:
    SmartFilter(int queueLen = 4);

    void setInput(float input);
    float getOutput();
    float getMin() const;
    float getMax() const;

private:
    bool smEMPTY;
    bool smACQUIRING;
    bool smFULL;
    int CurrIndex;
    float DataQueue[33]; // [0..32]
    unsigned char MaxQueueLen;
    int QueueLen;
    float Sum;
    float Output;
    float Input;
    float Min;
    float Max;

    void reset();
};

#endif