/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srobert- <srobert-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 22:34:33 by david             #+#    #+#             */
/*   Updated: 2019/12/14 18:20:46 by srobert-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

void ignore_flags(t_flags *flags, int len)
{
	int tmp_width;
	int tmp_f_num;

	if (flags->minus)
		flags->zero = 0;
	tmp_width = (flags->width > flags->f_num) ? flags->width - flags->f_num : 0;
	tmp_f_num = (flags->f_num > len) ? flags->f_num - len : 0;
	// if

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
	debug_flags(flags);
}