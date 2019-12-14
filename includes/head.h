/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobert- <srobert-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 05:25:45 by david             #+#    #+#             */
/*   Updated: 2019/12/13 21:11:43 by srobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include <stdarg.h>
#include "../libft/libft.h"


typedef struct	s_flags
{
	int			h;
	int			hh;
	int			l;
	int			ll;
	int			hash;
	int			zero;
	int			minus;
	int			plus;
	int			space;
	int			width;
	int			precision;
	int			dot;
}				t_flags;

typedef struct	s_snuff
{
	size_t		byte_size;
	va_list		ap;
	const char	*format;
}				t_snuff;

int ft_printf(const char *format, ...);
void parse(t_snuff *snuff);
t_flags init_flag(void);
int num_len(int number);
void debug_flags(t_flags flags);
void	analyze_digit(t_flags flags, int arg);
int find_letter(const char *str, char c);