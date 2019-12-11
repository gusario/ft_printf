/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 22:34:33 by david             #+#    #+#             */
/*   Updated: 2019/12/12 01:29:45 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void ignore_flags(t_flags *flags, int len)
{
	if (flags->minus)
		flags->zero = 0;
	if (len > flags->width)
		flags->width = 0;
	
}

void	analyze_digit(t_flags flags, int arg)
{
	char	*buff;
	char	*num;
	int		len;

	len = num_len(arg);
	num = ft_itoa(arg);
	ignore_flags(&flags, len);
	ft_putnbr(arg);
	// debug_flags(flags);
}