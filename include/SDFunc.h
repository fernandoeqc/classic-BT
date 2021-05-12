#include "sd.h"

#define CMD_ESCAPE 0x12 //ctrl + a
#define CMD_START 0x02  //ctrl + b
#define CMD_END 0x04    //ctrl + d

#define DEBUG_PRINT(x)  teste(x)

char receivedChar;
boolean newData = false;
void recvOneChar(char bufChar)
{
    receivedChar = bufChar;
    newData = true;   
}

void teste(char  * x) {
    Serial.println(x);
}

void cmdController()
{
    static boolean escapuliu = false;
    static File myFile;

    if (escapuliu)
    {
        escapuliu = false;

        switch (receivedChar)
        {
        case CMD_START:

            PRINTS("inicio do arquivo");
            digitalWrite(2, true);
            myFile = SD.open("/hello.wav", FILE_WRITE);
            break;
        case CMD_END:
            PRINTS("fim do arquivo");
            digitalWrite(2, false);
            myFile.close();
            break;
        }
    }

    else if (receivedChar == CMD_ESCAPE)
    {
        escapuliu = true;
        PRINTS("Escapuliu");
    }

    else if (myFile)
    {
        myFile.print(receivedChar);
    }
}

void showNewData()
{
    if (newData == true)
    {
        cmdController();

        //Serial.print(receivedChar);

        /* if (!isPrintable(receivedChar))
        {
            Serial.print("0x");
            Serial.print(receivedChar, HEX);
        } */

        newData = false;
    }
}
