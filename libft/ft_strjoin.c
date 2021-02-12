/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/08 17:07:39 by akant         #+#    #+#                 */
/*   Updated: 2021/02/01 14:33:19 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		total_length;
	char	*string;

	i = 0;
	total_length = (int)(ft_strlen(s1) + ft_strlen(s2));
	string = ft_calloc((total_length + 1), sizeof(char));
	if (string == NULL)
		return (NULL);
	while (i < total_length && *s1)
	{
		string[i] = *s1;
		s1++;
		i++;
	}
	while (i < total_length && *s2)
	{
		string[i] = *s2;
		s2++;
		i++;
	}
	if (*s2)
		free((void *)s2);
	return (string);
}
