#define DBG
#include <Arduino.h>
#include "project_defines.h"

extern "C"
{
#include "crypto/base64.h"
}

#include <debug.h>

void maisoumenos()
{
    static char inteiro = 0;

    if ((inteiro > 0x20) && (inteiro < 0x7E))
    {
        Serial.printf("%c ", inteiro);
    }
    else
    {
        Serial.printf(".");
    }
    inteiro++;
}

void binario()
{
    static char inteiro = 0;

    if (inteiro & 0x60)
    {
        Serial.printf("%c ", inteiro);
    }
    else
    {
        Serial.printf(".");
    }
    inteiro++;
}

void testeStackOverflow()
{
    static uint8_t index1 = 12;
    static uint8_t index0 = 1;
    static uint8_t index2 = 5;

    index0++;
    if (index0 > 255)
    {
        printf("entrou\n");
        index0 = 0;
    }
    Serial.printf("end: %lu, val: %u, ", (&index0), index0);
    Serial.printf("end: %lu, val: %u, ", (&index0 + 1), *(&index0 + 1));
    Serial.printf("end: %lu, val: %u, ", (&index0 - 1), *(&index0 - 1));
    // Serial.printf("end: %lu, val: %u, ", (&index1), *(&index1));
    // Serial.printf("end: %lu, val: %u, ", (&index2), *(&index2));
    Serial.printf("\n");
}

void setup()
{
    Serial.begin(BAUD);
    while (!Serial)
        ;

    DBG_WAIT_START();

    char *toEncode = "Hello World";
    size_t outputLength;

    unsigned char *encoded = base64_encode((const unsigned char *)toEncode, strlen(toEncode), &outputLength);

    Serial.print("Length of encoded message: ");
    Serial.println(outputLength);

    Serial.printf("%.*s", outputLength, encoded);
    free(encoded);
}

int i = 0;
int tempo, tempo_old;
void loop()
{
    esp_restart();
}

SGVsbG8gV29ybGQ=