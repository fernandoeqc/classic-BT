#include "BluetoothSerial.h"
BluetoothSerial SerialBT;

void answer(uint8_t response)
{
    SerialBT.print(response);


}