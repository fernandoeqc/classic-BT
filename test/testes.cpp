
//#pragma message "achou"
#include <Arduino.h>

#define DEBUG
#include "main.h"

#include <testes.h>

void setup()
{
    Serial.begin(115200);
    while (!Serial)
        ;
    delay(500);

    //previne loop de restarts 
    DB_WAIT_START
}

void loop()
{
    //debugPrints();
    clearString();
    
    //verificar qual o tamanho da string depois de apagar
    
    
    
    Serial.println("fim");
    while(1);
}
