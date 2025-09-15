#include<unistd.h>

void rot(char *str)
{
    int i = 0;
    while(str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = ((str[i] - 'A' + 13) % 26) + 'A';
        else if (str[i] >= 'a' && str[i] <= 'z')
             str[i] = ((str[i] - 'a' + 13) % 26) + 'a';
        else
            str[i] = str[i];
        write(1,&str[i],1);
        i++;
    }
}
int main(int argc,char **argv)
{
    if (argc==2)
        rot(argv[1]);
    write(1,"\n",1);
}