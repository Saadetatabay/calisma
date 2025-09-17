#include<unistd.h>
void inter(char *str,char *ara)
{
    int i = 0;
    int j,b,k;
    while(str[i])
    {
        j = 0;
        while(ara[j])
        {
            if(str[i]==ara[j])
            {
                b = 1; //true
                if(i!=0)
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
                }
                if(b==1)
                {
                    write(1,&str[i],1);
                    break;
                }
            }
            j++;
        }
        i++;
    }
}
int main(int argc,char **argv)
{
    if (argc == 3)
        inter(argv[1],argv[2]);
    write(1,"\n",1);
}