#define NATIVE
#define DBG

#include <stdint.h>
#include <stdio.h>

#include "project_defines.h"
#include "arduino_native.h"
#include <debug.h>
#include "test_native.h"
#include <manage_files.h>
#include "strings_teste.h"

#define TESTE teste_string1


uint8_t task = 0;


int main()
{   
    int i = 0;

    while(TESTE[i] != 0x00)
    {
        processData(TESTE[i]);
        delay(500);

        i++;
    }
    return 0;
}
