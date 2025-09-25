#include "ft_list.h"
#include<stdio.h>
#include<stdlib.h>
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    if (!begin_list || !*begin_list)
         return;

    t_list *t = *begin_list;
    if((*cmp)(t->data,data_ref)==0)
    {
        *begin_list = t->next;
        free(t->data);
        free(t);
        ft_list_remove_if(begin_list,data_ref,cmp);
    }
    else
        ft_list_remove_if(&t->next,data_ref,cmp);
}
int cmp_int(void *a, void *b)
{
    return (*(int*)a != *(int*)b); 
    // eşitse 0 döner, değilse 1 döner
}
void print_list(t_list *lst)
{
    while (lst)
    {
        printf("%d -> ", *(int*)lst->data);
        lst = lst->next;
    }
    printf("NULL\n");
}

int main(void)
{
    // 4 düğümlü liste: 10 -> 20 -> 30 -> 20 -> NULL
    int *n1 = malloc(sizeof(int));
    int *n2 = malloc(sizeof(int));
    int *n3 = malloc(sizeof(int));
    int *n4 = malloc(sizeof(int));
    *n1 = 10; *n2 = 20; *n3 = 30; *n4 = 20;

    t_list *a = malloc(sizeof(t_list));
    t_list *b = malloc(sizeof(t_list));
    t_list *c = malloc(sizeof(t_list));
    t_list *d = malloc(sizeof(t_list));

    a->data = n1; a->next = b;
    b->data = n2; b->next = c;
    c->data = n3; c->next = d;
    d->data = n4; d->next = NULL;

    t_list *head = a;

    printf("Silmeden önce liste:\n");
    print_list(head);

    int ref = 20; // silmek istediğimiz değer
    ft_list_remove_if(&head, &ref, cmp_int);

    printf("Silmeden sonra liste:\n");
    print_list(head);

    // Geriye kalan düğümleri serbest bırak
    while (head)
    {
        t_list *tmp = head->next;
        free(head->data);
        free(head);
        head = tmp;
    }

    return 0;
}