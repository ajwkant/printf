/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   itoa.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/05 16:51:45 by akant         #+#    #+#                 */
/*   Updated: 2021/02/09 18:07:29 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*fill_in_str_u(unsigned int n, char *string, int digits)
{
	int i;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	while (n)
	{
		string[digits - i - 1] = n % 10 + '0';
		n /= 10;
		i++;
	}
	return (string);
}

char	*unsigned_itoa(unsigned int n)
{
	int				digits;
	unsigned int	num;
	char			*string;

	digits = 0;
	num = n;
	while (num != 0)
	{
		digits++;
		num /= 10;
	}
	if (n == 0)
		digits = 1;
	string = ft_calloc(digits + 1, sizeof(char));
	if (!string)
		return (NULL);
	return (fill_in_str_u(n, string, digits));
}

char	*char_join(char c, char *s2)
{
	char	*string;
	int		i;

	i = 0;
	string = ft_calloc((ft_strlen(s2) + 2), sizeof(char));
	if (string == NULL)
		return (NULL);
	string[0] = c;
	while (s2 && s2[i])
	{
		string[i + 1] = s2[i];
		i++;
	}
	if (s2)
		free((void *)s2);
	return (string);
}

char	*hex_itoa(long int n, int caseint)
{
	char		*alphabet;
	int			index;
	char		*str;

	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
		n = UINT_MAX + n + 1;
	alphabet = "0123456789abcdef0123456789ABCDEF";
	str = NULL;
	while (n)
	{
		index = n % 16;
		str = char_join(alphabet[index + caseint], str);
		if (!str)
			return (NULL);
		n /= 16;
	}
	return (str);
}

int		index_increment(char *string, int i)
{
	while (ft_isdigit(string[i + 1]) || string[i + 1] == '*')
		i++;
	return (i);
}
