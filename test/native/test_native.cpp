#include <stdio.h>
#include <stdlib.h>

#include "test_native.h"

char str[] = "hello";

void openFileByName(char * name)
{
    //DB_PRINTS("inicio do arquivo");
    digitalWrite(2, true);
   
    printf("%s", name);
    //myFile = SD.open(name, FILE_WRITE);

}


int main()
{
    openFileByName(str);


    printf("fim\n");
    getchar();
    return 0;
}