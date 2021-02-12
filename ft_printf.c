/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/19 15:25:47 by akant         #+#    #+#                 */
/*   Updated: 2021/02/12 08:29:59 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		g_char_count;

int		ft_printf(const char *string, ...)
{
	va_list	varlist;
	int		i;

	g_char_count = 0;
	va_start(varlist, string);
	i = 0;
	while (i >= 0 && string[i])
	{
		if (string[i] == '%')
			i = arg_parser((char *)string, i, &varlist);
		else
			i = print_chars((char *)string + i, i);
	}
	va_end(varlist);
	if (i == -1)
		return (-1);
	return (g_char_count);
}

t_word	*node_init(void)
{
	t_word	*new_node;

	new_node = malloc(sizeof(t_word));
	if (!new_node)
		return (NULL);
	new_node->minus_flag = 0;
	new_node->zero_flag = 0;
	new_node->precision_bool = 0;
	new_node->dot_flag = 0;
	new_node->width = 0;
	return (new_node);
}

int		is_specifier(t_word *node, char c, va_list *varlist, int i)
{
	if (!in_set(c, "cspdiuxX%%"))
		return (-1);
	if (c == 'c')
		return (char_convert(varlist, node, i));
	else if (c == 's')
		return (string_convert(varlist, node, i));
	if (c == 'p')
		return (pointer_convert(varlist, node, i));
	else if (c == 'd' || c == 'i')
		return (int_convert(varlist, node, i));
	else if (c == 'u')
		return (int_convert_u(varlist, node, i));
	else if (c == 'x')
		return (hex_convert(varlist, node, 0, i));
	else if (c == 'X')
		return (hex_convert(varlist, node, 16, i));
	else if (c == '%')
		return (perc_convert(node, i));
	free(node);
	return (-1);
}

int		width_parser(t_word *node, char *string, int i)
{
	node->width = ft_atoi((const char *)(string + i));
	if (node->width < 0)
	{
		node->width *= -1;
		node->minus_flag = 1;
	}
	while (ft_isdigit(string[i]))
		i++;
	return (i);
}

int		arg_parser(char *string, int i, va_list *varlist)
{
	t_word	*new_node;

	new_node = node_init();
	if (!new_node)
		return (-1);
	i++;
	while (in_set(string[i], "-0"))
		i = flags_parser(new_node, string, i, varlist);
	if (ft_isdigit(string[i]))
		i = width_parser(new_node, string, i);
	while (in_set(string[i], ".*"))
		i = flags_parser(new_node, string, i, varlist);
	return (is_specifier(new_node, string[i], varlist, i));
}
