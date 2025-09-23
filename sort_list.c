#include "ft_list.h"
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
static int check_sira(t_list *lst,int (*cmp)(int ,int))
{
    while(lst && lst->next)
    {
        if(!cmp((int)(intptr_t)lst->data,(int)(intptr_t)lst->next->data))
        {
            return (1);
        }
        lst = lst->next;
    }
    return (0);
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    while(check_sira(lst,cmp))
    {
        t_list *temp = lst;
        while(temp && temp->next)
        {
            if(!cmp((int)(intptr_t)temp->data,(int)(intptr_t)temp->next->data))
            {
                int t = (int)(intptr_t)temp->data;
                temp->data = temp->next->data;
                temp->next->data=(void *)(intptr_t)t;
            }
            temp = temp->next;
        }

    }
    return(lst);
}


// cmp fonksiyonu (küçükten büyüğe)
int cmp(int a, int b)
{
    return (a <= b);
}

// Listeyi yazdıran fonksiyon
void print_list(t_list *lst)
{
    while (lst)
    {
        printf("%d ", (int)(intptr_t)lst->data);
        lst = lst->next;
    }
    printf("\n");
}

// Yeni node oluştur
t_list *create_node(int data)
{
    t_list *node = malloc(sizeof(t_list));
    node->data = (void*)(intptr_t)data;
    node->next = NULL;
    return node;
}

int main()
{
    // Listeyi oluştur: 3 -> 1 -> 4 -> 2
    t_list *lst = create_node(3);
    lst->next = create_node(1);
    lst->next->next = create_node(4);
    lst->next->next->next = create_node(2);

    printf("Before sort: ");
    print_list(lst);

    lst = sort_list(lst, cmp);

    printf("After sort:  ");
    print_list(lst);

    return 0;
}