#include<unistd.h>
void expand_str(char *str)
{
    int i = 0;
    while(str[i]==' ' || (str[i]>=9 && str[i]<=13))
        i++;
    while(str[i])
    {
        if(str[i]!=' ' && !(str[i]>=9 && str[i]<=13))
        {
            write(1,&str[i],1);
        }
        else
        {
            while(str[i]==' ' || (str[i]>=9 && str[i]<=13))
                i++;
            if(str[i])
            {
                write(1," ",1);
                write(1," ",1);
                write(1," ",1);
                i--;
            }
            else
                break;
        }
        i++;
    }
}
int main(int argc,char **argv)
{
    if(argc==2)
        expand_str(argv[1]);
    write(1,"\n",1);
}