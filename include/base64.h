#define MAX_BUFFER_CODEC 255


static unsigned char out_enc[MAX_BUFFER_CODEC];
static unsigned char out_dec[MAX_BUFFER_CODEC];

unsigned char *
base64_encode(unsigned char * in, unsigned char len, 
        unsigned char *out_len, bool end)
{
    unsigned char i = 0;
    while(in[i])
    {
        printf("i: %u, ", i);
        printf("%x, \n", in[i]);
        out_enc[i] = in[i] + 0x20;
        i++;

    }
    // *out_len = i;
    return out_enc;
}

unsigned char * 
base64_decode(unsigned char * in, unsigned char len, unsigned char *out_len, bool end)
{

}


/* 
unsigned char * base64_encode(unsigned char * in, unsigned char len, 
                    unsigned char *out_len, bool end);

unsigned char * base64_decode(unsigned char * in, unsigned char len, 
                    unsigned char *out_len, bool end);
 */