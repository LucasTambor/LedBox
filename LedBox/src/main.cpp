
#include <inttypes.h>


#include "BlueTooth.hpp"
#include "Burn.hpp"

using namespace bluetooth;
using namespace burn;

#define Pin_PWM  5
#define Pin_Led 16

#define Rx_Pin  7
#define Tx_Pin  8

// SoftwareSerial Serial1(7,8); //Rx, Tx



int8_t command = 0;
int8_t intensity = 0;
int8_t duration = 0;
int8_t i = 0;

BlueTooth BT(9600, Rx_Pin,Tx_Pin);
Burn Queima;


//*****************************************************************************

void setup()
{
    Serial.begin(9600);

    pinMode(Pin_PWM, OUTPUT);
    pinMode(Pin_Led, OUTPUT);



}

//*****************************************************************************

void loop()
{
    if(BT.receive(&command, &intensity, &duration))
    {
        Serial.print("Comando: ");
        Serial.println(command);
        Serial.print("Intensidade: ");
        Serial.println(intensity);
        Serial.print("Duração: ");
        Serial.println(duration);

        if(!Queima.Go(command, duration))
        {
            Serial.print("Sucesso!");
        }
    }



}
