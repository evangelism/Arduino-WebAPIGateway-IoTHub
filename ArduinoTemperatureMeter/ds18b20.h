// Simple library for BS18B20 temp sensor

#include <OneWire.h>

OneWire ds(DS_PIN);

byte ds_data[12];
byte ds_addr[8];
bool ds_ok=false;

void ds_init()
{
    ds_ok = ds.search(ds_addr);
}

float ds_temp()
{
    ds.reset();
    ds.select(ds_addr);
    ds.write(0x44,1);
    delay(1000);
    ds.reset();
    ds.select(ds_addr);
    ds.write(0xBE);
    for (int i=0;i<9;i++) ds_data[i]=ds.read();
    int16_t raw = (ds_data[1] << 8) | ds_data[0];
    byte cfg = (ds_data[4] & 0x60);
    if (cfg == 0x00) raw = raw & ~7;  // 9 bit resolution, 93.75 ms
    else if (cfg == 0x20) raw = raw & ~3; // 10 bit res, 187.5 ms
    else if (cfg == 0x40) raw = raw & ~1; // 11 bit res, 375 ms
    return (float)raw / 16.0;
}

