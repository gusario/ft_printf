/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: david <david@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 06:40:03 by david             #+#    #+#             */
/*   Updated: 2019/12/12 01:13:28 by david            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/head.h"

t_flags init_flag(void)
{
	t_flags flags;

	flags.h = 0;
	flags.hh = 0;
	flags.hash = 0;
	flags.l = 0;
	flags.ll = 0;
	flags.minus = 0;
	flags.plus = 0;
	flags.space = 0;
	flags.zero = 0;
	flags.width = 0;
	flags.dot = 0;
	flags.f_num = 0;
	return (flags);
}

int num_len(int number)
{
	int count;
	long long num;

	count = 0;
	num = number;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		count++;
		num /= 10;
	}
	return (count);
}

void debug_flags(t_flags flags)
{
	printf("\n\ndebug flags:\n");
	printf("h == %d\n", flags.h);
	printf("hh == %d\n", flags.hh);
	printf("# == %d\n", flags.hash);
	printf("l == %d\n", flags.l);
	printf("ll == %d\n", flags.ll);
	printf("- == %d\n", flags.minus);
	printf("+ == %d\n", flags.plus);
	printf("space == %d\n", flags.space);
	printf("0 == %d\n", flags.zero);
	printf("width == %d\n", flags.width);
	printf("dot == %d\n", flags.dot);
	printf("f_num == %d\n\n", flags.f_num);
}

int find_letter(const char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (-1);
		i++;
	}
	return (0);
}