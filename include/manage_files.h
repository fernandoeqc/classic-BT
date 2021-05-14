
#ifndef NATIVE
#include <SDFunc.h>
#endif


#define CMD_START 0x02  //ctrl + b
#define CMD_END 0x04    //ctrl + d
#define TAM_ESCAPE 4
const char escape[TAM_ESCAPE] = {0x12, 0x12, 0x12, 0x12}; //ctrl + r
char bufferTmp[TAM_ESCAPE] = {0, 0, 0, 0};


char receivedChar;
boolean newData = false;

char nameFile[] = "/hello.wav";

void recvOneChar(char bufChar)
{
    receivedChar = bufChar;
    newData = true;

    if (isPrintable(receivedChar))
    {
        DB_PRINT(receivedChar);
    }
    else
    {
        DB_PRINTX(receivedChar);
    }
}


boolean header(int count)
{
    if (receivedChar == escape[count])
    {
        DB_PRINTS("cont");
        DB_PRINT(count);
        bufferTmp[count] = receivedChar;

        return true;
    }
    else
    {
        memset(bufferTmp, 0, sizeof(bufferTmp));
        bufferTmp[0] = receivedChar; 
    }

    DB_PRINTS("bufferTmp:");
    DB_PRINTS(bufferTmp);
    return false;
}


void processData()
{
    static boolean b_escapeCorrect = 0;
    static boolean file_open = false;
    static int counterCompare = 0;

    if (newData == true)
    {
        newData = false;

        if (header(counterCompare))
        {
            counterCompare++;
            if (counterCompare == TAM_ESCAPE)
            {
                b_escapeCorrect = true;
                DB_PRINTS("header encontrado");
            }
        }

        else if (b_escapeCorrect)
        {
            switch (receivedChar)
            {
            case CMD_START:
                openFileByName(nameFile);
                file_open = true;
                break;
            case CMD_END:
                closeFile();
                file_open = false;
                break;
            }

            counterCompare = 0;
            b_escapeCorrect = false;
        }

        else if (file_open)
        {
            printf("ESCREVE:\n");
            writeStrFile(bufferTmp);
        }
    
        memset(bufferTmp, 0, sizeof(bufferTmp));
    }
}
