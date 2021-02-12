/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 13:59:11 by akant         #+#    #+#                 */
/*   Updated: 2021/01/02 15:39:06 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../printf.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *next_node;

	while (*lst)
	{
		next_node = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = next_node;
	}
	lst = NULL;
}
