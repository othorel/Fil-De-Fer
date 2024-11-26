/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:04:40 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/26 16:11:59 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
/*
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

int	main(void)
{
	t_list	*node1 = create_elem("First");
	t_list	*node2 = create_elem("Second");
	t_list	*node3 = create_elem("Three");

	node1->next = node2;
	node2->next = node3;

	int	size = ft_lstsize(node1);
	printf("Size of list is : %d\n", size);
	free(node1);
	free(node2);
	free(node3);
}*/
