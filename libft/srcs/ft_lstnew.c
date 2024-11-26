/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:32:38 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/26 16:11:53 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
/*
int	main(void)
{
	char	*str = "Hello lst !";
	t_list	*new = ft_lstnew((void *)str);

	if (new == NULL)
	{
		printf("Error alloc.\n");
		return (1);
	}
	printf("Content of cell : %s\n", (char *)new->content);
	free(new);
}*/
