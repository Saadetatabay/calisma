#include<stdio.h>
#include<stdlib.h>
char	*ft_itoa(int nbr)
{
    int num;
    int count=0;
    num = nbr;
    if (nbr == 0)
    {
        char *ret = malloc(2);
        if (!ret) return NULL;
        ret[0] = '0';
        ret[1] = '\0';
        return ret;
    }
    if(nbr<0)
    {
        count++;
        num*=-1;
    }
    while(num>0)
    {
        count++;
        num=num/10;
    }
    char *ret = malloc((count+1)*sizeof(char));
    if(!ret)
        return NULL;
    int i = 0;
    if(nbr<0)
    {
        nbr*=-1;
        ret[i]='-';
        i++;
    }
    ret[count]='\0';
    while((count-1)>=i)
    {
        ret[count-1]=nbr%10 + '0';
        count--;
        nbr=nbr/10;
    }
    return(ret);
}
int main()
{
    printf("%s",ft_itoa(0));
}