#include<unistd.h>
void put_char(char a,int count)
{
    while(count)
    {
        write(1,&a,1);
        count--;
    }
}
void repeat_alpha(char *stringg)
{
    int  i = 0;
    while(stringg[i])
    {
        if (stringg[i] >= 'A' && stringg[i] <= 'Z')
            put_char(stringg[i],stringg[i]-'A'+1);
        else if (stringg[i] >= 'a' && stringg[i] <= 'z')
            put_char(stringg[i],stringg[i]-'a'+1);
        else
            write(1,&stringg[i],1);
        i++;
    }
}
int main(int argc,char **argv)
{
    if(argc == 2)
        repeat_alpha(argv[1]);
    write(1,"\n",1);
}