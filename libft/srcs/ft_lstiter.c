/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:13:27 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/26 16:11:37 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst && f)
	{
		f(lst->content);
		lst = lst->next;
	}
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

void print_content(void *content)
{
	printf("%s\n", (char *)content);
}

int	main(void)
{
	t_list	*elem1 = create_elem("Hello");
	t_list	*elem2 = create_elem("world");
	t_list	*elem3 = create_elem("!");

	elem1->next = elem2;
	elem2->next = elem3;

	printf("Content of list : \n");

	ft_lstiter(elem1, print_content);

	free(elem1);
	free(elem2);
	free(elem3);
}*/
