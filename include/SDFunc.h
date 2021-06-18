#include "sd.h"
File myFile;
char fileName[] = "/hello.wav";

void openFileR()
{
    
    myFile = SD.open(fileName, FILE_READ);
    if(myFile)
    {
        DBG_PRINTS("leitura do arquivo\n");
    }
    //digitalWrite(2, true);
}

void openFileW()
{
    myFile = SD.open(fileName, FILE_WRITE);
    if(myFile)
    {
        DBG_PRINTS("inicio do arquivo\n");
        digitalWrite(2, true);
    }
}

void writeOnFile(char *myData)
{
    myFile.print(myData);
    /* Serial.printf("\nmem %u\n", myData);
    Serial.printf("\nval %u\n", *myData);
    Serial.printf("\nmem+1 %lu\n", myData+1);
    Serial.printf("\nval %u\n", *myData+1); */
}

void closeFile()
{
    myFile.close();
    digitalWrite(2, false);
    DBG_PRINTS("fim do arquivo\n");
}

void readFile()
{
    Serial.printf("Reading file \n");

    myFile = SD.open(fileName, FILE_READ);
    if (!myFile)
    {
        Serial.println("Failed to open file for reading");
        return;
    }

    Serial.print("Read from file: ");
    while (myFile.available())
    {
        Serial.write(myFile.read());
    }
    myFile.close();
}