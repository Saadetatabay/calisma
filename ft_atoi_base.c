
int	ft_atoi_base(const char *str, int str_base)
{
    int sign = 1;
    int i = 0;
    int result = 0;
    if(str[i]=='-')
    {
        sign=-1;
        i++;
    }
    char *s = "0123456789abcdef";

    //2f
    while(str[i])
    {
        result*=str_base;
        if(str[i]>='0' && str[i]<='9')
            result+= str[i] - '0';
        if(str[i]>='a' && str[i]<='f')
            result+=str[i]-'a'+10;
        if(str[i]>='A' && str[i]<='F')
            result+=str[i]-'A'+10;
        i++;
    }
    return(result*sign);
}
#include<stdio.h>
int main()
{
    printf("%d",ft_atoi_base("-77", 8));
}