/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 17:38:39 by dpylypen          #+#    #+#             */
/*   Updated: 2017/03/02 17:43:50 by dpylypen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main/fdf.h"

int		ft_isspace(int symb)
{
	if (symb == ' ' || symb == '\t')
		return (1);
	return (0);
}

int		get_int(char ch)
{
	int i;

	ch = (char)ft_tolower(ch);
	if (ch > 96)
		i = ch - 97 + 10;
	else
		i = ch - 48;
	if (i > 15 || i < 0)
		return (-1);
	return (i);
}

int		hex_reader(char **str)
{
	int ret_val;

	(*str) += 2;
	ret_val = 0;
	while (!ft_isspace(**str) && **str)
	{
		ret_val *= 16;
		ret_val += get_int(**str);
		(*str)++;
	}
	return (ret_val);
}
