#include<unistd.h>
void my_union(char *str,char *ara)
{
    int i = 0;
    int k;
    int b;
    while(str[i])
    {
        b = 1; //true
        if (i == 0)
            write(1,&str[i],1);
        else
        {
            k = 0;
            while(k<i)
            {
                if(str[k]==str[i])
                {
                    b = 0; //false
                    break;
                }
                k++;
            }
            if(b==1)
                write(1,&str[i],1);
        }   
        i++;
    }
    i = 0;
    while(ara[i])
    {
        b = 1; //true
        k = 0;
        while(str[k])
        {
            if(ara[i]==str[k])
            {
                b = 0; //false
                break;
            }
            k++;
        }
        if(b==1)
        {
            if(i == 0)
                write(1,&ara[i],1);
            else
            {
                k = 0;
                while(k<i)
                {
                    if(ara[k]==ara[i])
                    {
                        b=0;
                        break;
                    }
                    k++;
                }
                if(b==1)
                    write(1,&ara[i],1);
            }
        }
        i++;
    }
}

int main(int argc,char **argv)
{
    if(argc == 3)
        my_union(argv[1],argv[2]);
    write(1,"\n",1);
}