#include "list.h"

t_list *sort_list(t_list *lst, int (*cmp)(int, int))
{
    int tmp;
    t_list *head = lst;  // save start of list
    t_list *current;

    if (!lst)
        return NULL;

    while (1)
    {
        int swapped = 0;
        current = head;
        while (current->next)
        {
            if (cmp(current->data, current->next->data) > 0)
            {
                tmp = current->data;
                current->data = current->next->data;
                current->next->data = tmp;
                swapped = 1;
            }
            current = current->next;
        }
        if (!swapped)
            break;
    }
    return head;
}

