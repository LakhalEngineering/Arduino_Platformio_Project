#include "tOn_tOff.h"

bool tOn_tOff(double Period_Off_ms,double Period_On_ms,double Base_Tempi_ms)
{
    double Get_Counter_ON_ms, Get_Counter_OFF_ms = 0;
    bool Output = false;
    if(Period_Off_ms == 0)
    { 
        Output = true;
    }
    else if(Period_On_ms == 0)
    { 
        Output = false;
    }
    else if (Base_Tempi_ms <= (Get_Counter_ON_ms + Period_Off_ms))
    {
        // Spengo uscita
        Get_Counter_OFF_ms = Base_Tempi_ms;
        Output = false;
    }
    else if (Base_Tempi_ms < (Get_Counter_OFF_ms + Period_On_ms))
    {
        // Accendo uscita
        Output = true;
    }    
    else
    { 
        Get_Counter_ON_ms = Base_Tempi_ms;
    }
    
    return Output;
}


