#ifndef NATIVE
#include <SDFunc.h>
#endif

// #define CMD_START 0x02 //ctrl + b
// #define CMD_END 0x04   //ctrl + d
// #define TAM_ESCAPE 4

#define ESCAPE_CMD  0x12 // ^R
#define OPEN_CMD    0x02 // ^B
#define CLOSE_CMD   0x04 // ^D
#define END_CMD     0x17 // ^W
#define OK_CMD      0x06 // ^F
#define FAIL_CMD    0x15 // ^u


enum tasks {RECEIVE_APK_TASK, SEND_APK_TASK, COMMANDS_TASK, RECEIVE_RADIO_TASK, SEND_RADIO_TASK};

#pragma message "SEPARAR TASKS, SEPARAR ESCRITA EM ARQUIVO, ENVIO DE Audio e RECEBIMENTO DE COMANDOS EM TASKS SEPARADAS, NO MAIN"

char fileName[] = "/hello.wav";



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
 */


// esperando escape
// escape
// 


bool processData(char byte)
{


}

enum wait_events {WAIT_ESC, WAIT_CMD, WAIT_LEN, WAIT_BUF, WAIT_END,WAIT_CLOSE};
bool escape(char byte)
{
    static u_int8_t controller;
    static u_int8_t lenght_buffer;
    static u_int8_t index = 0;
    static char buffer_tmp[50];

    switch (controller)
    {      
    case WAIT_ESC:
        if (byte == ESCAPE_CMD)
        {
            DBG_PRINTS("ESCAPE\n");
            controller = WAIT_CMD;
        }
        break;
    
    case WAIT_CMD:
        controller = WAIT_ESC;
        if (byte == OPEN_CMD)
        {
            openFileW(fileName);
            controller = WAIT_LEN;
            DBG_PRINTS("file open\n");
            return RECEIVE_APK_TASK;
        }
        break;
    












    case WAIT_LEN:
        DBG_PRINTS("len\n");
        lenght_buffer = byte;
        controller = WAIT_BUF;
        break;

    case WAIT_BUF:
        DBG_PRINTS("buf: ");
        DBG_PRINTCH(byte);

        buffer_tmp[index] = byte;
        
        index++;
        if (index == lenght_buffer)
        {
            index = 0;
            controller = WAIT_END;
        }
        break;

    case WAIT_END:
        if ((byte == END_CMD) || (byte == CLOSE_CMD))
        {
            writeOnFile(buffer_tmp, lenght_buffer);
            
            if (byte == END_CMD)
            {
                controller = WAIT_LEN;
            }
            else
            {
                controller = WAIT_ESC;
                closeFile();
            }
            answer(OK_CMD);

            DBG_PRINTS("end\n");    
        }
        else
        {
            answer(FAIL_CMD);
            controller = WAIT_ESC;
            DBG_PRINTS("fail end\n");    
        }
        break;

    default:
        controller = WAIT_ESC;
    }
}

  
/* 


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
            openFileW(fileName);
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
 */