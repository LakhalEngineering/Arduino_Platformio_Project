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

float CalcY_4(float x, float x1, float x2, float x3, float x4, float y1, float y2, float y3, float y4)
{
    if(x < x2)
        return CalcY_2(x, x1, x2, y1, y2);
    else 
    if(x >= x2 && x < x3)
        return CalcY_2(x, x2, x3, y2, y3);
    else
    if(x >= x3)
        return CalcY_2(x, x3, x4, y3, y4);
    else
        return 0;
        
}

float Grad2Rad(float grad_in)
{
    return (grad_in * 3.14159)/180.0;
}

float Rad2Grad(float rad_in)
{
    return (rad_in * 180.0)/3.14189;
}