#include<unistd.h>
int ft_atoi(char *str)
{
    while(*str==' ' || (*str>=9 && *str <=13))
        str++;
    int sign = 1;
    long int  i = 0;
    if(*str=='-')
    {
        sign = -1;
        str++;
    }
    while(*str>='0' && *str<='9')
    {
        i *=10;
        i += (*str - '0');
        str++;
    }
    return (i*sign);
}
#include<stdio.h>
int main()
{
	printf("%d\n", ft_atoi(" \n  -2147483648"));
}