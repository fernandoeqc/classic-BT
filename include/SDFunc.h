//#include "sd.h"
#include <SdFat.h>

static SdFat sd;
static SdFile myFile;

const int chipSelect = 5;

/* void openFileByName(char *name)
{
    DBG_PRINTS("inicio do arquivo");
    digitalWrite(2, true);
    myFile = SD.open(name, FILE_WRITE);
}

void writeStrFile(char *tmp)
{
    myFile.print(tmp);
}

void closeFile()
{
    DBG_PRINTS("fim do arquivo");
    digitalWrite(2, false);
    myFile.close();
}
 */

void initSd()
{
    if (!sd.begin(chipSelect, SPI_DIV3_SPEED))
        sd.initErrorHalt();
}


void removeFile(char *name)
{
    sd.remove(name);
}


void openFileR(char *name)
{
    DBG_PRINTS("inicio do arquivo");
    digitalWrite(2, true);
    if (!myFile.open(name, O_READ))
    {
        sd.errorHalt("opening test.txt for read failed");
    }
}


void openFileW(char *name)
{
    if (!myFile.open(name, O_RDWR | O_CREAT | O_AT_END))
    {
        sd.errorHalt("opening test.txt for write failed");
    }
    DBG_PRINTS("inicio do arquivo");
    digitalWrite(2, true);
}


void writeOnFile(char *myData, int count)
{
    // myFile.write(myData, sizeof(myData));
    myFile.write(myData, count);
    // printf("sizefunc: %u \n", sizeof(* myData));
}


void readFile()
{
    int data;
    while ((data = myFile.read()) >= 0)
    {
        Serial.println(data);
    }
}

void closeFile()
{
    myFile.close();
    digitalWrite(2, false);
    DBG_PRINTS("fim do arquivo");
}
