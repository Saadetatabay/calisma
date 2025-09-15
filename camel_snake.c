#include<unistd.h>
#include<stdlib.h>
void camel_snake(char   *str)
{
    char    *ret;
    int i = 0;
    int j = 0;
    while(str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z' && i!=0)
            i++;
        i++;
    }
    ret = (char *)malloc(i);
    i = 0;
    while(str[j])
    {
        if (str[j] >= 'A' && str[j] <= 'Z')
        {
            str[j] = str[j]+32;
            ret[i]='_';
            write(1,&ret[i],1);
            i++;
        }
        ret[i] = str[j];
        write(1,&ret[i],1);
        i++;
        j++;
    }
}
int main(int argc,char **argv)
{
    if(argc == 2)
        camel_snake(argv[1]);
    write(1,"\n",1);
}