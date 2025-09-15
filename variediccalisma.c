#include <stdio.h>
#include <stdarg.h>

typedef struct Veri {
    int a;
    int b;
}veri;

#define TOPLA(veri) ((veri).a + (veri).b)

int main()
{
    veri    v = {10,20};
    printf("%d",TOPLA(v));
}