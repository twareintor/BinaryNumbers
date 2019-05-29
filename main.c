//Permanent link: https://rextester.com/YLIJKE12967
//bin2dec() and dec2bin() functions in C
//gcc 5.4.0 [x]
//Microsoft (R) C/C++ Optimizing Compiler Version 19.00.23506 for x64 [ ]
//Author: Twareintor - Copyright (c) 2019 Claudiu Ciutacu

#include  <stdio.h>
#include <memory.h>
#include <string.h>


/**
 *  This function fills a buffer of blanks with the binary 
 * form of the input positive integer n (by negative is
 * undefined behaviour) 
 * You have to provide enough room for the output string
 * or the result is undefined, the size of the output
 * string must be specified
 * Return value: the address of the output buffer
 */
char* dec2bin(char* out, size_t outSize, int n);

/**
 *  This function returns an integer equal to the corresponding
 * string "in" describing a number in bin format, which may 
 * contain any valid character but only '0' and '1' will be 
 * threated, rest are ignored (not assimilated to '0' - WARNING)
 * Consequently may contain digit group separators - any char
 * but '0' and '1' and the size must be specified
 */
int bin2dec(const char* in, size_t inSize);


int main(void)
{
    char szOut[] = "                           ";
    int len = strlen(szOut);
    printf("len = %d\n", len);
    int i;
    /* put both functions to the test in a loop: */
    for(i = 0; i<0x400; i++)
    {
        dec2bin(szOut, len, 323484+i);
        printf("\"%s\"\t%d\n", szOut, bin2dec(szOut, len));
    }
    
    return 0;
}


char* dec2bin(char* out, size_t outSize, int n)
{
    int i = 0, j = 1;
    char* tmp = out;
    out+=outSize;
    while(out > tmp)
    {
        // out[outSize-i-1] = '0'+(j==(n&j));
        *--out = '0'+(j==(n&j)); /* another way */
        j*=2;
        /* separate groups of digits by existing blank */
        if(!((i+1)%8)){i = -1; out--;}
        i++;
    }
    return out;
}

int bin2dec(const char* in, size_t inSize)
{
    int nOut = 0;
    int nCrt = 1; /* counts power of 2 */
    int i = inSize;
    while(i--)
    {
        /* elliminate the blanks and others */
        while(i&&!('0'==in[i]||'1'==in[i])) i--; 
        nOut+=nCrt*('1'==in[i]); /* add the power of two if '1' */
        nCrt*=2; /* powers of 2, the next one */
    }
    return nOut;
}
