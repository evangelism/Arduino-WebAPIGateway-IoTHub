
#define DS_PIN 7
#include "ds18b20.h"
#include "ethernet.h"


void setup() 
{
    Serial.begin(9600);
    ds_init();
    eth_init();
}

void loop() 
{
   float x = ds_temp();
   Serial.println(x);
   int y = get("www.google.com","/");
   Serial.println(y);
   delay(1000);
}


