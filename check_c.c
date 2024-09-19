/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:19:29 by hamad             #+#    #+#             */
/*   Updated: 2024/09/19 22:33:06 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_real(t_prog *p, int ac, char **av)
{
	size_t	i;

	if (ft_isonlyspace(av[2]))
		exit_prog(p, JULIA_WRONG_FORMAT, 1);
	i = ft_skipspace(av[2]);
	while (av[2][i] != '\0')
	{
		if (av[2][i] == '.')
			i++;
		if (ft_isalpha(av[2][i]) || ft_isspace(av[2][i]))
			exit_prog(p, JULIA_WRONG_FORMAT, 1);
		i++;
	}
}

void	check_imaginary(t_prog *p, int ac, char **av)
{
	size_t	i;

	if (ft_isonlyspace(av[3]))
		exit_prog(p, JULIA_WRONG_FORMAT, 1);
	i = ft_skipspace(av[3]);
	while (av[3][i] != '\0')
	{
		if (av[3][i] == 'i' && av[3][i + 1] == '\0')
			break ;
		if (av[3][i] == '.')
			i++;
		if (ft_isalpha(av[3][i]) || ft_isspace(av[3][i]))
			exit_prog(p, JULIA_WRONG_FORMAT, 1);
		i++;
	}
}
