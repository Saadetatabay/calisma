#include<stdio.h>
static int check(int *tab,unsigned int size)
{
    int i = 1;
    while(i<size)
    {
        if(!(tab[i]>tab[i-1]))
            return 0;
        i++;
    }
    return 1;
}
void sort_int_tab(int *tab, unsigned int size)
{
    int i = 0;
    int temp;
    while(!check(tab,size))
    {
        i = 0;
        while(i+1 <size)
        {
            if(tab[i]>tab[i+1])
            {
                temp = tab[i];
                tab[i]=tab[i+1];
                tab[i+1]=temp;
            }
            i++;
        }
    }
}
int main()
{
    int tab[6] = {5, 4, 3, 2, 1, 0};
    sort_int_tab(tab, 6);
    printf("%d %d %d %d %d %d ",tab[0],tab[1],tab[2],tab[3],tab[4],tab[5]);
}