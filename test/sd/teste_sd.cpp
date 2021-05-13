
//#pragma message "achou"
#include <Arduino.h>

#define DEBUG
#include "main.h"

#include "teste_sd.h"

void setup()
{
    Serial.begin(115200);
    while (!Serial)
        ;
    delay(500);

    //previne loop de restarts 
    DB_WAIT_START

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

    deleteFile(SD, "/teste.txt");
    writeFile(SD, "/teste.txt", "Teste ");
}

void loop()
{
    //todo
    
    writeBlankStr();
    
    Serial.println("fim");
    while(1);
}
