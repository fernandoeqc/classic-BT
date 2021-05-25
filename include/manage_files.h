
#ifndef NATIVE
#include <SDFunc.h>
#endif

// #define CMD_START 0x02 //ctrl + b
// #define CMD_END 0x04   //ctrl + d
// #define TAM_ESCAPE 4

#define ESCAPE_CMD 0x12
#define OPEN_CMD   0x02
// #define LEN_CMD     
#define END_CMD    0x05
#define CLOSE_CMD  0x04

char bufferTmp[] = {0, 0, 0, 0, 0, 0, 0, 0};

char nameFile[] = "/hello.wav";



/* void recvOneChar(char bufChar)
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
 */

boolean header(int count, char byte)
{
    boolean ret = false;

    if (byte == escape[count])
    {
        ret = true;
    }

    bufferTmp[count] = byte;

    if (ret)
        return true;
    else
        return false;
}


// esperando escape
// escape
// 
enum wait_events {WAIT_ESC, WAIT_OPEN, WAIT_LEN, WAIT_END,WAIT_CLOSE};
void header(char byte)
{
    static u_int8_t controller;
    static bool hasEscape = false;

    switch (controller)
    {      
    case WAIT_ESC:
        if (byte == ESCAPE_FLAG)
        {
            hasEscape = true;
        }
        openFileW(nameFile);
        break;
    }
}





void processData(char byte)
{
    static boolean b_escapeCorrect = 0;
    static boolean file_open = false;
    static int counterCompare = 0;

#ifdef DEBUG
    if (isPrintable(byte))
    {
        DBG_PRINTCH(byte);
    }
    else
    {
        DBG_PRINTX(byte);
    }
#endif

    if (header(counterCompare, byte))
    {
        counterCompare++;
        if (counterCompare == TAM_ESCAPE)
        {
            b_escapeCorrect = true;
            DBG_PRINTS("header encontrado");
        }
        return;
    }

    if (b_escapeCorrect)
    {
        b_escapeCorrect = false;

        switch (byte)
        {
        case CMD_START:
            openFileW(nameFile);
            file_open = true;
            break;
        case CMD_END:
            closeFile();
            file_open = false;
            break;
        }

        memset(bufferTmp, 0, sizeof(bufferTmp));
    }

    else if (file_open)
    {
        writeFileW(bufferTmp);
    }

    // memset(bufferTmp, 0, sizeof(bufferTmp));
    memset(bufferTmp, 0, counterCompare);
    counterCompare = 0;
}
