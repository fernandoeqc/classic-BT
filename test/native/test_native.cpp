#define NATIVE
//#define DEBUG

#include "arduino_native.h"
#include <debug.h>
#include "test_native.h"
#include <manage_files.h>



int x = 0;
char teste_string[] = {0x12, 0x12, 0x12, 0x12, 0x02,
0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49,  //A, B, C, E, F, G, H, I
0x12, 0x12, 0x12, 0x12, 0x04};

int main()
{
    
    for (x = 0; x < sizeof(teste_string); x++)
    {
        recvOneChar(teste_string[x]);
        
        processData();

        getchar();
        delay(100);
    }
    
    return 0;
}
