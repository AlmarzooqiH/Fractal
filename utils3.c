/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 23:50:11 by hamad             #+#    #+#             */
/*   Updated: 2024/09/21 19:49:31 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	exit_prog(t_prog *p, char *reason, int status)
{
	if (p->img)
		mlx_destroy_image(p->mlx, p->img);
	if (p->win)
		mlx_destroy_window(p->mlx, p->win);
	if (p->mlx)
		free(p->mlx);
	if (p->c)
		free(p->c);
	if (p->zn)
		free(p->zn);
	if (reason)
		ft_printf("%s", reason);
	free(p);
	exit(status);
}

void	reset_fractal(t_prog *p)
{
	if (p->fractal == 'j')
	{
		p->cycles = 50;
		p->zoom = 1.0;
		p->move_x = 0;
		p->move_y = 0;
		p->zoom_x = 0;
		p->zoom_y = 0;
		init_complex(p->zn, 0.0, 0.0);
	}
	else
	{
		p->cycles = 50;
		p->zoom = 1.0;
		p->move_x = 0;
		p->move_y = 0;
		p->zoom_x = 0;
		p->zoom_y = 0;
		init_complex(p->c, 0.0, 0.0);
		init_complex(p->zn, 0.0, 0.0);
	}
}

//This will check if the current point has have escaped to infinity.
int	has_escaped(t_complex *zn)
{
	return (zn->a * zn->a + zn->b * zn->b > 4);
}

void	change_or_reset_fractal(int keycode, t_prog *p)
{
	reset_fractal(p);
	if (keycode == M)
		p->fractal = 'm';
	else if (keycode == B)
		p->fractal = 'b';
	else if (keycode == T)
		p->fractal = 't';
}
