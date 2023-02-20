/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_threads.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 12:22:53 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/20 15:53:48 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static void		_init_tlset(t_parsed_args args, pthread_mutex_t *m_forks, pthread_mutex_t m_display,
							 t_tlset *tlsets);
static t_tlset	_init_unique_tlset(pthread_mutex_t m_l_fork, pthread_mutex_t m_r_fork, pthread_mutex_t mdisplay,
							 t_parsed_args args);
static t_ert	_init_thread_err_process(size_t indx, pthread_t *philo_id, t_ert ret_val);

t_ert	init_threads(t_parsed_args args, pthread_mutex_t *m_forks, pthread_mutex_t m_display,
					  pthread_t *philo_id)
{
	t_tlset	tlset[MAX_PHILO];
	size_t	indx;

	indx = 0;
	_init_tlset(args, m_forks, m_display, &tlset);
	while (indx < args.philo_nb)
	{
		if (pthread_create(&thread_id[indx], NULL, philo_launch, &tlset[indx]))
			return (_init_thread_err_process(++indx, philo_id, m_forks, m_display));
		indx++;
	}
	return (SUCCESS);
}

static void	_init_tlset(t_parsed_args args, pthread_mutex_t *m_forks, pthread_mutex_t m_display,
					t_tlset *tlsets)
{
	size_t			indx;
	pthread_mutex_t *m_l_fork;
	pthread_mutex_t *m_r_fork;

	indx = 0;
	m_r_fork = m_forks[0];
	m_l_fork = m_forks[args.philo_nb - 1];
	while (indx++ < args.philo_nb)
	{
		tlsets[indx] = _init_unique_tlset(m_l_fork, m_r_fork, mdisplay, args);
		m_l_fork = m_r_fork;
		m_r_fork = m_forks[indx];
	}
}

static t_tlset	_init_unique_tlset(pthread_mutex_t m_l_fork, pthread_mutex_t m_r_fork, pthread_mutex_t mdisplay,
							  t_parsed_args args)
{
	t_tlset tlset;

	tlset.ttd = args.ttd;
	tlset.tte = args.tte;
	tlset.tts = args.tts;
	tlset.nb_of_meal = args.nb_of_meal;
	tlset.l_fork = m_l_fork;
	tlset.r_fork = m_r_fork;
	tlset.display = mdisplay;
	return (tslet)
}

static t_ert	_init_thread_err_process(size_t indx, pthread_t *philo_id, pthread_mutex_t *m_forks, pthread_mutex_t display)
{
	while (indx--;)
	{
		pthread_join(philo_id[indx], NULL);
		pthread_mutex_destroy(&m_forks[indx]);
	}
	pthread_mutex_destroy(&m_display)
	return (FAILURE);
}
