

unsigned long old_time = 0;
bool TEMP_1S = false;

//*************************************************************************

bool timer()
{
    if(millis() > old_time + 1000)
    {
        TEMP_1S = !TEMP_1S;
        old_time = millis();
        // Serial.print("TEMP_1S: ");
        // Serial.println(TEMP_1S);
    }
    return TEMP_1S;
}
