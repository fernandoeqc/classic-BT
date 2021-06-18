#include "sd.h"
File myFile;

void openFileR(char *name)
{
    
    myFile = SD.open("/teste.txt", FILE_READ);
    if(myFile)
    {
        DBG_PRINTS("leitura do arquivo\n");
    }
    //digitalWrite(2, true);
}

void openFileW(char *name)
{
    myFile = SD.open("/teste.txt", FILE_WRITE);
    if(myFile)
    {
        DBG_PRINTS("inicio do arquivo\n");
        digitalWrite(2, true);
    }
}

void writeOnFile(char *myData)
{
    // myFile.print(myData);
    Serial.printf("\nmem %u\n", myData);
    Serial.printf("\nval %u\n", *myData);
    Serial.printf("\nmem+1 %lu\n", myData+1);
    Serial.printf("\nval %u\n", *myData+1);
}

void closeFile()
{
    myFile.close();
    digitalWrite(2, false);
    DBG_PRINTS("fim do arquivo\n");
}
