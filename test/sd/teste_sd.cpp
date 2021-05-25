/* 
//#pragma message "achou"
#include <Arduino.h>

#define DEBUG
#include "debug.h"

#include <SDFunc.h>
#include "teste_sd.h"

File dataFile;
File dataAudio;
String ret;
char bufferBtwFiles[10];

void setup()
{
    pinMode(2, OUTPUT);

    Serial.begin(115200);
    while (!Serial)
        ;
    delay(500);

    //previne loop de restarts 
    DBG_WAIT_START

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

    //deleteFile(SD, "/teste.txt");
    //writeFile(SD, "/hello.wav", "Hello ");

    
    
    dataFile = SD.open("/base64.txt");
    dataAudio = SD.open("/hello.wav");
}

void loop()
{   
    ret = readFileStep(SD, "/hello.wav", 3);
    dataAudio.printf(ret.c_str());
    Serial.println(ret.c_str());

    if(ret == "")
    {
        Serial.println("fim");
        dataAudio.close();
        esp_restart();
    }
    delay(100);
 
    // readFileStep();
    // esp_restart();

}

 */