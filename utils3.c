/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 23:50:11 by hamad             #+#    #+#             */
/*   Updated: 2024/09/18 09:29:27 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	reset_fractal(t_prog *p)
{
	p->fc = BLACK;
	p->fpc = BLACK;
	p->fsc = ROYALE_BLUE;
	p->zoom = 1;
	p->zoom_x = 0;
	p->zoom_y = 0;
	p->move_x = 0;
	p->move_y = 0;
	p->cycles = 50;
}
int	has_escaped(t_complex *zn)
{
	return (zn->a * zn->a + zn->b * zn->b > 4);
}
