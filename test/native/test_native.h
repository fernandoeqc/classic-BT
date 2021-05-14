

#define openFileByName(x) { printf("arquivo %s aberto \n", x); }
#define closeFile() { printf("arquivo fechado \n"); }
#define writeStrFile(x) { printf("%s", x); }

char str[] = "hello";
void clearStr()
{
    
    
    printf("str. %s", str);
    printf("tam. %lu", sizeof(str));

    memset(str, 0, sizeof(str));
    
    printf("str. %d", str[0]);
    printf("str. %d", str[1]);
    printf("str. %d", str[2]);
    printf("str. %d", str[3]);
    printf("str. %d", str[4]);
    printf("str. %d", str[5]);
    printf("str. %d", str[6]);
    printf("tam. %lu", sizeof(str));



}