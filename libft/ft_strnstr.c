/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: alexanderkant <alexanderkant@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 10:34:34 by alexanderka   #+#    #+#                 */
/*   Updated: 2020/11/23 10:34:35 by alexanderka   ########   odam.nl         */
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
