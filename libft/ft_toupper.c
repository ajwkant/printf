/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_toupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: akant <akant@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/08 17:12:39 by akant         #+#    #+#                 */
/*   Updated: 2020/11/19 14:58:31 by alexanderka   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_toupper(int c)
{
	if (97 <= c && c <= 122)
		c -= 32;
	return (c);
}
