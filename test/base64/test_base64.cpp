#include <Arduino.h>
#define DEBUG

extern "C" {
  #include "crypto/base64.h"
}

#include <debug.h>
 

void setup() {
  Serial.begin(115200);
  while(!Serial);

  DBG_WAIT_START

  char * toEncode = "Hello World";
  size_t outputLength;
 
  unsigned char * encoded = base64_encode((const unsigned char *)toEncode, strlen(toEncode), &outputLength);

  Serial.print("Length of encoded message: ");
  Serial.println(outputLength);
 
  Serial.printf("%.*s", outputLength, encoded);
  free(encoded);
}

void loop() {}
