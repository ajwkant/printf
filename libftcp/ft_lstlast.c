/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstlast.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 13:58:34 by akant         #+#    #+#                 */
/*   Updated: 2021/01/02 15:39:15 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../printf.h"

t_list	*ft_lstlast(t_list *lst)
{
	write(1, "S", 1);
	while (lst)
	{
		write(1, "S", 1);
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	write(1, "S", 1);
	return (NULL);
}
