/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamad <hamad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 15:19:29 by hamad             #+#    #+#             */
/*   Updated: 2024/09/19 18:22:57 by hamad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	check_real(t_prog *p, int ac, char **av)
{
	size_t	i;
	size_t	j;

	i = 2;
	if (ft_isonlyspace(av[i]))
		exit_prog(p, JULIA_WRONG_FORMAT, 1);
	j = ft_skipspace(av[i]);
	while (av[i][j] != '\0')
	{
		if (av[i][j] == '.')
			j++;
		if (ft_isalpha(av[i][j]) || ft_isspace(av[i][j]))
			exit_prog(p, JULIA_WRONG_FORMAT, 1);
		j++;
	}
}

void	check_imaginary(t_prog *p, int ac, char **av)
{
	size_t	i;
	size_t	j;

	i = 3;
	if (ft_isonlyspace(av[i]))
		exit_prog(p, JULIA_WRONG_FORMAT, 1);
	j = ft_skipspace(av[i]);
	while (av[i][j] != '\0')
	{
		if (av[i][j] == 'i')
			break ;
		if (av[i][j] == '.')
			j++;
		if (ft_isalpha(av[i][j]) || ft_isspace(av[i][j]))
			exit_prog(p, JULIA_WRONG_FORMAT, 1);
		j++;
	}
}
