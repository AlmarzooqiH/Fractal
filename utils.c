/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:44:28 by hamad             #+#    #+#             */
/*   Updated: 2024/09/15 17:49:10 by hamad            ###   ########.fr       */
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
		close_window(param);
	else if (keycode == LEFT)
		ft_printf("Left arrow was pressed!\n");
	else if (keycode == UP)
		ft_printf("up arrow was pressed!\n");
	else if (keycode == RIGHT)
		ft_printf("Right arrow was pressed!\n");
	else if (keycode == DOWN)
		ft_printf("Down arrow was pressed!\n");
	else if (keycode == MINUS)
		p->cycles -= 10;
	else if (keycode == PLUS)
		p->cycles += 10;
	fractal(p);
	return (0);
}

int	mouse_hook(int button, int x, int y, void *param)
{
	t_prog *p;

	p = (t_prog *)param;
	p->zoom_x = x;
	p->zoom_y = y;
	if (button == ZOOMIN)
		p->zoom *= 1.5;

	else if (button == ZOOMOUT)
		p->zoom /= 1.5;
	fractal(p);
		
}

void	hook(t_prog *p)
{
	mlx_key_hook(p->win, key_hook, (void *)p);
	mlx_hook(p->win, 17, 0, close_window, (void *)p);
	mlx_mouse_hook(p->win, mouse_hook, (void *)p);
}

void	get_c(t_prog *p, int ac, char **av)
{
	int	i;

	i = 2;
	p->c.a = ft_atod(av[i]);
	p->c.b = ft_atod(av[i + 1]);
}