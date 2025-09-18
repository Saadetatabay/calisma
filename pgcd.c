#include<stdio.h>
#include<stdlib.h>
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

unsigned int    lcm(unsigned int a, unsigned int b)
{
    if(a==0 || b==0)
        return (0);
    int bolen=1;
    int i = 2;
    if(a==1 || b==1)
        return(1);
    while(i<=a && i<=b)
    {
        if(prime_mi(i) && a%i==0 && b%i==0)
        {
            bolen*=i;
            a=a/i;
            b=b/i;
        }
        else
            i++;
        
    }
    return (bolen);
}
int is_pos_string(char *str)
{
    int i = 0;
    while(str[i]==' ' || (str[i]>=9 && str[i]<=13))
        i++;
    if(str[i]=='+')
        i++;
    while(str[i])
    {
        if(str[i]>'9' || str[i]<'0')
            return (0);
        i++;
    }
    return (1);
}
int main(int argc,char **argv)
{
    if(argc==3 && is_pos_string(argv[1]) && is_pos_string(argv[2]) )
    {
        printf("%d",lcm(atoi(argv[1]),atoi(argv[2])));
    }
    printf("\n");
}