#include<unistd.h>
void wd_match(char *str,char *ara)
{
    int j = 0;
    int i = 0;
    while(str[i])
    {
        while(ara[j])
        {
            if(str[i]==ara[j])
            {
                break;
            }
            j++;
        }
        if(ara[j]=='\0')
            return;
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
    if(argc == 3)
        wd_match(argv[1],argv[2]);
    write(1,"\n",1);
}