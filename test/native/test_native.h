

#define openFileW(x) { printf("arquivo %s aberto \n", x); }
#define closeFile() { printf("arquivo fechado \n"); }

void writeFile (char * buf) 
{   
    printf("{");
    while(* buf)
    {
        printf("%02x ", *buf++); 
    }
    printf("}");
}


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
    printf("write: %u, m%u \n", myData , * myData);
    func((char *)myData, sizeof(myData));
}
