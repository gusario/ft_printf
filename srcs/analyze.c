/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobert- <srobert-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 22:34:33 by david             #+#    #+#             */
/*   Updated: 2019/12/15 20:33:26 by srobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void	recalc_flags(t_flags *flags, int len)
{
	if (flags->minus)
		flags->zero = 0;
	flags->precision = (flags->precision > len) ? flags->precision - len : 0;
	flags->width = (flags->width > len + flags->precision) ? flags->width - \
	(len + flags->precision) : 0;
	if (flags->plus)
		flags->width = flags->width > 0 ? flags->width-- : 0;
}

void	analyze_digit(t_flags flags, int arg)
{
	int	len;
	int	i;

	i = 0;
	len = num_len(arg);
	recalc_flags(&flags, len);
	
	ft_putnbr(arg);
	debug_flags(flags);
}