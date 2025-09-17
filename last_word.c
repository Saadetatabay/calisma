#include<unistd.h>
void last(char *str)
{
    int len = 0;
    int i = 0;
    while(str[len])
        len++;
    while(str[len-1]==' ' || (str[len-1]>=9 && str[len-1]<=13))
        len--;
    while(str[len-i-1]!=' ' && !(str[len-i-1]>=9 && str[len-i-1]<=13))
    {
        i++;
    }
    while(i>0)
    {
        write(1,&str[len-i],1);
        i--;
    }

}
int main(int argc,char **argv)
{
    if(argc == 2)
        last(argv[1]);
    write(1,"\n",1);
}