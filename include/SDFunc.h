#include "sd.h"
File myFileR;
File myFileW;
// char fileName[] = "/hello.wav";

void openFileR(const char * fileName)
{
    
    myFileR = SD.open(fileName, FILE_READ);
    if(myFileR)
    {
        DBG_PRINTS("leitura do arquivo\n");
    }
    //digitalWrite(2, true);
}

void openFileW(const char *fileName)
{
    myFileW = SD.open(fileName, FILE_WRITE);
    if(myFileW)
    {
        DBG_PRINTS("inicio do arquivo\n");
        
    }
}

void writeOnFile(char *myData)
{
    myFileW.print(myData);
    /* Serial.printf("\nmem %u\n", myData);
    Serial.printf("\nval %u\n", *myData);
    Serial.printf("\nmem+1 %lu\n", myData+1);
    Serial.printf("\nval %u\n", *myData+1); */
}

void closeFile()
{
    
    
    DBG_PRINTS("fim do arquivo\n");
}

void readFile(const char *fileName)
{
    Serial.printf("Reading file \n");

    myFileR = SD.open(fileName, FILE_READ);
    if (!myFileR)
    {
        Serial.println("Failed to open file for reading");
        return;
    }

    Serial.print("Read from file: ");
    while (myFileR.available())
    {
        Serial.write(myFileR.read());
    }
    myFileR.close();
}