/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:08:59 by hamad             #+#    #+#             */
/*   Updated: 2024/09/21 12:58:16 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_fractal(t_prog *p, int ac, char **av)
{
	char	*fractal;

	fractal = ft_substr(av[1], ft_skipspace(av[1]), ft_strlen(av[1]));
	if (!fractal)
		exit_prog(p, WF, 1);
	if (ft_strcmp(fractal, MANDELBROT))
		p->fractal = 'm';
	else if (ft_strcmp(fractal, JULIA))
		p->fractal = 'j';
	else if (ft_strcmp(fractal, BURINGSHIP))
		p->fractal = 'b';
	else if (ft_strcmp(fractal, TRICON))
		p->fractal = 't';
	else
		exit_prog(p, WF, 1);
	free(fractal);
}

/*
	@brief	Draw on image
	@param	p	The program data.
*/
void	doi(t_prog *p)
{
	int	offset;

	offset = (p->y * p->sl) + (p->x * (p->bpp / 8));
	*(int *)(p->imgd + offset) = p->fc;
}

double	getx(t_prog *p)
{
	return ((p->zoom_x + (p->x - WIDTH / 2) * (p->range_x / (double)WIDTH)
			/ p->zoom) + p->move_x);
}

double	gety(t_prog *p)
{
	return ((p->zoom_y + (p->y - HEIGHT / 2) * (p->range_y / (double)HEIGHT)
			/ p->zoom) + p->move_y);
}

void	change_color(int keycode, t_prog *p)
{
	if (keycode == ONE)
	{
		p->fpc = BLACK;
		p->fsc = ROYALE_BLUE;
	}
	else if (keycode == TWO)
	{
		p->fpc = LIGHT_SALMON;
		p->fsc = LIGHT_CORAL;
	}
	else if (keycode == THREE)
	{
		p->fpc = BLACK;
		p->fsc = LIGHT_PURPLE;
	}
	else if (keycode == FOUR)
	{
		p->fpc = DARK_GREEN;
		p->fsc = GOLD;
	}
	else if (keycode == FIVE)
	{
		p->fpc = CRIMSON;
		p->fsc = GOLD;
	}
}
