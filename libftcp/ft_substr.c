/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: alexanderkant <alexanderkant@student.co      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/23 10:31:54 by alexanderka   #+#    #+#                 */
/*   Updated: 2020/11/23 10:31:57 by alexanderka   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*substr;
	size_t		size;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s) - 1)
		return (ft_calloc(1, 1));
	size = ft_strlen(s + start) > len ? len : ft_strlen(s + start);
	substr = ft_calloc(size + 1, sizeof(char));
	if (!substr)
		return (NULL);
	ft_memmove(substr, s + start, size);
	return (substr);
}
