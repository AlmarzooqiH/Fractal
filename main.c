/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 18:30:15 by h                 #+#    #+#             */
/*   Updated: 2024/09/19 22:03:56 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_program(void *param)
{
	t_prog	*p;

	p = (t_prog *) param;
	exit_prog(p, NULL, 0);
}

void	init_2(t_prog *p)
{
	p->cycles = 50;
	p->fc = BLACK;
	p->fpc = BLACK;
	p->fsc = ROYALE_BLUE;
	p->x = 0;
	p->y = 0;
	p->zoom = 1;
	p->move_x = 0;
	p->move_y = 0;
	p->range_x = 0.0 + (RPX - RNX);
	p->range_y = 0.0 + (IPY - INY);
	init_complex(p->c, 0.0, 0.0);
	init_complex(p->zn, 0.0, 0.0);
}

void	init(t_prog *p)
{
	p->mlx = mlx_init();
	if (!p->mlx)
		exit_prog(p, SOMETHING_WENT_WRONG, 1);
	p->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, FRACTOL);
	if (!p->win)
		exit_prog(p, SOMETHING_WENT_WRONG, 1);
	p->img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	if (!p->img)
		exit_prog(p, SOMETHING_WENT_WRONG, 1);
	p->imgd = mlx_get_data_addr(p->img, &p->bpp, &p->sl, &p->edn);
	if (!p->imgd)
		exit_prog(p, SOMETHING_WENT_WRONG, 1);
	p->c = (t_complex *)malloc(sizeof(t_complex));
	p->zn = (t_complex *)malloc(sizeof(t_complex));
	if (!p->c || !p->zn)
		exit_prog(p, SOMETHING_WENT_WRONG, 1);
	init_2(p);
}

int	main(int ac, char **av)
{
	t_prog	*p;

	check_args(ac, av);
	p = (t_prog *)malloc(sizeof(t_prog));
	if (!p)
		exit_prog(p, SOMETHING_WENT_WRONG, 1);
	init(p);
	hook(p);
	check_fractal(p, ac, av);
	if (p->fractal == 'j')
		get_c(p, ac, av);
	fractal(p);
	mlx_loop(p->mlx);
	return (0);
}
