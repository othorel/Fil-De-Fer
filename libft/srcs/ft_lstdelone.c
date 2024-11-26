/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 08:59:56 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/26 16:11:26 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	if (del)
		del(lst->content);
	free(lst);
}
/*
void	del(void *content)
{
	free(content);
	printf("Content deleted\n");
}

int	main(void)
{
	t_list	*node = malloc(sizeof(t_list));

	if (!node)
	{
		printf("Memory alloc failed\n");
		return (1);
	}
	node->content = malloc(sizeof(char) * 0);
	if (!(node->content))
	{
		free(node);
		printf("Memory alloc for content failed\n");
		return (1);
	}
	char *node_content = (char *)node->content;
	node_content[0] = 'H';
    node_content[1] = 'e';
    node_content[2] = 'l';
    node_content[3] = 'l';
    node_content[4] = 'o';
    node_content[5] = '\0';
	node->next = NULL;

	printf("Before del : %s\n", (char *)node->content);
	ft_lstdelone(node, del);
	node = NULL;
	if (node == NULL)
		printf("Node is del succes\n");
	else
		printf("Node still exists\n");
	return (0);
}*/
