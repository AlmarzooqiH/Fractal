/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:30:15 by h                 #+#    #+#             */
/*   Updated: 2024/09/17 23:59:37 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_program(void *param)
{
	t_prog	*p;

	p = (t_prog *) param;
	mlx_destroy_window(p->mlx, p->win);
	exit(0);
}

void	init_2(t_prog *p)
{
	p->fc = BLACK;
	p->fpc = BLACK;
	p->fsc = ROYALE_BLUE;
	p->zoom = 1;
	p->move_x = 0;
	p->move_y = 0;
	p->range_x = 0.0 + (RPX - RNX);
	p->range_y = 0.0 + (IPY - INY);
}

void	init(t_prog *p)
{
	p->mlx = mlx_init();
	if (!p->mlx)
	{
		ft_printf("%s\n", SOMETHING_WENT_WRONG);
		exit(1);
	}
	p->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, FRACTOL);
	if (!p->win)
	{
		ft_printf("%s\n", SOMETHING_WENT_WRONG);
		exit(1);
	}
	p->img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	if (!p->img)
	{
		mlx_destroy_window(p->mlx, p->win);
		ft_printf("%s\n", SOMETHING_WENT_WRONG);
		exit(1);
	}
	p->imgd = mlx_get_data_addr(p->img, &p->bpp, &p->sl, &p->edn);
	p->cycles = 50;
	init_2(p);
}

int	main(int ac, char **av)
{
	t_prog	p;

	check_args(ac, av);
	init(&p);
	hook(&p);
	check_fractal(&p, ac, av);
	if (p.fractal == 'j')
		get_c(&p, ac, av);
	fractal(&p);
	mlx_loop(p.mlx);
	return (0);
}
