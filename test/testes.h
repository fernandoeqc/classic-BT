#include "sd.h"

char hello[] = "hello\n";

void le(){
    static File myFile2;

    myFile2 = SD.open("/hello.wav", FILE_READ);
    delay(10);
    Serial.print(myFile2.readString());
    Serial.println("leu");
}

void escreve(){
    static File myFile;

    myFile = SD.open("/hello.wav", FILE_WRITE);
    delay(10);
    
    myFile.printf(hello);
    delay(10);

    myFile.close();

    Serial.println("escreveu");


}

char a = 'a';
char str[] = "hello word!";
void debugPrints()
{
    
    DB_PRINTS(str);
    DB_PRINTCH(a);
    DB_PRINTX(a);
}

void clearString() 
{
    Serial.println(str);
    memset(str, 0, sizeof(str));
    Serial.println(str);

    Serial.println(sizeof(str));
}