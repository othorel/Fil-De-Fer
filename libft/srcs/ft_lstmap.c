/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olthorel <olthorel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:17:17 by olthorel          #+#    #+#             */
/*   Updated: 2024/11/26 16:11:49 by olthorel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*new;
	t_list	*current;

	if (!lst || !f || !del)
		return (NULL);
	start = ft_lstnew(f(lst->content));
	if (!start)
		return (NULL);
	current = start;
	lst = lst->next;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		current->next = new;
		current = new;
		lst = lst->next;
	}
	return (start);
}
/*
t_list	*create_elem(void *content)
{
	t_list	*elem;

	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}

void *double_value(void *content)
{
    int	*value;
    int	*new_value;
	
	value = (int *)content;
	new_value = (int *)malloc(sizeof(int));
    if (!new_value)
        return (NULL);
    *new_value = *value * 2;
    return (new_value);
}

void	del(void *content)
{
	free(content);
}

void print_list(t_list *lst) 
{
    while (lst) 
	{
        printf("%d -> ", *(int *)lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}

int main(void)
{
	t_list *list = create_elem((void *)(intptr_t)(1));
    list->next = create_elem((void *)(intptr_t)(2));
    list->next->next = create_elem((void *)(intptr_t)(3));

    printf("Original list:\n");
    print_list(list);

    t_list *new_list = ft_lstmap(list, double_value, del);

    printf("Transformed list (doubled values):\n");
    print_list(new_list);

    while (list) {
        t_list *temp = list;
        list = list->next;
        del(temp->content);
        free(temp);
    }
    while (new_list) {
        t_list *temp = new_list;
        new_list = new_list->next;
        del(temp->content);
        free(temp);
    }

    return 0;
}*/
