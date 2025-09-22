#include<stdlib.h>
#include<unistd.h>
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

static char **filling(char *str,int word_c)
{
    char **splitted=malloc((word_c+1)*sizeof(char*));    
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
    while(word_c)
    {
        word_c--;
        k=0;
        while(splitted[word_c][k])
        {
            write(1,&splitted[word_c][k],1);
            k++;
        }
        if(word_c)
            write(1," ",1);
    }
}
void rev_str(char *str)
{
    int word;
    if(*str=='\0')
        word = 0;
    else 
        word = word_count(str);
    filling(str,word);
}
int main(int argc,char **argv)
{
    if(argc==2)
        rev_str(argv[1]);
    write(1,"\n",1);
}