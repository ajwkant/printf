/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/12 13:58:45 by akant         #+#    #+#                 */
/*   Updated: 2020/11/19 14:59:16 by alexanderka   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t i;

	i = 0;
	while (n)
	{
		if (*((unsigned char *)str) == (unsigned char)c)
			return ((unsigned *)str);
		str++;
		n--;
	}
	return (NULL);
}
