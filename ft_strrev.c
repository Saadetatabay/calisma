#include<stdio.h>
#include<string.h>
char *ft_strrev(char *str)
{
    char temp;
    int i = 0;
    int j = 0;
    while(str[i])
        i++;
    while (j<i/2)
    {
        temp = str[i-j-1];
        str[i-j-1] = str[j];
        str[j] = temp;
        j++;
    }
    return (str);
}
int main()
{
    char str[] = "hello";
    printf("%s",ft_strrev(str));
}