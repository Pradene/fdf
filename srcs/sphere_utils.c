/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpradene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 09:36:53 by lpradene          #+#    #+#             */
/*   Updated: 2023/02/26 09:36:54 by lpradene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	get_x(t_point p, float radian)
{
	t_point	point;

	point.x = p.x * 1 + p.y * 0 + p.z * 0;
	point.y = p.x * 0 + p.y * cos(radian) + p.z * sin(radian);
	point.z = p.x * 0 + p.y * -sin(radian) + p.z * cos(radian);
	return (point);
}

t_point	get_y(t_point p, float radian)
{
	t_point	point;

	point.x = p.x * cos(radian) + p.y * 0 + p.z * sin(radian);
	point.y = p.x * 0 + p.y * 1 + p.z * 0;
	point.z = p.x * -sin(radian) + p.y * 0 + p.z * cos(radian);
	return (point);
}

t_point	get_z(t_point p, float radian)
{
	t_point	point;

	point.x = p.x * cos(radian) + p.y * -sin(radian) + p.z * 0;
	point.y = p.x * sin(radian) + p.y * cos(radian) + p.z * 0;
	point.z = p.x * 0 + p.y * 0 + p.z * 1;
	return (point);
}
