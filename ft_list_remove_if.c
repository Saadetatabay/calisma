#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"  // t_list struct'ını buradan alıyoruz

// Örnek compare fonksiyonu
int cmp(void *a, void *b)
{
    return (*(int *)a - *(int *)b);
}
void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    while(*begin_list && cmp(((*begin_list)->data),data_ref)==0)
    {
        t_list *temp = *begin_list;
        *begin_list = (*begin_list)->next;
        free(temp);
    }
    t_list *current = *begin_list;

    while(current && current->next)
    {
        if(cmp(current->next->data,data_ref)==0)
        {
            t_list *temp = current->next;
            current->next=current->next->next;
            free(temp);
        }
        else
        {
            current=current->next;
        }
    }
}
int main()
{
    // Listeyi oluştur
    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));
    t_list *node4 = malloc(sizeof(t_list));

    int a = 1, b = 2, c = 3, d = 2;

    node1->data = &a;
    node2->data = &b;
    node3->data = &c;
    node4->data = &d;

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = NULL;

    t_list *head = node1;

    printf("Liste başta: ");
    for (t_list *tmp = head; tmp; tmp = tmp->next)
        printf("%d -> ", *(int *)tmp->data);
    printf("NULL\n");

    // data_ref = 2 olan düğümleri sil
    int data_ref = 2;
    ft_list_remove_if(&head, &data_ref, cmp);

    printf("Liste sonra: ");
    for (t_list *tmp = head; tmp; tmp = tmp->next)
        printf("%d -> ", *(int *)tmp->data);
    printf("NULL\n");

    // Listeyi temizle
    t_list *tmp;
    while (head)
    {
        tmp = head;
        head = head->next;
        free(tmp);
    }

    return 0;
}