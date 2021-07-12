

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


#define ESP_TO_APP      "/a/RecvApp.txt"
#define APP_TO_ESP      "/a/SentApp.txt"
#define RADIO_TO_ESP    "/a/RecvRadio.wav"
#define ESP_TO_RADIO    "/a/SentRadio.wav"

//PRECISA ser divisivel por 3 e por 4
#define MAX_BUFFER_CODEC 36
#if (MAX_BUFFER_CODEC % 3 != 0) | (MAX_BUFFER_CODEC % 4 != 0)
    #error "max buff errado" 
#endif
#define MAX_BUFFER_RECV 255

static char buffer_recv[MAX_BUFFER_RECV];


void encode()
{
    unsigned char *encoded;
    char toEncode[MAX_BUFFER_CODEC+1];
    size_t outputLength;

    File fileWav = SD.open(RADIO_TO_ESP, FILE_READ);
    File file64 = SD.open(ESP_TO_APP, FILE_WRITE);
    
    while(fileWav.available())
    {

        fileWav.readBytes(toEncode, MAX_BUFFER_CODEC);
        encoded = base64_encode((const unsigned char *)toEncode, strlen(toEncode), &outputLength);
        
        // DBG_PRINTS(toEncode);
        DBG_PRINTS(encoded);
        file64.printf("%.*s", outputLength, encoded);

        memset(toEncode, 0, MAX_BUFFER_CODEC);
        free(encoded);

    }
    fileWav.close();
    file64.close();
}


void decode()
{
    unsigned char *decoded;
    char toDecode[MAX_BUFFER_CODEC+1];
    // char toDecode[MAX_BUFFER_CODEC+1] = "TWljcm9jaGlwIFRlY2hub2xvZ3kgb2ZmZXJz";
    size_t outputLength;

    File file64 = SD.open(APP_TO_ESP, FILE_READ);
    File fileWav = SD.open(ESP_TO_RADIO, FILE_WRITE);
    
    // while(file64 .available())
    // {
           
        file64.readBytes(toDecode, MAX_BUFFER_CODEC);
        Serial.printf("%s", toDecode);

        // decoded = base64_decode((const unsigned char *)toDecode, strlen(toDecode), &outputLength);

        // DBG_PRINTS(decoded);
        // Serial.printf("%.*s", outputLength, decoded);
        // fileWav.printf("%.*s", outputLength, decoded);

        free(decoded);
        delay(1000);

    // }

    Serial.println("passou por aqui");
    file64.close();
    fileWav.close();
}

/* =========================================================== */
uint8_t commands()
{
    static bool has_open_file = false;

    if (buffer_recv[0] == OPEN_CMD)
    {
        #pragma message "ajeitar escrita SDFunc"
        // openFileW();
        DBG_PRINTS("\nfile open\n");
        has_open_file = true;
        // digitalWrite(2, true);
        return OK_CMD;
    }

    else if (buffer_recv[0] == CLOSE_CMD)
    {
        closeFile();
        DBG_PRINTS("\nfile closed\n");
        has_open_file = false;
        // digitalWrite(2, false);
        return OK_CMD;
    }

    else if(buffer_recv[0] == NEW_PACK_CMD)
    {
        if(has_open_file)
        {
            writeOnFile(&buffer_recv[1]);
            // DBG_PRINTS(&buffer_recv[1]);
            return OK_CMD;
        }
    }

    return FAIL_CMD;
}
/* 
    concatena  os bytes recebidos no buffer_recv até encontrar
    o escape. quando recebe, exclui o caractere de escape,
    envia o buffer para commands() e zera o index do buffer.
*/
void processData(char byte)
{
    static uint8_t index = 0;

    // DBG_PRINTX(byte);

    buffer_recv[index] = byte;
    index++;

    if(byte == ESCAPE_CMD)
    {
        digitalWrite(2, true);
        buffer_recv[index-1] = 0;
        answer(commands());
        index = 0;
        digitalWrite(2, false);
    }    
}
/* =========================================================== */