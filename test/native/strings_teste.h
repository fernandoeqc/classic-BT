
// um caractere a menos no buffer
int teste_string1[] = {
OPEN_CMD, ESCAPE_CMD, //comando abrir
NEW_PACK_CMD, 'A', 'B', 'C', ESCAPE_CMD, // comando pacote
NEW_PACK_CMD, 'D', 'E', 'F', ESCAPE_CMD,
NEW_PACK_CMD, 'D', 'E', 'F', ESCAPE_CMD,
NEW_PACK_CMD, 'D', 'E', 'F', ESCAPE_CMD,
NEW_PACK_CMD, 'D', 'E', 'F', ESCAPE_CMD,
NEW_PACK_CMD, 'D', 'E', 'F', ESCAPE_CMD,
NEW_PACK_CMD, 'D', 'E', 'F', ESCAPE_CMD,
NEW_PACK_CMD, 'D', 'E', 'F', ESCAPE_CMD,
NEW_PACK_CMD, 'D', 'E', 'F', ESCAPE_CMD,
NEW_PACK_CMD, 'D', 'E', 'F', ESCAPE_CMD,
CLOSE_CMD, ESCAPE_CMD, //comando fechar
0x01
};


int teste_string2[] = {
// OPEN_CMD, ESCAPE_CMD, 
NEW_PACK_CMD, 'A', 'B', 'C', ESCAPE_CMD,
NEW_PACK_CMD, 'D', 'E', 'F', 'G', 'H', 'I', 'J', ESCAPE_CMD,
CLOSE_CMD, ESCAPE_CMD,
0x00
};

int teste_string3[] = {
OPEN_CMD, ESCAPE_CMD, 
NEW_PACK_CMD, 'A', 'B', 'C', ESCAPE_CMD,
NEW_PACK_CMD, 'D', 'E', 'F', ESCAPE_CMD,
CLOSE_CMD, ESCAPE_CMD,
0x00
};

int teste_string4[] = {
OPEN_CMD, ESCAPE_CMD, 
NEW_PACK_CMD, 'A', 'B', 'C', ESCAPE_CMD,
NEW_PACK_CMD, 'D', 'E', 'F', ESCAPE_CMD,
CLOSE_CMD, ESCAPE_CMD,
0x00
};

int teste_string5[] = {
OPEN_CMD, ESCAPE_CMD, 
NEW_PACK_CMD, 'A', 'B', 'C', ESCAPE_CMD,
NEW_PACK_CMD, 'D', 'E', 'F', ESCAPE_CMD,
CLOSE_CMD, ESCAPE_CMD,
0x00
};