/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:17:07 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/26 16:11:45 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
/*
t_list	*create_elem(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = (void *)(intptr_t)content;
	new->next = NULL;
	return (new);
}

int main(void)
{
	t_list	*first = create_elem(1);
	first->next = create_elem(2);
	first->next->next = create_elem(3);
	first->next->next->next = create_elem(4);

	t_list	*last = ft_lstlast(first);
	
	if (last)
	{
		int	value = (int)(intptr_t)last->content;
		printf("The last elem is : %d\n", value);
	}
	else
		printf("List empty.\n");

	t_list	*temp;
	while (first)
	{
		temp = first->next;
		free(first);
		first = temp;
	}
}*/
