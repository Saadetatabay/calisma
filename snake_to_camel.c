#include<stdlib.h>
#include<unistd.h>
void snake(char *snake)
{
    char *ret;
    int i = 0;
    int l = 0;
    while(snake[l])
    {
        if(snake[l]!='_')
            i++;
        l++;
    }
    ret = (char *)malloc(i+1);
    int j = 0;
    i = 0;
    while(snake[j])
    {
        if(snake[j]=='_')
        {
            j++;
            snake[j]-=32;
        }
        ret[i] = snake[j];
        i++;
        j++; 
    }
    i = 0;
    while(ret[i])
    {
        write(1,&ret[i],1);
        i++;
    }
}
int main(int argc,char **argv)
{
    if (argc==2)
        snake(argv[1]);
    write(1,"\n",1);
}