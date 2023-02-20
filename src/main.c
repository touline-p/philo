/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:58:21 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/20 11:26:50 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static	int	_main_ending_process(char *msg);


int	main(int ac, char *av[])
{
	t_parsed_args	args;
	pthread_mutex_t m_forks[1024];
	pthread_mutex_t m_display;

	if (ac < 4 || ac > 5)
		return (_main_ending_process("Invalid argument number.\n"));
	if (init_pattern(&args, &av[2]) != SUCCESS)
		return (_main_ending_process("Invalid argument.\n"));
	if (init_mutex(args, m_forks, &m_display))
		return (_main_ending_process("Can't init mutex.\n"));
	if (init_threads(args, m_fork, m_display))
		return (_main_ending_process("error initializing threads.\n"));
	return (0);
}

static	int	_main_ending_process(char *msg)
{
	write(2, msg, ft_strlen(msg));

	return (0);
}

static t_ert	_init_mutex_eu(pthread_mutex_t *mfork, int nb_fork);

t_ert	init_mutex(t_parsed_args args, pthread_mutex_t *m_fork, pthread_mutex_t *m_display)
{
	int i;

	i = 0;
	if (pthread_mutex_init(m_display, NULL))
		return (_init_mutex_eu())
	while (i < args.philo_nb)
	{
		if (pthread_mutex_init(&m_fork[i], NULL))
			return (_init_mutex_eu(mfork, i, m_display));
		i++;
	}
}

static t_ert	_init_mutex_eu(pthread_mutex_t *m_fork, int nb_fork, pthread_mutex_t *m_display)
{
	pthread_mutex_destroy(&m_fork[nb_fork]);
	while (nb_fork--)
		pthread_mutex_destroy(&m_fork[nb_fork]);
	ptread_mutex_destroy(m_display);
	return (FAILURE);
}