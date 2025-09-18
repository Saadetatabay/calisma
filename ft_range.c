#include<stdlib.h>
int     *ft_range(int start, int end)
{
    int i;
    int *array;
    array = (int *)malloc((end-start+1)*(sizeof(int)));
    if(!array)
        return NULL;
    i =0;
    while(start<=end)
    {
        array[i] = start;
        start++;
        i++;
    }
    return(array);
}
#include<stdio.h>
int main()
{

    printf("%d %d %d",ft_range(-1,1)[0],ft_range(-1,1)[1],ft_range(-1,1)[2]);
}