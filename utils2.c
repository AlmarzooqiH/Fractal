/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:08:59 by hamad             #+#    #+#             */
/*   Updated: 2024/09/17 22:54:16 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_fractal(t_prog *p, int ac, char **av)
{
	if (ft_strcmp(av[1], MANDELBROT))
		p->fractal = 'm';
	else if (ft_strcmp(av[1], JULIA))
		p->fractal = 'j';
	else
	{
		ft_printf("%s", WRONG_FRACTALS);
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
	int	i;
	int	j;
	int	offset;

	offset = (p->y * p->sl) + (p->x * (p->bpp / 8));
	*(int *)(p->imgd + offset) = p->fc;
}
//Figure out how to zoomin to the mouse pointer.
double	getx(t_prog *p)
{
    return (p->zoom_x + (p->x - WIDTH / 2) * (p->range_x / (double)WIDTH) / p->zoom) + p->move_x;
}

double	gety(t_prog *p)
{
    return (p->zoom_y + (p->y - HEIGHT / 2) * (p->range_y / (double)HEIGHT) / p->zoom) + p->move_y;
}
