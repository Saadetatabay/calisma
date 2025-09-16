#include<stddef.h>
size_t ft_strcspn(const char* src,const char*reject)
{
    int i = 0;
    int j ;
    while(src[i])
    {
        j = 0;
        while(reject[j])
        {
            if(src[i]==reject[j])
                return(i);
            j++;
        }
        i++;
    }
    return(i);
}
#include<string.h>
#include<stdio.h>
int main()
{
    printf("%ld",ft_strcspn("abc","kl"));
}