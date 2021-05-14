#include "sd.h"

static File myFile;

void openFileByName(char *name)
{
    DB_PRINTS("inicio do arquivo");
    digitalWrite(2, true);
    myFile = SD.open(name, FILE_WRITE);
}

void writeStrFile(char *tmp)
{
    myFile.print(tmp);
}

void closeFile()
{
    DB_PRINTS("fim do arquivo");
    digitalWrite(2, false);
    myFile.close();
}

