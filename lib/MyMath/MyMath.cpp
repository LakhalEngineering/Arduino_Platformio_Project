#include "MyMath.h"

float CalcY_2(float x, float x1, float x2, float y1, float y2)
{
    float A, B, C;
    float output;

    A = y2 - y1;
    B = x - x1;
    C = x2 - x1;
    if(C == 0) C = 1;
    return output = ((A * B) / C) + y1;
    
}

float CalcY_3(float x, float x1, float x2, float x3, float y1, float y2, float y3)
{
    if(x < x2)
        return CalcY_2(x, x1, x2, y1, y2);
    else
        return CalcY_2(x, x2, x3, y2, y3);
}