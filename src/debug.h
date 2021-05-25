#ifdef DEBUG
    #ifndef NATIVE
        #define DBG_PRINTS(s)          \
            {                         \
                Serial.println(F(s)); \
            }
        #define DBG_PRINTCH(c)         \
            {                         \
                Serial.print(c);    \
            }
        #define DBG_PRINTX(s) { Serial.print(s, HEX); }

        #define DBG_PRINT(x)           \
            {                         \
                Serial.println(x);    \
            }

        #define DBG_WAIT_START                    \
            {                                     \
                Serial.println("press any key");  \
                while (!Serial.available());      \
            }
    #else
        #define DBG_PRINTS(s)            \
            {                           \
                printf("%s ",s);       \
            }
        #define DBG_PRINTCH(c)           \
            {                           \
                printf("%c ",c);       \
            }
        #define DBG_PRINTX(s)            \
            {                           \
                printf("0x%x ", s);      \
            }
        #define DBG_PRINT(x)             \
            {                           \
                printf("%u ", x);      \
            }

        #define DBG_WAIT_START                    \
            {                                    \
                printf("press any key\n");         \
                getchar();                       \
                    ;                            \
            }
    #endif
#else
#define DBG_PRINTS(s)
#define DBG_PRINTCH(c)
#define DBG_PRINTX(s)
#define DBG_PRINT(x)
#define DBG_WAIT_START
#endif

