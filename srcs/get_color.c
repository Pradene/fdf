/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:37:29 by lpradene          #+#    #+#             */
/*   Updated: 2023/02/12 20:38:08 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int32_t	parse_color(char *s, char *base)
{
	int32_t	i;
	int32_t	j;
	int32_t	color;

	i = -1;
	color = 0;
	while (s[i] && s[++i] != 'x')
		;
	while (s[++i] && s[i] != '\n' && s[i] != ' ')
	{
		j = -1;
		while (base[++j])
		{
			if (s[i] == base[j])
				break ;
		}
		color = color * strlen(base) + j;
	}
	return (color);
}

int32_t	get_color(char *s)
{
	int32_t	i;

	i = 0;
	while (s[i] && s[i] != ' ' && s[i] != '\n')
	{
		if (s[i] == ',')
			return (parse_color(&s[i + 1], "0123456789ABCDEF"));
		++i;
	}
	return (-1);
}
