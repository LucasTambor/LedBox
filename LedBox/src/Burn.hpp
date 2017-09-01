#ifndef BURN_H
#define BURN_H

#include <inttypes.h>
#include <Arduino.h>

#define Pin_PWM  5
#define Pin_Led 12


namespace burn
{
    class Burn
    {
    private:
        unsigned char _intensity;
        int32_t _timer;
        bool time_aux_burn = false ;


        void get_PWM(unsigned char intensity);

    public:
        Burn();
        int Go(unsigned char intensity, unsigned char duration, int8_t *ST_Burn );
        void Stop(void);
        void Cancel(void);
        void Slider(unsigned char intensity, unsigned char duration );
    };


}

#endif//BURN_H
