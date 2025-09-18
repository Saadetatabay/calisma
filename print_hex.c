#include<unistd.h>
#include<stdlib.h>
void print_hex(int num)
{
    char *s = "0123456789abcdef";
    if(num>=16)
        print_hex(num/16);
    write(1,&s[num%16],1);
}
int is_pos_string(char *str)
{
    int i = 0;
    while(str[i]==' ' || (str[i]>=9 && str[i]<=13))
        i++;
    if(str[i]=='+')
        i++;
    while(str[i])
    {
        if(str[i]>'9' || str[i]<'0')
            return (0);
        i++;
    }
    return (1);
}

int main(int argc,char **argv)
{
    if(argc==2 && is_pos_string(argv[1]))
        print_hex(atoi(argv[1]));
    write(1,"\n",1);
}