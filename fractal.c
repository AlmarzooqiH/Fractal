/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:45:52 by h                 #+#    #+#             */
/*   Updated: 2024/09/17 23:59:14 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	has_escaped(t_complex *zn)
{
	return (zn->a * zn->a + zn->b * zn->b > 4);
}

/*
    @brief	This function will draw the mandelbrot fractal.

	@param	p	The p pointer holds all of the program data that will be used.
    @var    	ipp Iteration per pixel.
*/
void	mandelbrot(t_prog *p)
{
	int	ipp;

	init_complex(&p->c, getx(p), gety(p));
	init_complex(&p->zn, 0, 0);
	ipp = 0;
	while (ipp < p->cycles)
	{
		square_complex(&p->zn);
		add_complex(&p->zn, p->c);
		if (has_escaped(&p->zn))
			break ;
		ipp++;
	}
	if (ipp == p->cycles)
		p->fc = p->fpc;
	else
		p->fc = p->fpc + (ipp * p->fsc);
	doi(p);
}

void	julia(t_prog *p)
{
	int	ipp;

	init_complex(&p->zn, getx(p), gety(p));
	ipp = 0;
	while (ipp < p->cycles)
	{
		square_complex(&p->zn);
		add_complex(&p->zn, p->c);
		if (has_escaped(&p->zn))
			break ;
		ipp++;
	}
	if (ipp == p->cycles)
		p->fc = p->fpc;
	else
		p->fc = p->fpc + (ipp * p->fsc);
	doi(p);
}

void	fractal(t_prog *p)
{
	p->y = 0;
	while (p->y != HEIGHT)
	{
		p->x = 0;
		while (p->x != WIDTH)
		{
			if (p->fractal == 'm')
				mandelbrot(p);
			else if (p->fractal == 'j')
				julia(p);
			p->x++;
		}
		p->y++;
	}
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}
