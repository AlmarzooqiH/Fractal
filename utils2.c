/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:08:59 by hamad             #+#    #+#             */
/*   Updated: 2024/09/19 18:22:16 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_fractal(t_prog *p, int ac, char **av)
{
	if (ft_strcmp(av[1], MANDELBROT))
		p->fractal = 'm';
	else if (ft_strcmp(av[1], JULIA))
		p->fractal = 'j';
	else if (ft_strcmp(av[1], BURINGSHIP))
		p->fractal = 'b';
	else if (ft_strcmp(av[1], TRICON))
		p->fractal = 't';
	else
	{
		ft_printf("%s%s", WRONG_FRACTALS1, WRONG_FRACTALS2);
		mlx_destroy_image(p->mlx, p->img);
		mlx_destroy_window(p->mlx, p->win);
		exit(1);
	}
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
