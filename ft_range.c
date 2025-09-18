#include<stdlib.h>
int     *ft_range(int start, int end)
{
    int i;
    int *array;
    int temp;
    i =0;
    if (start>end)
    {
        array = (int *)malloc((start-end+1)*(sizeof(int)));
        while(start>=end)
        {
            array[i] = start;
            start--;
            i++;
        }
        return(array);
    }
    array = (int *)malloc((end-start+1)*(sizeof(int)));
    if(!array)
        return NULL;
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

    printf("%d %d %d",ft_range(0,-2)[0],ft_range(0,-2)[1],ft_range(0,-2)[2]);
}