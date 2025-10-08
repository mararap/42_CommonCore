
#include <stddef.h>
#include "ft_list.h"

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	// if pointer to pointer to first node does not exist, or
	// if pointer to first node does not exist, or
	// if the function pointer is not valid:
	// return
	if (!begin_list || !*begin_list || !cmp)
		return;
	// while current pointer to node does not point to NULL
	while (*begin_list)
	{
		// if cmp-function returns 0, meaning that
		// the data stored at the current node
		// is equal to the data that data_ref points to
		if (cmp((*begin_list)->data, data_ref) == 0)
		{
			// store the pointer to current node in temp
			temp = *begin_list;
			// re-link pointer that points to current node
			// so it points to next node
			*begin_list = (*begin_list)->next;
			// free what temp is pointing too
			free (temp);

		}
		else
		{
			// change the pointer to the pointer to the current
			// node, so it points to the pointer that points
			// to the next node
			begin_list = &(*begin_list)->next;
		}
	}
}
