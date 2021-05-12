#include <Arduino.h>

// Debugging switches and macros
#define DEBUG 1 // Switch debug output on and off by 1 or 0

#if DEBUG
    #define PRINTS(s)   { Serial.print(F(s)); }
    #define PRINT(s,v)  { Serial.print(F(s)); Serial.print(v); }
    #define PRINTX(s,v) { Serial.print(F(s)); Serial.print(F("0x")); Serial.print(v, HEX); }
#else
    #define PRINTS(s)
    #define PRINT(s,v)
    #define PRINTX(s,v)
#endif


//This example code is in the Public Domain (or CC0 licensed, at your option.)
//By Evandro Copercini - 2018
//
//This example creates a bridge between Serial and Classical Bluetooth (SPP)
//and also demonstrate that SerialBT have the same functionalities of a normal Serial

#include "BluetoothSerial.h"
#include <SDFunc.h>

//#define DEBUG_PRINT(x)  teste(x)

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;



void setup()
{
    Serial.begin(115200);
    SerialBT.begin("esp32teste"); //Bluetooth device name
    Serial.println("The device started, now you can pair it with bluetooth!");

    Serial.begin(115200);
    if (!SD.begin())
    {
        Serial.println("Card Mount Failed");
        return;
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
    if (Serial.available())
    {
        SerialBT.write(Serial.read());
    }
    /* 
  if (SerialBT.available()) {
    Serial.write(SerialBT.read());
  } */
    
    if (SerialBT.available())
    {
        recvOneChar(SerialBT.read());
    }

    showNewData();

}