#include "Burn.hpp"
#include "timer.h"

using namespace burn;
//******************************************************************
Burn::Burn()
{

}


//******************************************************************

void Burn::get_PWM(int8_t intensity)
{
    _intensity = map(intensity, 0, 100, 0, 255);
    Serial.print("Duty Cycle: ");
    Serial.println(_intensity);
}

//******************************************************************

int Burn::Go(int8_t intensity, int8_t duration)
{
    Serial.print("Começou: ");

    get_PWM(intensity);

    if(_temp1s != TEMP_1S)
    {
        _timer++;
        Serial.print("Contador de tempo: ");
        Serial.println(_timer);
    }

    if(_timer < duration)
    {
        analogWrite(_intensity, Pin_PWM);
        return 1;
    }else{
        return 0;
    }



}
