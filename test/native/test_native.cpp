#define NATIVE
#define DBG

#include <stdint.h>
#include <stdio.h>
#include "arduino_native.h"

#include <dbg.h>
#include <project_defines.h>
#include "test_native.h"

#include "base64.h"
// #include <manage_files.h>
// #include "strings_teste.h"

#define TESTE teste_string1


uint8_t task = 0;


unsigned char ascii[] = "ABCDEFGHIJLMNOP";
bool end = false;
unsigned char outputLength = 0;
unsigned char *encoded;

int main()
{   
    printf("inicio\n");
    /*
    int i = 0;

    while(TESTE[i] != 0x00)
    {


        // processData(TESTE[i]);
        delay(500);

        i++;
    } */


    encoded = base64_encode(ascii, sizeof(ascii), &outputLength, end);

    printf("%s", encoded);

    printf("out_len: %u", outputLength);
    // getchar();
    return 0;
}
