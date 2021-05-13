#include "sd.h"

#define CMD_ESCAPE 0x12 //ctrl + a
#define CMD_START 0x02  //ctrl + b
#define CMD_END 0x04    //ctrl + d

#define DEBUG_PRINT(x)  teste(x)

#define TAM_ESCAPE 4
const char escape[TAM_ESCAPE] = {0x12, 0xAA, 0xAA, 0xAA};
char bufferTmp[TAM_ESCAPE] = {0,0,0,0};

char nameFile[] = "/hello.wav"

char receivedChar;
boolean newData = false;

static File myFile;

void recvOneChar(char bufChar)
{
    receivedChar = bufChar;
    newData = true;   
    DB_PRINTCH(receivedChar);
}

void openFileByName(char * name)
{
    DB_PRINTS("inicio do arquivo");
    digitalWrite(2, true);
    myFile = SD.open(name, FILE_WRITE);
}

void closeFile()
{
    DB_PRINTS("fim do arquivo");
    digitalWrite(2, false);
    myFile.close();
}
 
boolean header(int count)
{
    if (receivedChar == escape[count])
    {
        bufferTmp[count] = receivedChar;
        DB_PRINTS("CORRETO");
        return true;
    }
    return false;
}

void processData()
{
    static boolean b_escapeCorrect = 0;
    static int counterCompare = 0;
    
    if (newData == true)
    {
        //headerFound = header();
  
        if (header(counterCompare)) {

            counterCompare++;
            if (counterCompare == TAM_ESCAPE) {
                b_escapeCorrect = true;     
                DB_PRINTS("header encontrado");
            }    
        }

        else if (b_escapeCorrect) {
            switch (receivedChar)
            {
            case CMD_START:
                openFileByName(nameFile);
                break;
            case CMD_END:
                closeFile();
                break;
            }

            counterCompare = 0;
            b_escapeCorrect= false;
        }

        else if (myFile)
        {
            myFile.print(bufferTmp);
        }

        memset(bufferTmp, 0, sizeof(bufferTmp));
    }
} 




