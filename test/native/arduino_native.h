#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <time.h>


#define boolean bool


#define digitalWrite(x, y) { printf("pin %d %d\n", x, y); }


boolean isPrintable(char x) {
    if( (x >= 32) && (x <= 126) ) {
        return true;
    } 
    else {
        return false; 
    }
}



// C function showing how to do time delay

// To use time library of C

  
void delay(int milliseconds)
{ 
    long pause;
    clock_t now,then;

    pause = milliseconds*(CLOCKS_PER_SEC/1000);
    now = then = clock();
    while( (now-then) < pause )
        now = clock();
}

