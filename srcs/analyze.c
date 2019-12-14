/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobert- <srobert-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 22:34:33 by david             #+#    #+#             */
/*   Updated: 2019/12/14 18:22:38 by srobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

// void ignore_flags(t_flags *flags, int len)
// {
// 	int tmp_width;
// 	int tmp_precision;

// 	if (flags->minus)
// 		flags->zero = 0;
// 	tmp_width = (flags->width > flags->precision) ? flags->width - flags->precision : 0;
// 	tmp_precision = (flags->precision > len) ? flags->precision - len : 0;
// 	// if

// }

void	analyze_digit(t_flags flags, int arg)
{
	char	*buff;
	char	*num;
	int		len;

	len = num_len(arg);
	num = ft_itoa(arg);
	// ignore_flags(&flags, len);
	ft_putnbr(arg);
	debug_flags(flags);
}