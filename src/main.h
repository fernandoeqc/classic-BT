#ifdef DEBUG
    #define DB_PRINTS(s)           \
    {                           \
        Serial.println(F(s));   \
    }
    #define DB_PRINTCH(c)          \
    {                           \
        Serial.println(c);      \
    }
    #define DB_PRINTX(s)           \
    {                           \
        Serial.print(s, HEX);   \
        Serial.println("");     \
    }

    //
    #define DB_WAIT_START                \
    {                                    \
        Serial.println("press any key"); \
        while (!Serial.available());     \
    }                                   
#else
    #define DB_PRINTS(s)
    #define DB_PRINTCH(c)
    #define DB_PRINTX(s)
    #define DB_WAIT_START
#endif