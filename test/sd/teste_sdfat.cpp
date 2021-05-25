// Ported to SdFat from the native Arduino SD library example by Bill Greiman
// On the Ethernet Shield, CS is pin 4. SdFat handles setting SS

/*
 SD card read/write
  
 This example shows how to read and write data to and from an SD card file 	
 The circuit:
 * SD card attached to SPI bus as follows:
 ** MOSI - pin 11
 ** MISO - pin 12
 ** CLK - pin 13
 ** CS - pin 4
 
 created   Nov 2010
 by David A. Mellis
 updated 2 Dec 2010
 by Tom Igoe
 modified by Bill Greiman 11 Apr 2011
 This example code is in the public domain.
 	 
 */

//#include <SdFat.h>
#include <debug.h>
#include <manage_files.h>

//SdFat sd;
//SdFile myFile;

char namefile[] = "test.txt";


// uint8_t test_buffer[] = "abcderfgijlmnopqrstuvxzABCDEFGHIJLMNOPQRSTUVXZ123456789abcderfgijlmnopqrstuvxzABCDEFGHIJLMNOPQRSTUVXZ123456789abcderfgijlmnopqrstuvxzABCDEFGHIJLMNOPQRSTUVXZ123456789";
char test_buffer[] = {97,98,99,100,101,102,103,104,105,106,'\0'};

uint8_t test[] = {1,2,3,4,5};

void setup()
{
    Serial.begin(115200);
    while (!Serial)
    {
    } // wait for Leonardo
    Serial.println("Type any character to start");
    while (Serial.read() <= 0);
    delay(400); // catch Due reset problem

    initSd();
    
    removeFile(namefile);
    openFileW(namefile);
    Serial.println("Writing to test.txt...");
    writeOnFile(test_buffer, 10);
    Serial.println("done.");
    closeFile();

    Serial.println("read file: ");
    openFileR(namefile);
    readFile();
    closeFile();

    printf("size: %u \n",sizeof(test_buffer));
}

void loop()
{
    // nothing happens after setup
}
