int is_power_2(unsigned int n)
{
    if (n==1)
        return(1);
    int i = 2;
    while (i < n)
        i*=2;
    if (i == n)
        return(1);
    return(0);
}

#include <stdio.h>

int main()
{
	printf("%d\n", is_power_2(0));
}