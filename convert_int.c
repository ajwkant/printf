/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_int.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/25 15:45:47 by akant         #+#    #+#                 */
/*   Updated: 2021/02/10 12:10:53 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		digit_counter(int num)
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

char	*field_maker(t_word *node, int len, int *field_width, int num)
{
	char	*field;
	char	c;
	int		negative;

	if (node->precision_bool)
		node->zero_flag = 0;
	negative = 0;
	negative = num < 0 ? 1 : 0;
	c = ' ';
	*field_width = node->width > len + negative ? node->width : len + negative;
	if (node->zero_flag == 1 && !node->minus_flag)
		c = '0';
	if (node->precision_bool)
		*field_width = *field_width > node->dot_flag + negative ?
		*field_width : node->dot_flag + negative;
	if (node->width == 0 && num == 0 &&
		node->precision_bool && node->dot_flag == 0)
		*field_width = 0;
	field = calloc(*field_width + 1, sizeof(char));
	if (!field)
		return (NULL);
	ft_memset(field, c, *field_width);
	return (field);
}

char	*data_maker(t_word *node, int num, int *len)
{
	char	*num_str;
	char	*temp;

	if (node->precision_bool && node->dot_flag < 0)
		node->precision_bool = 0;
	*len = digit_counter(num);
	if (num == 0 && ((node->precision_bool == 1 && node->dot_flag == 0)
		|| (node->precision_bool == 2)))
		return (ft_strdup(""));
	num_str = ft_itoa(num);
	if (!num_str)
		return (NULL);
	if (num < 0)
	{
		temp = ft_strdup(num_str + 1);
		free(num_str);
		if (!temp)
			return (NULL);
		num_str = temp;
	}
	if (node->precision_bool && node->dot_flag > *len)
		num_str = zero_padding(num_str, node->dot_flag - *len);
	return (num_str);
}

void	neg_num(t_word *node, char *field, int len, int field_width)
{
	if (node->minus_flag || node->zero_flag)
		field[0] = '-';
	else
		field[field_width - len - 1] = '-';
}

int		int_convert(va_list *varlist, t_word *node, int i)
{
	char	*num_str;
	int		num;
	int		len;
	char	*field;
	int		field_width;

	num = va_arg(*varlist, int);
	num_str = data_maker(node, num, &len);
	if (!num_str)
		return (free_node(node));
	field = field_maker(node, len, &field_width, num);
	if (!field)
		return (free_node(node));
	len = (int)ft_strlen(num_str);
	if (node->minus_flag)
		ft_memcpy(field + (num < 0), num_str, len);
	else
		ft_memcpy(field + field_width - len, num_str, len);
	if (num < 0)
		neg_num(node, field, len, field_width);
	free(num_str);
	g_char_count += field_width;
	write(1, field, field_width);
	free(field);
	return (i + 1);
}
