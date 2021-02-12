/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_char.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/30 10:49:42 by akant         #+#    #+#                 */
/*   Updated: 2021/02/10 10:24:30 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*field_maker_char(t_word *node, int *field_width)
{
	char	*field;

	*field_width = node->width > 1 ? node->width : 1;
	field = calloc(*field_width + 1, sizeof(char));
	if (!field)
		return (NULL);
	ft_memset(field, ' ', *field_width);
	return (field);
}

int		char_convert(va_list *varlist, t_word *node, int i)
{
	char	*field;
	int		field_width;
	char	temp;

	if (node->zero_flag || node->precision_bool == 1)
		return (free_node(node));
	temp = va_arg(*varlist, int);
	field = field_maker_char(node, &field_width);
	if (!field)
		return (free_node(node));
	if (node->minus_flag)
		field[0] = temp;
	else
		field[field_width - 1] = temp;
	g_char_count += field_width;
	write(1, field, field_width);
	free(field);
	free(node);
	return (i + 1);
}
