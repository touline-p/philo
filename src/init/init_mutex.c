/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 11:41:17 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/20 11:41:25 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static t_ert	_init_mutex_eu(pthread_mutex_t *mfork, int nb_fork);

t_ert	init_mutex(t_parsed_args args, pthread_mutex_t *m_fork, pthread_mutex_t *m_display)
{
	int i;

	i = 0;
	if (pthread_mutex_init(m_display, NULL) != SUCCESS)
		return (_init_mutex_eu());
	while (i < args.philo_nb)
	{
		if (pthread_mutex_init(&m_fork[i], NULL) != SUCCESS)
			return (_init_mutex_eu(mfork, i, m_display));
		i++;
	}
	return (SUCCESS);
}

/*
 * I don't protect mutex_destroy cause it fails only in those 3 cases :
 * If the mutex object has not been initialized with the pthread_mutex_init function.
 * If the mutex object is locked when calling the pthread_mutex_destroy function.
 * If multiple threads attempt to destroy the same mutex object simultaneously.
 */

static t_ert	_init_mutex_eu(pthread_mutex_t *m_fork, int nb_fork, pthread_mutex_t *m_display)
{
	pthread_mutex_destroy(&m_fork[nb_fork]);
	while (nb_fork--)
		pthread_mutex_destroy(&m_fork[nb_fork]);
	ptread_mutex_destroy(m_display);
	return (FAILURE);
}
