/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamalmar <hamalmar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:44:28 by hamad             #+#    #+#             */
/*   Updated: 2024/09/21 11:25:43 by hamalmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_args(int ac, char **av)
{
	if (ac == 1 || ac > 4 || !av || av[1][0] == '\0')
	{
		ft_printf("%s%s", INPUT_ERROR, CF);
		exit(1);
	}
}

int	key_hook(int keycode, void *param)
{
	t_prog	*p;

	p = (t_prog *) param;
	if (keycode == ESC)
		close_program(param);
	else if (keycode == LEFT)
		p->move_x -= 1.5 / p->zoom;
	else if (keycode == UP)
		p->move_y -= 1.5 / p->zoom;
	else if (keycode == RIGHT)
		p->move_x += 1.5 / p->zoom;
	else if (keycode == DOWN)
		p->move_y += 1.5 / p->zoom;
	else if (keycode == MINUS)
		p->cycles -= 10;
	else if (keycode == PLUS)
		p->cycles += 10;
	else if (keycode == ONE || keycode == TWO || keycode == THREE
		|| keycode == FOUR || keycode == FIVE)
		change_color(keycode, p);
	else if (keycode == R || keycode == M || keycode == B || keycode == T)
		change_or_reset_fractal(keycode, p);
	fractal(p);
	return (0);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	t_prog	*p;
	double	mre;
	double	mie;

	p = (t_prog *)param;
	mre = p->zoom_x + (x - WIDTH / 2) * (p->range_x / (double)WIDTH)
		/ p->zoom;
	mie = p->zoom_y + (y - HEIGHT / 2) * (p->range_y / (double)HEIGHT)
		/ p->zoom;
	if (button == ZOOMIN)
		p->zoom *= 1.5;
	else if (button == ZOOMOUT)
		p->zoom /= 1.5;
	p->zoom_x = mre - (x - WIDTH / 2) * (p->range_x / (double)WIDTH)
		/ p->zoom;
	p->zoom_y = mie - (y - HEIGHT / 2) * (p->range_y / (double)HEIGHT)
		/ p->zoom;
	fractal(p);
	return (1);
}

void	hook(t_prog *p)
{
	mlx_key_hook(p->win, key_hook, (void *)p);
	mlx_hook(p->win, 17, 0, close_program, (void *)p);
	mlx_mouse_hook(p->win, mouse_hook, (void *)p);
}

void	get_c(t_prog *p, int ac, char **av)
{
	if (ac == 4)
	{
		check_real(p, ac, av);
		check_imaginary(p, ac, av);
		p->c->a = ft_atod(av[2]);
		p->c->b = ft_atod(av[3]);
		if (p->c->a < RNX || p->c->a > RPX || p->c->b < INY || p->c->b > IPY)
			exit_prog(p, JULIA_WRONG_FORMAT, 1);
	}
	else
		exit_prog(p, JULIA_WRONG_FORMAT, 1);
}
