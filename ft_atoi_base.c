
int	ft_atoi_base(const char *str, int str_base)
{
    int sign = 1;
    int i = 0;
    int result = 0;
    int digit;
    if (str_base < 2 || str_base >16)
        return (0);
    if(str[i]=='-')
    {
        sign=-1;
        i++;
    }
    char *s = "0123456789abcdef";

   
    while(str[i])
    {
        if(str[i]>='0' && str[i]<='9')
            digit = str[i] - '0';
        else if(str[i]>='a' && str[i]<='f')
            digit =str[i]-'a'+10;
        else if(str[i]>='A' && str[i]<='F')
            digit=str[i]-'A'+10;
        else
            break;
        result = result*str_base + digit;
        i++;
    }
    return(result*sign);
}
#include<stdio.h>
int main()
{
    printf("%d",ft_atoi_base("101", 2));
}