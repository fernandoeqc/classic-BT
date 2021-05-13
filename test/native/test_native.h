/* #define digitalWrite(x, y)          \
    {                               \
        printf("pin %d %d", x, y);  \
    }  */                          

#define digitalWrite(x, y) printf("pin %d %d\n", x, y);