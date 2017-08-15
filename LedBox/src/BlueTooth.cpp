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


int BlueTooth::receive(int8_t *command, int8_t *intensity, int8_t *duration)
{
    if(Serial1.available())
	{
	    *command = Serial1.read();
        while (!Serial1.available());
  		*intensity = Serial1.read();
        while (!Serial1.available());
  		*duration = Serial1.read();
      //Serial.write(*velocity);
      return 1;

	}
  return 0;
}
