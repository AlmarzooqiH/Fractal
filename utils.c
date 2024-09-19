/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:44:28 by hamad             #+#    #+#             */
/*   Updated: 2024/09/19 15:38:03 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_args(int ac, char **av)
{
	if (ac == 1 || ac > 4 || !av || av[1][0] == '\0')
	{
		ft_printf("%s", INPUT_ERROR);
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
	double	mouse_re;
	double	mouse_im;

	p = (t_prog *)param;
	mouse_re = p->zoom_x + (x - WIDTH / 2) * (p->range_x / (double)WIDTH)
		/ p->zoom;
	mouse_im = p->zoom_y + (y - HEIGHT / 2) * (p->range_y / (double)HEIGHT)
		/ p->zoom;
	if (button == ZOOMIN)
		p->zoom *= 1.5;
	else if (button == ZOOMOUT)
		p->zoom /= 1.5;
	p->zoom_x = mouse_re - (x - WIDTH / 2) * (p->range_x / (double)WIDTH)
		/ p->zoom;
	p->zoom_y = mouse_im - (y - HEIGHT / 2) * (p->range_y / (double)HEIGHT)
		/ p->zoom;
	fractal(p);
}

void	hook(t_prog *p)
{
	mlx_key_hook(p->win, key_hook, (void *)p);
	mlx_hook(p->win, 17, 0, close_program, (void *)p);
	mlx_mouse_hook(p->win, mouse_hook, (void *)p);
}

void	get_c(t_prog *p, int ac, char **av)
{
	int	i;

	if (ac == 4)
	{
		check_real(p, ac, av);
		check_imaginary(p, ac, av);
		i = 2;
		p->c.a = ft_atod(av[i]);
		p->c.b = ft_atod(av[i + 1]);
		if (p->c.a < RNX || p->c.a > RPX || p->c.b < INY || p->c.b > IPY)
			exit_prog(p, JULIA_WRONG_FORMAT, 1);
	}
	else
		exit_prog(p, JULIA_WRONG_FORMAT, 1);
}
