
#include "Arduino.h"
#define DBG

#include "dbg.h"
#include "project_defines.h"

#include "SDFunc.h"
#include "BTFunc.h"
#include "manage_files.h"


#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

char x = 0;

void setup()
{
    pinMode(2, OUTPUT);
    
    Serial.begin(BAUD);
        while (!Serial)
        ;
    DBG_WAIT_START();
    
    SerialBT.begin("ESP32test"); //Bluetooth device name
    Serial.println("The device started, now you can pair it with bluetooth!");

    initSD();
}


void loop()
{
    if (SerialBT.available())
    {
        processData((char)SerialBT.read());
    }

    if(Serial.available())
    {
        if(Serial.read() == 'a')
        {
            readFile(SD, "/hello.wav");
        }
    }
}
