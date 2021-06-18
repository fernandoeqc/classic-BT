

// #define CMD_START 0x02 //ctrl + b
// #define CMD_END 0x04   //ctrl + d
// #define TAM_ESCAPE 4

// requisicoes
#define ESCAPE_CMD      0x07   // ^G    
#define OPEN_CMD        0x02   // ^B
#define CLOSE_CMD       0x04   // ^D
#define NEW_PACK_CMD    0x01   // ^A

// respostas
#define OK_CMD          0x06   // ^F
#define FAIL_CMD        0x15   // ^u


bool file_open = false;
static char buffer_tmp[50];


enum tasks
{
    COMMAND_TASK,
    RECEIVE_APK_TASK,
    SEND_APK_TASK,
    RECEIVE_RADIO_TASK,
    SEND_RADIO_TASK
}; 

uint8_t commands()
{
    static bool has_open_file = false;

    if (buffer_tmp[0] == OPEN_CMD)
    {
        openFileW();
        DBG_PRINTS("\nfile open\n");
        has_open_file = true;
        return OK_CMD;
    }

    else if (buffer_tmp[0] == CLOSE_CMD)
    {
        closeFile();
        DBG_PRINTS("\nfile closed\n");
        has_open_file = false;
        return OK_CMD;
    }

    else if(buffer_tmp[0] == NEW_PACK_CMD)
    {
        if(has_open_file)
        {
            writeOnFile(&buffer_tmp[1]);
            DBG_PRINTS(&buffer_tmp[1]);
            return OK_CMD;
        }
    }

   
    return FAIL_CMD;
}
/* 
    concatena  os bytes recebidos no buffer_tmp até encontrar
    o escape. quando recebe, exclui o caractere de escape,
    envia o buffer para commands() e zera o index do buffer.
*/
void processData(char byte)
{
    static uint8_t index = 0;

    DBG_PRINTX(byte);

    buffer_tmp[index] = byte;
    index++;

    if(byte == ESCAPE_CMD)
    {
        buffer_tmp[index-1] = 0;
        answer(commands());
        index = 0;
    }
}
