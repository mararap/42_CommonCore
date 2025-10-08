
#include <stddef.h>
#include "ft_list.h"

void	ft_list_foreach(t_list *begin, void (*f)(void *))
{
	while (begin_list != NULL)
	{
		if (begin_list->data != NULL)
			(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}
