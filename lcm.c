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
        return(a*b);
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
    return (a*b/bolen);
}
#include<stdio.h>
int main()
{
    printf("%d",lcm(4,3));
}