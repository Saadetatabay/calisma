#include<stdlib.h>
static int word_count(char *s)
{
    int count = 0;
    if(*s!=' ')
        count++;
    int i = 1;
    while(s[i]) 
    {
        if(s[i] != ' ' && s[i-1]== ' ')
            count++;
        i++;
    }
    return (count);
}
static void free_split(char **splitted,int j)
{
    while(j>0)
    {
        j--;
        free(splitted[j]);
    }
    free(splitted);
}
static char **filling(char **splitted,char *str,int word_c)
{
    int j = 0;
    int len;
    int k = 0 ;
    int i;
    while(j<word_c)
    {
        len = 0;
        while(str[k] && str[k]==' ')
            k++;
        while(str[k+len] && str[k+len]!=' ')
            len++;
        splitted[j]=malloc(sizeof(char)*(len+1));
        if(!splitted[j])
        {
            free_split(splitted,j);
            return NULL;
        }
        i = 0;
        while(i<len)
        {
            splitted[j][i]=str[k];
            i++;
            k++;
        }
        splitted[j][i]='\0';
        j++;
    }
    splitted[j]=NULL;
    return(splitted);
}
char    **ft_split(char *str)
{
    int word_c;
    if(str[0]=='\0')
        word_c= 0;
    else
        word_c=word_count(str);
    char **splitted = malloc((word_c+1) *(sizeof(char *)));
    return (filling(splitted,str,word_c));
}
#include<stdio.h>
int main()
{
    char *str = "  dkfdf kdfmlsdk ffldf ";
    char **words=ft_split(str);
    printf("%s aaa %s aaa %s",words[0],words[1],words[2]);
    for (int i = 0; words[i]; i++)
        free(words[i]);
    free(words);

}