
// made by chat
#include <stdlib.h>
#include "ft_list.h"

// Example comparison function
int cmp(void *data, void *data_ref)
{   
    return (*(int *)data - *(int *)data_ref);
}

// Function to print the list
void print_list(t_list *head)
{   
    while (head)
    {   
        printf("%d -> ", *(int *)head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Create a new node
t_list *new_node(int value)
{
    t_list *node = malloc(sizeof(t_list));
    int *data = malloc(sizeof(int));
    *data = value;
    node->data = data;
    node->next = NULL;
    return node;
}

int main(void)
{
    // Create list: 1 -> 2 -> 3 -> 2 -> 4 -> NULL
    t_list *head = new_node(1);
    head->next = new_node(2);
    head->next->next = new_node(3);
    head->next->next->next = new_node(2);
    head->next->next->next->next = new_node(4);

    printf("Original list:\n");
    print_list(head);

    // Remove all nodes with value 2
	ft_list_remove_if(&head, &(int){2}, cmp);

    printf("After removing 2:\n");
    print_list(head);

    // Free remaining nodes
    t_list *tmp;
    while (head)
    {
        tmp = head;
        head = head->next;
        free(tmp->data);
        free(tmp);
    }

    return 0;
}


