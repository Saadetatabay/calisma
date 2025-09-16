#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int do_op(int i,char *str,int j)
{
    if(*str == '*')
        return (i*j);
    else if (*str=='/')
        return(i/j);
    else if(*str=='+')
        return(i+j);
    else if(*str =='-')
        return(i-j);
    else if(*str=='%')
        return(i%j);
}
int main(int argc,char **argv)
{
    int i;
    int j;
    if (argc==4)
    {
        i = atoi(argv[1]);
        j = atoi(argv[3]);
        printf("%d",do_op(i,argv[2],j));
    }
}