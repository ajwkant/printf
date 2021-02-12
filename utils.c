/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/26 12:41:31 by akant         #+#    #+#                 */
/*   Updated: 2021/02/12 09:53:13 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*zero_padding(char const *s1, int n)
{
	int		i;
	int		total_length;
	char	*string;

	i = 0;
	total_length = (int)ft_strlen(s1) + n;
	string = ft_calloc((total_length + 1), sizeof(char));
	if (string == NULL)
		return (NULL);
	ft_memmove(string + n, s1, (int)ft_strlen(s1));
	while (i < n)
	{
		string[i] = '0';
		i++;
	}
	if (*s1)
		free((void *)s1);
	return (string);
}

int		print_chars(char *string, int begin_index)
{
	int	i;

	i = 0;
	while (1)
	{
		if (string[i] == '%' || string[i] == '\0')
			return (begin_index + i);
		else if (string[i + 1] == '%' || string[i + 1] == '\0')
		{
			write(1, string, i + 1);
			g_char_count += i + 1;
		}
		i++;
	}
}

int		in_set(char c, char *set)
{
	while (*set && *set != c)
		set++;
	if (*set == c)
		return (1);
	return (0);
}

int		flags_parser(t_word *node, char *string, int i, va_list *varlist)
{
	if (string[i] == '-')
		node->minus_flag = 1;
	else if (string[i] == '0')
		node->zero_flag = 1;
	else if (string[i] == '.')
	{
		node->precision_bool = 1;
		if (string[i + 1] == '*')
			node->dot_flag = va_arg(*varlist, int);
		else if (ft_isdigit(string[i + 1]))
			node->dot_flag = ft_atoi((const char *)&string[i + 1]);
		else
			node->precision_bool = 2;
		i = index_increment(string, i);
	}
	else if (string[i] == '*')
	{
		node->width = va_arg(*varlist, int);
		if (node->width < 0)
		{
			node->width *= -1;
			node->minus_flag = 1;
		}
	}
	return (i + 1);
}

int		free_node(t_word *node)
{
	free(node);
	return (-1);
}
