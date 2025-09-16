#include<stddef.h>
char* ft_strpbrk(const char*s,const char *accept)
{
    int i = 0;
    int j ;
    while(s[i])
    {
        j = 0;
        while(accept[j])
        {
            if(s[i]==accept[j])
                return((char *)&s[i]);
            j++;
        }
        i++;
    }
    return(NULL);
}

#include <stdio.h>

int main()
{
	printf("%s\n", ft_strpbrk("Hello World!", "e"));
}