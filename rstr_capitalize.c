#include<unistd.h>
void capitalize(char *str)
{
    int i = 0;
    while(str[i])
    {
        if(str[i]>='A' && str[i]<='Z')
            str[i]+=32;
        if(((str[i]>='a' && str[i]<='z') && !str[i+1]) || ((str[i]>='a' && str[i]<='z') && str[i+1]==' '))
            str[i]-=32;
        i++;
    }
    i = 0;
    while(str[i])
    {
        write(1,&str[i],1);
        i++;
    }
}
void rstr_capitalize(char **argv)
{
    int i = 1;
    while(argv[i])
    {
        capitalize(argv[i]);
        write(1,"\n",1);
        i++;
    }
}
int main(int argc,char **argv)
{
    if(argc>1)
        rstr_capitalize(argv);
    else
        write(1,"\n",1);
}