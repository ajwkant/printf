/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_percentage.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/30 10:49:42 by akant         #+#    #+#                 */
/*   Updated: 2021/02/09 18:08:56 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*field_maker_percentage(t_word *node, int len, int *field_width)
{
	char	*field;
	char	c;

	c = ' ';
	*field_width = node->width > len ? node->width : len;
	if (node->zero_flag == 1 && !node->minus_flag)
		c = '0';
	field = calloc(*field_width + 1, sizeof(char));
	if (!field)
		return (NULL);
	ft_memset(field, c, *field_width);
	return (field);
}

char	*data_maker_percentage(t_word *node, char *word, int *len)
{
	char	*str;

	if (node->precision_bool && node->dot_flag < 0)
		node->precision_bool = 0;
	str = ft_calloc(*len + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_memcpy(str, word, *len + 1);
	return (str);
}

int		perc_convert(t_word *node, int i)
{
	char	*str;
	int		len;
	char	*field;
	int		field_width;

	str = "%%";
	len = 1;
	str = data_maker_percentage(node, str, &len);
	if (!str)
		return (free_node(node));
	field = field_maker_percentage(node, len, &field_width);
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
