#include<unistd.h>
void putnbr(int a)
{
    char c;
    if(a>9)
        putnbr(a/10);
    c = a%10 + '0';
    write(1,&c,1);
}
void paramsum(char **argv)
{
    int i = 0;
    while(argv[i])
        i++;
    putnbr(i-1);
}
int main(int argc,char **argv)
{
    if(argc>=2)
        paramsum(argv);
    write(1,"\n",1);

}