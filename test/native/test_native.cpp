#define NATIVE
#define DEBUG

#include "arduino_native.h"
#include <debug.h>
#include "test_native.h"
#include <manage_files.h>

int x = 0;
int teste_string[] = {0x12, 0x12, 0x44,
0x12, 0x12, 0x12, 0x12, 0x02,
0x12, 0x12, 0x43, 0x44, 0x45, 0x46, 0x47, 0x48, 0x49,  //A, B, C, E, F, G, H, I
0x12, 0x12, 0x12, 0x12, 0x04};


char test[] = "abcde";

int main()
{   
    char p[12] = "hello world";
    printf("inicio\n");
    
    /* for (x = 0; x < sizeof(teste_string)/4; x++)
    {
        processData((char)teste_string[x]);
        getchar();
        // delay(100);
    }
     */
    printf("main: %u, m: %u", test, &test);
    writeOnFile(test);
    //testeBuf(p);
    //printf("%s", p);
    return 0;
}
