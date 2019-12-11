/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 06:55:31 by david             #+#    #+#             */
/*   Updated: 2019/12/12 01:10:46 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

int	check_flags(const char *format, t_flags *flags)
{
	int id;
	int check_id;
	int tmp;
	id = 0;
	check_id = id;
	while (format[id] != '\0' && (tmp = find_letter("diouxXcsp", format[id])) == 0)
	{
		if (format[id] == '0')
		{
			flags->zero = 1;
			id++;
		}
		if (format[id] == ' ')
		{
			flags->space = 1;
			id++;
		}
		if (format[id] == '+')
		{
			flags->plus = 1;
			id++;
		}
		if (format[id] == '-')
		{
			flags->minus = 1;
			id++;
		}
		if (format[id] == 'h')
		{
			id++;
			if (format[id] != '\0' && format[id] == 'h')
			{
				flags->hh = 1;
				id++;
			}
			else
				flags->h = 1;
		}
		if (format[id] == 'l')
		{
			id++;
			if (format[id] != '\0' && format[id] == 'l')
			{
				flags->ll = 1;
				id++;
			}
			else
				flags->l = 1;
		}
		if (format[id] == '#')
		{
			flags->hash = 1;
			id++;
		}
		if (ft_isdigit(format[id]) && format[id] != '0')
		{
			flags->width = ft_atoi(&format[id]);
			id += num_len(flags->width);
		}
		if (format[id] == '.')
		{
			flags->dot += 1;
			id++;
			if (format[id] != '\0' && flags->dot == 1)
			{
				flags->f_num = ft_atoi(&format[id]);
				id += num_len(flags->f_num);
			}
			else if (flags->dot > 1)
				id += num_len(ft_atoi(&format[id]));
		}
		if (check_id == id)
		{
			id++;
			check_id = id;
		}
		else
			check_id = id;
	}
	return (id);
}

int parse_conversion(const char *format, t_snuff *snuff)
{
	t_flags flags;
	int		id = 0;
	flags = init_flag();

	id += check_flags(format, &flags);
	if (&format[id])
	{
		if (format[id] == 'd')
			analyze_digit(flags, va_arg(snuff->ap, int));
		// else if (format[id] == 'i')
		// 	analyze_idigit(flags, va_arg(snuff->ap, int));
		// else if (format[id] == 'o')
		// 	analyze_octet(flags, va_arg(snuff->ap, int));
	}
	return (id + 1);
}

void parse(t_snuff *snuff)
{
	int diff;
	int id;

	diff = 0;
	id = 0;
	while (snuff->format[id] != '\0')
	{
		while (snuff->format[id] != '%' && snuff->format[id])
		{
			write(1, &snuff->format[id], 1);
			id++;
			snuff->byte_size++;
		}
		if (snuff->format[id] == '%')
			id += parse_conversion(&snuff->format[id + 1], snuff);
	}

}