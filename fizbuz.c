#include<unistd.h>
void put_nbr(int i)
{
    if(i>9)
        put_nbr(i/10);
    char a = i%10 + '0';
    write(1,&a,1);
}
int main()
{
   int i = 0;
   while (i<101)
   {
    if (i%15==0)
        write(1,"fizbuz\n",7);
    else if(i%3==0)
        write(1,"fiz\n",4);
    else if(i%5==0)
        write(1,"buz\n",4);
    else
    {
        put_nbr(i);
        write(1,"\n",1);
    }    

    i++;
   }
}