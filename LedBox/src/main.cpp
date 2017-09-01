
#include <inttypes.h>


#include "BlueTooth.hpp"
#include "Burn.hpp"

using namespace bluetooth;
using namespace burn;

#define Pin_PWM  5
#define Pin_Led 12
#define Pin_Tampa 11

#define Rx_Pin  8
#define Tx_Pin  7


int8_t command = 0;
unsigned char intensity = 0;
unsigned char duration = 0;
int8_t i = 0;

int8_t ST_Burn = 0;

char Aviso_Tampa[] = "Tampa Aberta";
char Aviso_Inicio[] = "Taca-lhe Pau";

BlueTooth BT(9600, Rx_Pin,Tx_Pin);
Burn Queima;


//*****************************************************************************

void setup()
{
    Serial.begin(9600);

    pinMode(Pin_PWM, OUTPUT);
    pinMode(Pin_Led, OUTPUT);
    pinMode(Pin_Tampa, INPUT_PULLUP);
    digitalWrite(Pin_PWM, LOW);
    for(int i = 0; i<12; i++ )
    {
        BT.send(Aviso_Tampa[i]);

    }
    Serial.println(Aviso_Tampa);

}

//*****************************************************************************

void loop()
{
    if(BT.receive(&command, &intensity, &duration))
    {
        // Serial.print("Comando: ");
        // Serial.println(command);
        // Serial.print("Intensidade: ");
        // Serial.println(intensity);
        // Serial.print("Duração: ");
        // Serial.println(duration);

        if(command == 1)
        {
            if(!digitalRead(Pin_Tampa))//Porta fechada
            {
                Serial.println("Porta fechada");
                ST_Burn = 1;
                Serial.println("ST_BURN = 1");

                for(int i = 0; i<12; i++ )
                {
                    BT.send(Aviso_Inicio[i]);

                }

            }else{
                Serial.println("Porta Aberta");

                for(int i = 0; i<12; i++ )
                {
                    BT.send(Aviso_Tampa[i]);

                }
            }
        }

        if(command == 2)//cancelar
        {
            ST_Burn = 0;
            Queima.Cancel();
            Serial.println("ST_BURN = 0");

        }

        if(command == 0)//Pausar
        {
            ST_Burn = 0;
            Queima.Stop();
        }

        if(command == 3) //Slider
        {
            Serial.println("SLIDER");
            ST_Burn = 0;
            Queima.Slider(intensity, duration);
        }
    }

    //Começa procedimento de queimar as parada
    if(ST_Burn == 1)
    {
        if(!Queima.Go(intensity, duration, &ST_Burn))
        {
            Serial.print("Sucesso!");
        }

    }

    if(digitalRead(Pin_Tampa))
    {
        ST_Burn = 0;

        Queima.Stop();

    }




}
