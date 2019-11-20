/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hben-yah <hben-yah@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 17:58:50 by hben-yah          #+#    #+#             */
/*   Updated: 2019/05/04 10:47:39 by hben-yah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>
# include <stdint.h>
# include <stddef.h>

# define CONVERTERS		"diDoOuUxXcCsSpbnqQkmr"
# define NUMERICS		"diDoOuUxXpb"
# define LONG_NUMERICS	"DOU"
# define LENGTHS		"hhlljtz"
# define FLAGS			"0+- #'"

# define ERROR_MESSAGE "Error"

typedef struct	s_formatter
{
	char	length;
	char	flags;
	int		width;
	int		precision;
	int		pos;
	char	converter;
	int		index;
	int		prev_len;
}				t_formatter;

typedef struct	s_conversion
{
	char	pad;
	size_t	beg;
	size_t	end;
	int		len;
}				t_conversion;

typedef struct	s_arglist
{
	va_list	begin;
	va_list	natural;
	va_list	selected;
}				t_arglist;

typedef struct	s_date
{
	long	year;
	long	month;
	long	day;
	long	hour;
	long	min;
	long	sec;
}				t_date;

#endif
