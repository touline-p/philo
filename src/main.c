/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:58:21 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/17 17:16:42 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static	int	_main_ending_process(char *msg);

int	main(int ac, char *av[])
{
	t_philo_id	pattern;

	if (ac < 4 || ac > 5)
		return (_main_ending_process("Invalid argument number.\n"));
	if (init_pattern(&pattern, av[2]) != SUCCESS)
		return (_main_ending_process("Invalid argument.\n"))
	return (0);
}

static	int	_main_ending_process(char *msg)
{
	write(2, msg, ft_strlen(msg));

	return (0);
}