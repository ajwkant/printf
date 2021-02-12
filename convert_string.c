/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_string.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/21 12:20:51 by akant         #+#    #+#                 */
/*   Updated: 2021/02/09 18:01:11 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*field_maker_string(t_word *node, int *len, int *field_width)
{
	char	*field;

	*field_width = node->width > *len ? node->width : *len;
	field = calloc(*field_width + 1, sizeof(char));
	if (!field)
		return (NULL);
	ft_memset(field, ' ', *field_width);
	return (field);
}

char	*data_maker_string(t_word *node, char *word, int *len)
{
	char	*str;

	if (node->precision_bool && node->dot_flag < 0)
		node->precision_bool = 0;
	if (node->precision_bool && node->dot_flag < *len)
		*len = node->dot_flag;
	str = ft_calloc(*len + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, word, *len);
	return (str);
}

char	*null_string(char *str, int *len)
{
	if (str)
	{
		*len = (int)ft_strlen(str);
		return (str);
	}
	*len = 6;
	return ("(null)");
}

int		string_convert(va_list *varlist, t_word *node, int i)
{
	char	*str;
	int		len;
	char	*field;
	int		field_width;

	str = va_arg(*varlist, char *);
	str = null_string(str, &len);
	str = data_maker_string(node, str, &len);
	if (!str)
		return (free_node(node));
	field = field_maker_string(node, &len, &field_width);
	if (!field)
		return (free_node(node));
	if (node->minus_flag)
		ft_memcpy(field, str, len);
	else
		ft_memcpy(field + (field_width - len), str, len);
	free(str);
	g_char_count += field_width;
	write(1, field, field_width);
	free(field);
	return (i + 1);
}
