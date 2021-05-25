
#include <Arduino.h>
//#define DEBUG

#include "debug.h"

#include "BluetoothSerial.h"
#include "manage_files.h"


#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;
char x = 0;

void setup()
{
    pinMode(2, OUTPUT);
    
    Serial.begin(115200);
    while (!Serial)
        ;
    DBG_WAIT_START
    
    SerialBT.begin("esp32teste"); //Bluetooth device name
    Serial.println("The device started, now you can pair it with bluetooth!");

    if (!SD.begin())
    {
        Serial.println("Card Mount Failed");
        while (1);
    }
    
    uint8_t cardType = SD.cardType();
    if (cardType == CARD_NONE)
    {
        Serial.println("No SD card attached");
        return;
    }

    deleteFile(SD, "/hello.wav");
    writeFile(SD, "/hello.wav", "Hello ");
}


void loop()
{
    if (SerialBT.available())
    {
        processData((char)SerialBT.read());

        if(ret == 1)
        {
            SerialBT.write(0x06);
        }
    }
}
