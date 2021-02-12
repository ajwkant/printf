/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_pointer.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/01 14:14:17 by akant         #+#    #+#                 */
/*   Updated: 2021/02/10 12:36:41 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*field_maker_pointer(t_word *node, int len,
		int *field_width)
{
	char	*field;

	*field_width = node->width > len ? node->width : len;
	field = calloc(*field_width + 1, sizeof(char));
	if (!field)
		return (NULL);
	ft_memset(field, ' ', *field_width);
	return (field);
}

char	*data_maker_pointer(long int num, int *len, t_word *node)
{
	char	*temp;
	char	*num_str;

	if ((node->precision_bool == 1 && node->dot_flag == 0)
		|| (!num && node->precision_bool == 2))
		num_str = ft_strdup("");
	else
		num_str = hex_itoa(num, 0);
	if (!num_str)
		return (NULL);
	temp = ft_strdup("0x");
	num_str = ft_strjoin(temp, num_str);
	free(temp);
	if (!num_str)
		return (NULL);
	*len = (int)ft_strlen(num_str);
	return (num_str);
}

int		pointer_convert(va_list *varlist, t_word *node, int i)
{
	char			*num_str;
	long int		num;
	int				len;
	char			*field;
	int				field_width;

	num = va_arg(*varlist, long int);
	num_str = data_maker_pointer(num, &len, node);
	if (!num_str)
		return (free_node(node));
	field = field_maker_pointer(node, len, &field_width);
	if (!field)
		return (free_node(node));
	len = (int)ft_strlen(num_str);
	if (node->minus_flag)
		ft_memcpy(field, num_str, len);
	else
		ft_memcpy(field + (field_width - len), num_str, len);
	free(num_str);
	g_char_count += field_width;
	write(1, field, field_width);
	free(field);
	return (i + 1);
}
