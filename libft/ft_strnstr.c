/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/12 14:08:01 by akant         #+#    #+#                 */
/*   Updated: 2021/02/12 14:08:04 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_this_needle(char *haystack, char *needle, int i)
{
	while (haystack[i] == *needle && *needle)
	{
		i++;
		needle++;
	}
	if (!*needle)
		return (1);
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int i;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	if (!len)
		return (NULL);
	while (haystack[i] && len - i)
	{
		if (ft_strlen(needle) > len - i)
			return (NULL);
		if (haystack[i] == *needle)
		{
			if (is_this_needle((char *)haystack, (char *)needle, i))
				return ((char *)&(haystack[i]));
		}
		i++;
	}
	return (NULL);
}
