/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   convert_hex.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/29 17:11:27 by akant         #+#    #+#                 */
/*   Updated: 2021/02/10 12:13:10 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		digit_counter_hex(int num)
{
	int count;

	count = 0;
	if (num == 0)
		return (1);
	if (num < 0)
		count++;
	while (num)
	{
		num /= 16;
		count++;
	}
	return (count);
}

char	*data_maker_hex(t_word *node, unsigned int num, int len, int caseint)
{
	char	*num_str;

	if (node->precision_bool && node->dot_flag < 0)
		node->precision_bool = 0;
	if (num == 0 && ((node->precision_bool == 1 && node->dot_flag == 0)
		|| (node->precision_bool == 2)))
		return (ft_strdup(""));
	num_str = hex_itoa(num, caseint);
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

int		hex_convert(va_list *varlist, t_word *node, int caseint, int i)
{
	char			*num_str;
	unsigned int	num;
	int				len;
	char			*field;
	int				field_width;

	num = va_arg(*varlist, int);
	len = (int)ft_strlen(hex_itoa(num, caseint));
	num_str = data_maker_hex(node, num, len, caseint);
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
