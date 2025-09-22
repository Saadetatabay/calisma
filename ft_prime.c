#include<stdio.h>
#include<stdlib.h>
void prime(int num)
{
    if(num==1)
    {
        printf("1");
        return;
    }
    int i=2;
    int carp = 0;
    while(i<=num)
    {   
        if(num%i==0)
        {
            if(carp==1)
                printf("*");
            num=num/i;
            carp = 1;
            printf("%d",i);
        }
        else
        i++;
    }
}
int main(int argc,char  *argv[])
{
    if(argc==2)
        prime(atoi(argv[1]));
    printf("\n");
}