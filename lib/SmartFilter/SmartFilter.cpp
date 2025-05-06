#include "SmartFilter.h"

SmartFilter::SmartFilter(int queueLen)
    : QueueLen(queueLen), smEMPTY(false), smACQUIRING(false), smFULL(false),
      CurrIndex(0), MaxQueueLen(32), Sum(0), Output(0), Input(0), Min(0), Max(0) {
    reset();
}

void SmartFilter::reset() {
    smEMPTY = false;
    smACQUIRING = false;
    smFULL = false;
    CurrIndex = 0;
    Sum = 0;
    Min = 0;
    Max = 0;
}

void SmartFilter::setInput(float input) {
    Input = input;

    if (!smEMPTY && !smACQUIRING && !smFULL) {
        if (QueueLen <= 0) QueueLen = 4;
        if (QueueLen > MaxQueueLen) QueueLen = MaxQueueLen;

        CurrIndex = 0;
        DataQueue[CurrIndex++] = Input;
        smACQUIRING = true;
        Output = Input;
        Min = Max = Input;
        return;
    }

    if (smACQUIRING) {
        if (QueueLen <= 0) QueueLen = 4;
        if (QueueLen > MaxQueueLen) QueueLen = MaxQueueLen;

        if (CurrIndex < QueueLen) {
            DataQueue[CurrIndex++] = Input;
            Output = Input;
            Min =  999999;
            Max = -999999;
            for (int i = 0; i < CurrIndex; i++) {
                if (DataQueue[i] < Min) Min = DataQueue[i];
                if (DataQueue[i] > Max) Max = DataQueue[i];
            }
            return;
        } else {
            smACQUIRING = false;
            smFULL = true;
        }
    }

    if (smFULL) {
        if (QueueLen <= 0) QueueLen = 4;
        if (QueueLen > MaxQueueLen) QueueLen = MaxQueueLen;

        for (int i = 0; i < QueueLen - 1; i++)
            DataQueue[i] = DataQueue[i + 1];
        DataQueue[QueueLen - 1] = Input;

        Sum = 0;
        Min =  999999;
        Max = -999999;
        for (int i = 0; i < QueueLen; i++) {
            if (DataQueue[i] < Min) Min = DataQueue[i];
            if (DataQueue[i] > Max) Max = DataQueue[i];
            Sum += DataQueue[i];
        }

        Output = (QueueLen > 0) ? Sum / QueueLen : -1;
    }
}

float SmartFilter::getOutput() {
    return Output;
}

float SmartFilter::getMin() const {
    return Min;
}

float SmartFilter::getMax() const {
    return Max;
}