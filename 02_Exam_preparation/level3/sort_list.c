
#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int		temp;
	t_list	*head;
	
	if (!lst || !cmp)
		return (NULL);
	head = lst;
	while (lst->next)
	{
		if (cmp(lst->data, list->next->data) == 0)
		{
			temp = list->data;
			list->data = list->next->data;
			list->next->data = temp;
			lst = head;
		}
		list = list->next;
	}
	return (head);
}	
