#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*current;

	current = *lst;
	while (current)
	{
		ft_lstdelone(current, (*del));
		current = current->next;
	}
}
