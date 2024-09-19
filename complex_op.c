/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 22:45:01 by h                 #+#    #+#             */
/*   Updated: 2024/09/19 21:54:36 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_complex(t_complex *p, double a, double bi)
{
	p->a = a;
	p->b = bi;
}

/*
	@brief		This function will compute (a + bi)^2
	@param	zn	Complex number
*/
void	square_complex(t_complex *zn)
{
	double	a;
	double	b;

	a = zn->a;
	b = zn->b;
	zn->a = (a * a) - (b * b);
	zn->b = 2 * a * b;
}

/*
	@brief	This function will add two complex numbers to each other.
	@param	zn	Complex number
	@param	c	The constant complex number added in the mandelbrot equation.
*/
void	add_complex(t_complex *zn, t_complex *c)
{
	zn->a += c->a;
	zn->b += c->b;
}
