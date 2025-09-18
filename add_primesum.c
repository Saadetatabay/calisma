#include<unistd.h>
#include<stdio.h>
void putnbr(int n)
{
    char    a;
    if(n>9)
        putnbr(n/10);
    a = (n%10)+'0';
    write(1,&a,1);
}
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
int prime_mi(int n)
{
    if(n<2)
        return (0);
    if(n==2)
        return (1);
    int i = 2;
    while(i<=n/2)
    {
        if(n%i==0)
            return (0);
        i++;
    }
    return (1);
}
int add_prime(int n)
{
    int i = 0;
    int sum = 0;
    while(i<=n)
    {
        if(prime_mi(i))
            sum+=i;
        i++;
    }
    putnbr(sum);
}

int main(int argc,char **argv)
{
    if(argc!=2)
        write(1,"0",1);
    else
    {
        add_prime(ft_atoi(argv[1]));
    }
    write(1,"\n",1);
}