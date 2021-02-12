/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_unsigned.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/28 15:23:27 by akant         #+#    #+#                 */
/*   Updated: 2021/02/10 12:10:47 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		digit_counter_u(unsigned int num)
{
	int count;

	count = 0;
	if (num == 0)
		return (1);
	while (num)
	{
		num /= 10;
		count++;
	}
	return (count);
}

char	*field_maker_u(t_word *node, int len,
		int *field_width, unsigned int num)
{
	char	*field;
	char	c;

	c = ' ';
	if (node->precision_bool && node->dot_flag < 0)
		node->precision_bool = 0;
	if (node->precision_bool)
		node->zero_flag = 0;
	*field_width = node->width > len ? node->width : len;
	if (node->zero_flag == 1 && !node->minus_flag)
		c = '0';
	if (node->precision_bool)
		*field_width = *field_width > node->dot_flag ?
		*field_width : node->dot_flag;
	if (node->width == 0 && num == 0 && node->precision_bool
		&& node->dot_flag == 0)
		*field_width = 0;
	field = calloc(*field_width + 1, sizeof(char));
	if (!field)
		return (NULL);
	ft_memset(field, c, *field_width);
	return (field);
}

char	*data_maker_u(t_word *node, unsigned int num, int len)
{
	char	*num_str;

	if (num == 0 && ((node->precision_bool == 1 && node->dot_flag == 0)
		|| (node->precision_bool == 2)))
		return (ft_strdup(""));
	num_str = unsigned_itoa(num);
	if (!num_str)
		return (NULL);
	if (node->precision_bool && node->dot_flag > len)
	{
		num_str = zero_padding(num_str, node->dot_flag - len);
		if (!num_str)
			return (NULL);
	}
	return (num_str);
}

int		int_convert_u(va_list *varlist, t_word *node, int i)
{
	char			*num_str;
	unsigned int	num;
	int				len;
	char			*field;
	int				field_width;

	num = va_arg(*varlist, unsigned int);
	len = digit_counter_u(num);
	num_str = data_maker_u(node, num, len);
	if (!num_str)
		return (free_node(node));
	field = field_maker_u(node, len, &field_width, num);
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
