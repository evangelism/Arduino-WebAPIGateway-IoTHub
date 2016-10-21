
#define DS_PIN 7
#include "ds18b20.h"


void setup() 
{
    ds_init();
    Serial.begin(9600);
}

void loop() 
{
   float x = ds_temp();
   Serial.print(x);
   delay(1000);
}


