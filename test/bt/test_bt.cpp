#define DBG

#include <Arduino.h>
#include "test_bt.h"
#include <project_defines.h>
#include "BluetoothSerial.h"
#include "debug.h"
#include "manage_files.h"


#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

BluetoothSerial SerialBT;

int inteiro = 0;
void contador ()
{
    Serial.printf("Enviando %c, 0x%x\n", inteiro, inteiro);
    SerialBT.write(inteiro);
    delay(200);
    if(inteiro == 255)
    {
        inteiro = 0;
    }
    inteiro++;
}

void setup()
{
    pinMode(2, OUTPUT);
    
    Serial.begin(BAUD);     
        ;

    //DBG_WAIT_START
    
    SerialBT.begin(BT_NAME_CLASSIC); //Bluetooth device name
    Serial.println("The device started, now you can pair it with bluetooth!");

}

uint8_t ui = 0x06;
char ch = 0x06;
unsigned char uch= 0x06;

void loop()
{
    /* if (SerialBT.available())
    {
        processData(SerialBT.read());
    } */
    
    if (Serial.available())
    {
        char rd = Serial.read();
        if (rd == 'a')
        {
            Serial.println("envia 'a'");
            SerialBT.write('a');
        }
        if (rd == 'b')
        {
            Serial.println("envia '|n'");
            SerialBT.write('\n');
        }
        if (rd == 'c')
        {
            Serial.println("envia '0x0a'");
            SerialBT.write(0x0a);
        }
        if (rd == 'd')
        {
            Serial.println("envia 'uint_8' 0x06");
            SerialBT.write(ui);
        }
        if (rd == 'e')
        {
            Serial.println("envia 'char' 0x06");
            SerialBT.write(ch);
        }
        if (rd == 'f')
        {
            Serial.println("envia 'unsigned char' 0x06");
            SerialBT.write(uch);
        }
    }


}
