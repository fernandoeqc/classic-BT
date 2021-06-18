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
    
    SerialBT.begin("esp32test"); //Bluetooth device name
    Serial.println("The device started, now you can pair it with bluetooth!");

}


void loop()
{
    if (SerialBT.available())
    {
        processData(SerialBT.read());
    }    
}
