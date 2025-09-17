unsigned char	swap_bits(unsigned char octet)
{
    //0001 0010 -> 0010 0001 
    unsigned char ret = 0;
    ret = ret |  octet;
    ret = ret<<4;
    ret = ret | octet>>4;
    return (ret);
}
#include <stdio.h>

int main()
{
	printf("%d\n", swap_bits(143));
}