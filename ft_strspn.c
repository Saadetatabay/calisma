#include<stdio.h>
#include<string.h>
size_t ft_strspn(const char *s,const char *accept)
{
    int i = 0;
    int j;
    int ret = 0;
    int b;
    while(s[i])
    {
        j=0;
        b = 0;
        while(accept[j])
        {
            if(s[i]==accept[j])
            {
                ret++;
                b = 1;
                break;
            }
            j++;
        }
        if (b==0)
            break;
        i++;
    }
    return(ret);
}

int main()
{
    char str[] = "elokheee";
    char accept[] = "hello";
    printf("%ld",ft_strspn(str,accept));
}