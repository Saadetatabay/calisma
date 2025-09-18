#include<unistd.h>
void capitalize(char *str)
{
    int i;
    i = 0;
    if(!str[i])
        return;
    if(str[i]>='a' && str[i]<='z')
    {
        str[i]-=32;
    }
    i=1;
    while(str[i])
    {
        if(str[i]>='A' && str[i]<='Z')
            str[i]+=32;
        if(str[i-1]==' ' && str[i]>='a' && str[i]<='z')
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
int main(int argc,char **argv)
{
    if(argc>1)
    {
        int i = 1;
        while(i<argc)
        {
            capitalize(argv[i]);
            i++;
        }
    }
    write(1,"\n",1);
}