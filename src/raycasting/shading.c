/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramusho <eramusho@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 17:51:16 by eramusho          #+#    #+#             */
/*   Updated: 2023/12/12 14:36:01 by eramusho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

static unsigned int	adjust_pixel_cord(t_img *img, int x, int y, double wall_h8)
{
	unsigned int	color;

	y = ((y - (((WIN_HEIGHT - wall_h8) / 2))) * img->height) / wall_h8;
	color = img->addr[y * (img->line_length / 4) + x];
	return (color);
}

unsigned int	apply_brightness(unsigned int color, double wall_height)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
	unsigned int	brightness;

	r = (color & 0xFF0000) >> 16;
	g = (color & 0xFF00) >> 8;
	b = (color & 0xFF);
	brightness = 255 * wall_height / WIN_HEIGHT;
	r = r * brightness / 255;
	g = g * brightness / 255;
	b = b * brightness / 255;
	if (r > (color & 0xFF0000) >> 16)
		r = (color & 0xFF0000) >> 16;
	if (g > (color & 0xFF00) >> 8)
		g = (color & 0xFF00) >> 8;
	if (b > (color & 0xFF))
		b = color & 0xFF;
	return (r << 16 | g << 8 | b);
}

unsigned int	shading_effect(t_img *img, int x, int y, double wall_height)
{
	unsigned int	color;
	unsigned int	shaded_color;

	color = adjust_pixel_cord(img, x, y, wall_height);
	shaded_color = apply_brightness(color, wall_height);
	return (shaded_color);
}
