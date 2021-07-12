#define DBG
#include <Arduino.h>
#include "project_defines.h"
extern "C"
{
    #include "crypto/base64.h"
}


#include <dbg.h>
#include <project_defines.h>

#include <SDFunc.h>
#include <teste_sd.h>
#include <tasks.h>
#include <manage_files.h>




void setup()
{
    Serial.begin(BAUD);
    while (!Serial)
        ;

    DBG_WAIT_START();

    initSD();



    Serial.println("Fim do setup.");
}

int i = 0;
int tempo, tempo_old;
void loop()
{
    
/*     while(encoded[i] != 0)
    {
        Serial.println(encoded[i]);
    }
    esp_restart();
 */

    // encode();
    decode();

    esp_restart();

}

// SGVsbG8gV29ybGQ=

