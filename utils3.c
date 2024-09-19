/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 23:50:11 by hamad             #+#    #+#             */
/*   Updated: 2024/09/19 18:46:26 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	exit_prog(t_prog *p, char *reason, int status)
{
	ft_bzero((void *)p->imgd, ft_strlen(p->imgd));
	if (p->win)
		mlx_destroy_window(p->mlx, p->win);
	if (p->img)
		mlx_destroy_image(p->mlx, p->img);
	if (!reason || reason == NULL)
		exit(status);
	ft_printf("%s", reason);
	exit(status);
}

void	reset_fractal(t_prog *p)
{
	p->cycles = 50;
	p->fc = BLACK;
	p->fpc = BLACK;
	p->fsc = ROYALE_BLUE;
	p->zoom = 1;
	p->move_x = 0;
	p->move_y = 0;
	p->zoom_x = 0;
	p->zoom_y = 0;
}

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
