/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:58:21 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/20 15:46:20 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static	int	_main_ending_process(char *msg);


int	main(int ac, char *av[])
{
	t_parsed_args	args;
	pthread_mutex_t m_forks[MAX_PHILO];
	pthread_mutex_t m_display;
	pthread_t		philo_id[MAX_PHILO];

	if (ac < 4 || ac > 5)
		return (_main_ending_process("Invalid argument number.\n"));
	if (init_pattern(&args, &av[1]) != SUCCESS)
		return (_main_ending_process("Invalid argument.\n"));
	if (init_mutex(args, m_forks, &m_display))
		return (_main_ending_process("Can't init mutex.\n"));
	if (init_threads(args, m_fork, m_display, philo_id))
		return (_main_ending_process("Error initializing threads.\n"));
	return (0);
}

static	int	_main_ending_process(char *msg)
{
	write(2, msg, ft_strlen(msg));

	return (0);
}
