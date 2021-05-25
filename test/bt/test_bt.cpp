
#include <Arduino.h>
#define DEBUG

#include "debug.h"

#include "BluetoothSerial.h"


#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

char tm = 0;

void setup()
{
    pinMode(2, OUTPUT);
    
    Serial.begin(115200);     
        ;

    //DBG_WAIT_START
    
    SerialBT.begin("esp32apk"); //Bluetooth device name
    Serial.println("The device started, now you can pair it with bluetooth!");

    tm = 0;

}

int inteiro = 0;
void loop()
{

    if (SerialBT.available())
    {
        tm = (char)SerialBT.read();
        /* if (isPrintable(tm))
        {
            DBG_PRINTCH(tm);
        }
        else
        {
            DBG_PRINTX(tm);
        } */
    } 
}