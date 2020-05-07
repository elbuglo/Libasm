/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nine <nine@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/28 10:31:39 by lulebugl          #+#    #+#             */
/*   Updated: 2020/05/07 02:07:25 by nine             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

void
	printf_list(t_list *list)
{
	while (list)
	{
		printf("; %s\n", list->data);
		list = list->next;
	}
}

void
	ft_lstclear(t_list **list)
{
	t_list	*elem;

	while (*list)
	{
		elem = (*list)->next;
		if ((*list)->data)
			free((*list)->data);
		free(*list);
		*list = elem;
	}
}

int		ft_list_size(t_list *begin_list);

int		main(void)
{
	t_list	list;
	t_list	list_next;
	t_list	list_last;
	list.data = strdup("Blue");
	list.next = &list_next;
	list_next.data = strdup("sky");
	list_next.next = &list_last;
	list_last.data = strdup("and butterflies");
	list_last.next = NULL;
	printf("\n--ft_list_size\n");
	printf("list content:\n");
	printf_list(&list);
	printf("size : %d (from first : %d)\n", ft_list_size(&list), 3);
	printf("size : %d (from second : %d)\n", ft_list_size(&list_next), 2);
	printf("size : %d (NULL : %d)\n", ft_list_size(NULL), 0);
	printf("size : %d (from last : %d)\n", ft_list_size(&list_last), 1);
	printf("-done\n");
	free(list_next.data);
	free(list_last.data);
	return (0);
}