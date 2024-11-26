/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:03:53 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/26 16:11:20 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if (!lst || !(*lst) || !del)
		return ;
	if ((*lst)->next)
		ft_lstclear((&(*lst)->next), del);
	del((*lst)->content);
	free (*lst);
	*lst = NULL;
}
/*
void del(void *content)
{
    free(content);
}

t_list	*create_elem(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_list **lst, t_list *elem)
{
	if (!lst || !elem)
		return ;
	elem->next = *lst;
	*lst = elem;
}

int	main(void)
{
	t_list	*lst = NULL;

	int	*value1 = malloc(sizeof(int));
	int	*value2 = malloc(sizeof(int));
	int	*value3 = malloc(sizeof(int));

	*value1 = 42;
	*value2 = 84;
	*value3 = 126;

	ft_lstadd_front(&lst, create_elem(value1));
    ft_lstadd_front(&lst, create_elem(value2));
    ft_lstadd_front(&lst, create_elem(value3));

	printf("List before lstclear :\n");

	t_list	*temp = lst;

	while (temp)
	{
		printf("%d\n", *(int *)(temp->content));
        temp = temp->next;
	}
	ft_lstclear(&lst, del);

	if (lst == NULL)
        printf("Ok list clear.\n");
    else
        printf("Error list not clear.\n");

    return 0;
}*/
