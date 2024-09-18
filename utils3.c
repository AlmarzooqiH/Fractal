/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 23:50:11 by hamad             #+#    #+#             */
/*   Updated: 2024/09/18 17:53:11 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	exit_prog(t_prog *p, char *reason, int status)
{
	if (!reason || reason == NULL)
	{
		mlx_destroy_window(p->mlx, p->win);
		exit(status);
	}
	mlx_destroy_window(p->mlx, p->win);
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

void	check_c(t_prog *p, int ac, char **av)
{
	int	i;
	int	j;

	if (ac == 3)
		exit_prog(p, JULIA_WRONG_FORMAT, 1);
	i = 2;
	if (!av[i] ||!av[i][0] || av[i][0] == '\0')
		exit_prog(p, JULIA_WRONG_FORMAT, 1);
	j = 0;
	while (av[i][j] != '\0')
	{
		if (ft_isalpha(av[i][j] || ft_isspace(av[i][j])))
			exit_prog(p, JULIA_WRONG_FORMAT, 1);
		j++;
	}
	i++;
	j = 0;
	while (av[i][j] != '\0')
	{
		if (av[i][j] == 'i')
			break ;
		if (ft_isalpha(av[i][j] || ft_isspace(av[i][j])))
			exit_prog(p, JULIA_WRONG_FORMAT, 1);
		j++;
	}
}
