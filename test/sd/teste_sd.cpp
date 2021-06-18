#define DBG

#include "project_defines.h"
#include "Arduino.h"
#include "debug.h"
#include "teste_sd.h"
#include <SDFunc.h>
#include <manage_files.h>


char namefile[] = "test.txt";

char test_buffer[] = {97, 98, 99, 100, 101, 102, 103, 104, 105, 106, '\0'};

uint8_t test[] = {1, 2, 3, 4, 5};

void setup()
{
    Serial.begin(BAUD);
    while (!Serial)
    {
    }
    DBG_WAIT_START();
    delay(400); // catch Due reset problem

    initSD();
    Serial.println("fim do setup");
}

void tempoEscrita()
{
     int tempo = 0;
    //readFile(SD, "/test.txt");
    tempo = millis();

    copypaste(SD, "/copy.txt", "/paste.txt");
    Serial.println(millis() - tempo);
} 

void loop()
{
   
    /* if(Serial.available())
    {
        processData(Serial.read());
        // Serial.print(Serial.read());
    } */

    // Serial.printf("fim\n");
    // Serial.println("\n\n\n");
    // esp_restart();

}
