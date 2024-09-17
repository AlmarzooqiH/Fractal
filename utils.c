/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:44:28 by hamad             #+#    #+#             */
/*   Updated: 2024/09/17 23:00:23 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_args(int ac, char **av)
{
	// if (ac == 1 || ac > 4 || !av || av[1][0] == '\0')
	// {
	// 	ft_printf("%s", INPUT_ERROR);
	// 	exit(1);
	// }
	//Finish parsing later.
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
	fractal(p);
	return (0);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	t_prog	*p;
	double	mouse_re;
	double	mouse_im;

	p = (t_prog *)param;
	mouse_re = p->zoom_x + (x - WIDTH / 2) * (p->range_x / (double)WIDTH) / p->zoom;
	mouse_im = p->zoom_y + (y - HEIGHT / 2) * (p->range_y / (double)HEIGHT) / p->zoom;
	if (button == ZOOMIN)
		p->zoom *= 1.5;
	else if (button == ZOOMOUT)
		p->zoom /= 1.5;
	p->zoom_x = mouse_re - (x - WIDTH / 2) * (p->range_x / (double)WIDTH) / p->zoom;
	p->zoom_y = mouse_im - (y - HEIGHT / 2) * (p->range_y / (double)HEIGHT) / p->zoom;
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

	i = 2;
	p->c.a = ft_atod(av[i]);
	p->c.b = ft_atod(av[i + 1]);
}