#include<stdio.h>
#include<stdarg.h>

int topla(int miktar,...)
{
    va_list arg; //değişken sayıda argümanları tutmak için kullanılır
    //va_list, değişken sayıda argümanları tutmak için kullanılan bir veri
    //yapısıdır. Bu yapı, fonksiyonun argümanlarını dinamik olarak
    //alabilmemizi sağlar.
    //va_start makrosu, argüman listesinin başlangıcını belirtir.
    //va_end makrosu, argüman listesinin sonunu belirtir.
    //va_arg makrosu, argüman listesinden bir argüman alır
    //ve bu argümanın tipini belirtmemizi sağlar.
    int toplam = 0;
    va_start(arg, miktar);
    for(int i = 0; i < miktar; i++)
    {
        toplam += va_arg(arg, int);
    }
    va_end(arg);
    return toplam;    
}
int main()
{
    int sonuc = topla(5, 10, 20, 30, 40, 50);
    printf("Toplam: %d\n", sonuc);
    return 0;
}