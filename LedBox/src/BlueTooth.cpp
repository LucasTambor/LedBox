#include "BlueTooth.hpp"
#include <SoftwareSerial.h>

//*************************************************************************
using namespace bluetooth;

BlueTooth::BlueTooth(long Baudrate, int8_t Rx, int8_t Tx):
Serial1(Rx, Tx)
{
    Serial1.begin(Baudrate);

}


//*************************************************************************


int BlueTooth::receive(int8_t *command, unsigned char *intensity, unsigned char *duration)
{
    if(Serial1.available())
	{
	    *command = Serial1.read();
        while (!Serial1.available());
  		*intensity = Serial1.read();
        while (!Serial1.available());
  		*duration = Serial1.read();
    //   Serial.write(*velocity);
      return 1;

	}
  return 0;
}

void BlueTooth::send(char Texto)
{
    Serial1.write(Texto);
}
