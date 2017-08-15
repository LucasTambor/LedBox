#ifndef BURN_H
#define BURN_H

#include <inttypes.h>
#include <Arduino.h>

#define Pin_PWM  5
#define Pin_Led 16


namespace burn
{
    class Burn
    {
    private:
        int8_t _intensity;
        int32_t _timer;
        bool _temp1s = false ;

        void get_PWM(int8_t intensity);

    public:
        Burn();
        int Go(int8_t intensity, int8_t duration);
    };


}

#endif
