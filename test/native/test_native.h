
#define openFileW(x) { printf("arquivo %s aberto \n", x); }
#define closeFile() { printf("arquivo fechado \n"); }

void testeBuf(char * buf)
{
    char i;
    char texto[] = "ola mundo";    
    
    for(i = 0; i < 10; i++)
    {
        buf[i] = texto[i];
    }    
}

void func(char *buf, size_t count)
{
    printf("%u\n", *buf);
}

void writeOnFile(char *myData)
{
    for (int i = 0; i < 5; i++)
    {
        printf("write { 0x%02x }\n", myData[i]);
    }
}


// ====================================================================
// bluetooth
void answer(uint8_t ans)
{
    printf("comando enviado: 0x%02x \n", ans);
}