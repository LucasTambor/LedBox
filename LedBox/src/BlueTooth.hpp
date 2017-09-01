#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

#include <Arduino.h>
#include <SoftwareSerial.h>


namespace bluetooth
{
    class BlueTooth
    {
    public:

        BlueTooth(long Baudrate, int8_t Rx, int8_t Tx);

        int receive(int8_t *command, unsigned char *intensity, unsigned char *duration);

        void send(char Texto);
    private:
        SoftwareSerial Serial1;
    };


}
#endif
