#include<unistd.h>
int hidenp(char *str,char *ara)
{
    int i = 0;
    int j = 0;
    int b;
    while(str[i])
    {
        b = 0;
        while(ara[j])
        {
            if(str[i]==ara[j])
            {
                b = 1; //true
                break;
            }
            j++;
        }
        if(!ara[j] && b == 0)
            return (0);
        i++;
    }
    return(1);
}

int main(int argc,char **argv)
{
    char a;
    if(argc==3)
    {
        a=hidenp(argv[1],argv[2]) + '0';
        write(1,&a,1);
    }
    write(1,"\n",1);
}