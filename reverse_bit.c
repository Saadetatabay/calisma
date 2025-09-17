#include<unistd.h>
unsigned char	reverse_bits(unsigned char octet)
{
    //0000 0101
    //0000 0000
    int i = 0;
    unsigned char c = 0;

    while(i<8)
    {
        c = c<<1;
        c = c | (octet>>i & 1);
        i++;
    }
    return(c);
}
#include<stdio.h>
int main()
{
    unsigned char c = 2;
    printf("%d",reverse_bits(c));
}