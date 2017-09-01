#include "Burn.hpp"
#include "timer.h"

using namespace burn;
//******************************************************************
Burn::Burn()
{

}


//******************************************************************

void Burn::get_PWM(unsigned char intensity)
{
    Serial.println(intensity);
    _intensity = map(intensity, 0, 100, 0, 255);
    Serial.print("Duty Cycle: ");
    Serial.println(_intensity);
}

//******************************************************************

int Burn::Go(unsigned char intensity, unsigned char duration,int8_t *ST_Burn)
{
    timer();
    Serial.println("Começou: ");

    get_PWM(intensity);

    if(*ST_Burn)
    {

        if(TEMP_1S != time_aux_burn)
        {
            _timer++;
            Serial.println("contador de segundos:");
            Serial.println(_timer);
            time_aux_burn = TEMP_1S;
        }

        if(_timer > duration)
        {

            Serial.println("Tempo esgotado!");
            *ST_Burn = 0;
            _timer = 0;
            Cancel();


            return 0;
        }





        analogWrite(Pin_PWM, _intensity);
        digitalWrite(Pin_Led, HIGH);
        return 1;
    }


}



void Burn::Cancel(void)
{
    _timer = 0;
    analogWrite(Pin_PWM, 0);
    digitalWrite(Pin_Led, LOW);
}

void Burn::Stop(void)
{
    analogWrite(Pin_PWM, 0);
    digitalWrite(Pin_Led, LOW);

}

void Burn::Slider(unsigned char intensity, unsigned char duration )
{
    if(duration)
    {
        get_PWM(intensity);
        analogWrite(Pin_PWM, _intensity);
        digitalWrite(Pin_Led, HIGH);

    }else{
        digitalWrite(Pin_PWM, LOW);
        digitalWrite(Pin_Led, LOW);
    }

}
