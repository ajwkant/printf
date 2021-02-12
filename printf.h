/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/19 15:25:31 by akant         #+#    #+#                 */
/*   Updated: 2021/02/10 12:36:25 by akant         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>
# include "libft/libft.h"
# define UINT_MAX	0xffffffff

extern int			g_char_count;

typedef struct		s_word
{
	int				minus_flag;
	int				zero_flag;
	int				precision_bool;
	int				dot_flag;
	int				width;
}					t_word;

int					ft_printf(const char *string, ...);
int					print_chars(char *string, int begin_index);
int					arg_parser(char *string, int i, va_list *varlist);
t_word				*node_init(void);
int					in_set(char c, char *set);
int					flags_parser(t_word *node, char *string,
					int i, va_list *varlist);
int					index_increment(char *string, int i);
int					width_parser(t_word *node, char *string, int i);
int					is_specifier(t_word *node, char c, va_list *varlist, int i);

int					char_convert(va_list *varlist, t_word *node, int i);
char				*prefix_maker(t_word *node, int digits);

int					string_convert(va_list *varlist, t_word *node, int i);
char				*field_maker_string(t_word *node,
					int *len, int *field_width);
char				*data_maker_string(t_word *node, char *word, int *len);
int					digit_counter(int num);

int					int_convert(va_list *varlist, t_word *node, int i);
char				*data_maker(t_word *node, int num, int *len);
char				*zero_padding(char const *s1, int n);
char				*field_maker(t_word *node, int len,
					int *field_width, int minus);

int					int_convert_u(va_list *varlist, t_word *node, int i);
char				*data_maker_u(t_word *node, unsigned int num, int len);
char				*field_maker_u(t_word *node, int len, int *field_width,
					unsigned int num);
char				*unsigned_itoa(unsigned int n);
int					digit_counter_u(unsigned int num);

int					hex_convert(va_list *varlist,
					t_word *node, int caseint, int i);
char				*data_maker_hex(t_word *node,
					unsigned int num, int len, int caseint);
char				*hex_itoa(long int n, int caseint);
char				*char_join(char c, char *s2);
int					digit_counter_hex(int num);

int					pointer_convert(va_list *varlist, t_word *node, int i);
char				*data_maker_pointer(long int num, int *len, t_word *node);

int					perc_convert(t_word *node, int i);
int					free_node(t_word *node);

#endif
