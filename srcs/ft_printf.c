/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 05:25:20 by david             #+#    #+#             */
/*   Updated: 2019/12/11 22:58:36 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"


int		ft_printf(const char *format, ...)
{
	t_snuff	snuff;

	va_start(snuff.ap, format);
	snuff.byte_size = 0;
	snuff.format = (char*)format;
	if (format == NULL)
		return (-1);
	parse(&snuff);
	va_end(snuff.ap);
	return (snuff.byte_size);
}