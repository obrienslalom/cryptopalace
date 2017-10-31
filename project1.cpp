#include <string>
#include <cstring>
#include <stdlib.h>
#include <iostream>

const char* BASE64_TABLE = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

char HexToByte(char c) 
{
    if(c >= 'a' && c <= 'f')
    {
        return 10 + (c - 'a');
    }
    else if(c >= 'A' && c <= 'F')
    {
        return 10 + (c - 'A');
    }
    else
    {
        return c - '0';
    }
    return 0;
}

const char* HexToBase64(const char* c) 
{
    if(!c) return "";

    unsigned sz = strlen(c);
    unsigned num_bits = sz * 4;
    unsigned base64_size = num_bits / 6; 
    char* const buff = ((char*) malloc(sizeof(char) * base64_size));
    for(unsigned i = 0, j = 0; j < sz; i+=3, j+=2)
    {
        unsigned six_bit_val = (HexToByte(c[i]) << 2) + (HexToByte(c[i + 1]) >> 2); 
        buff[j] = BASE64_TABLE[six_bit_val];
        six_bit_val = ((HexToByte(c[i + 1]) & 0x3) << 4) + (HexToByte(c[i + 2]));
        buff[j+1] = BASE64_TABLE[six_bit_val];
    }
    return buff;
}

const char* XOR(const char* a, const char* b)
{
    unsigned a_sz = strlen(a);
    unsigned b_sz = strlen(a);
    if(a_sz != b_sz)
        return NULL;

    char* const buff = ((char*) malloc(sizeof(char) * a_sz));
    for(unsigned i = 0; i < a_sz; ++i)
    {
        buff[i] = HexToByte(a[i]) ^ HexToByte(b[i]);
    }
    return buff;
}
