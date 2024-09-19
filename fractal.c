/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 13:45:52 by h                 #+#    #+#             */
/*   Updated: 2024/09/19 22:27:17 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
/*
    @brief	This function will draw the mandelbrot fractal.

	@param	p	The p pointer holds all of the program data that will be used.
    @var    	ipp Iteration per pixel.
*/
void	mandelbrot(t_prog *p)
{
	int	ipp;

	init_complex(p->c, getx(p), gety(p));
	init_complex(p->zn, 0, 0);
	ipp = 0;
	while (ipp < p->cycles)
	{
		square_complex(p->zn);
		add_complex(p->zn, p->c);
		if (has_escaped(p->zn))
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

	init_complex(p->zn, getx(p), gety(p));
	ipp = 0;
	while (ipp < p->cycles)
	{
		square_complex(p->zn);
		add_complex(p->zn, p->c);
		if (has_escaped(p->zn))
			break ;
		ipp++;
	}
	if (ipp == p->cycles)
		p->fc = p->fpc;
	else
		p->fc = p->fpc + (ipp * p->fsc);
	doi(p);
}

void	burningship(t_prog *p)
{
	int		ipp;
	double	x;
	double	y;

	x = getx(p);
	y = gety(p);
	init_complex(p->c, 0, 0);
	init_complex(p->zn, x, y);
	ipp = 0;
	while (ipp < p->cycles)
	{
		square_complex(p->zn);
		p->zn->a += x;
		p->zn->b = fabs(p->zn->b) + y;
		add_complex(p->zn, p->c);
		if (has_escaped(p->zn))
			break ;
		ipp++;
	}
	if (ipp == p->cycles)
		p->fc = p->fpc;
	else
		p->fc = p->fpc + (ipp * p->fsc);
	doi(p);
}

void	tricon(t_prog *p)
{
	int	ipp;

	init_complex(p->c, getx(p), gety(p));
	init_complex(p->zn, 0, 0);
	ipp = 0;
	while (ipp < p->cycles)
	{
		square_complex(p->zn);
		p->zn->b = -p->zn->b;
		add_complex(p->zn, p->c);
		if (has_escaped(p->zn))
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
	while (p->y < HEIGHT)
	{
		p->x = 0;
		while (p->x < WIDTH)
		{
			if (p->fractal == 'm')
				mandelbrot(p);
			else if (p->fractal == 'j')
				julia(p);
			else if (p->fractal == 'b')
				burningship(p);
			else if (p->fractal == 't')
				tricon(p);
			p->x++;
		}
		p->y++;
	}
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
}
