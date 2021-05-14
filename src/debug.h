#ifdef DEBUG
    #ifndef NATIVE
        #define DB_PRINTS(s)          \
            {                         \
                Serial.println(F(s)); \
            }
        #define DB_PRINTCH(c)         \
            {                         \
                Serial.println(c);    \
            }
        #define DB_PRINTX(s)          \
            {                         \
                Serial.print(s, HEX); \
                Serial.println("");   \
            }
        #define DB_PRINT(x)           \
            {                         \
                Serial.println(x);    \
            }

        #define DB_WAIT_START                    \
            {                                    \
                Serial.println("press any key"); \
                while (!Serial.available())      \
                    ;                            \
            }
    #else
        #define DB_PRINTS(s)            \
            {                           \
                printf("%s\n",s);       \
            }
        #define DB_PRINTCH(c)           \
            {                           \
                printf("%c\n",c);       \
            }
        #define DB_PRINTX(s)            \
            {                           \
                printf("0x%x\n", s);      \
            }
        #define DB_PRINT(x)             \
            {                           \
                printf("%u\n", x);      \
            }

        #define DB_WAIT_START                    \
            {                                    \
                printf("press any key\n");         \
                getchar();                       \
                    ;                            \
            }
    #endif
#else
#define DB_PRINTS(s)
#define DB_PRINTCH(c)
#define DB_PRINTX(s)
#define DB_PRINT(x)
#define DB_WAIT_START
#endif