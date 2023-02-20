/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:59:21 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/20 15:49:13 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_HILO_H
# define PHILO_HILO_H

# include "libft/libft.h"
# include <pthread.h>

# define MAX_PHILO 1024

typedef struct s_parsed_args
{
	int				ttd;
	int				tte;
	int				tts;
	int 			nb_of_meal;
	int				philo_nb;
}	t_parsed_args;

/*** INIT ***/

/**
 * @param pattern_ptr
 * @param arguments
 * @return SUCCESS if args are valid
 * @return FAILURE if not
 */

t_ert	init_pattern(t_parsed_args *pattern_ptr, char **arguments);

/**
 * @param args previously parsed in init pattern
 * @param m_fork array depicting all the forks
 * @param m_display
 * @return
 */

t_ert	init_mutex(t_parsed_args args, pthread_mutex_t *m_fork, pthread_mutex_t *m_display);

typedef struct s_philo_tool_set
{
	int				ttd;
	int				tte;
	int				tts;
	int				nb_of_meal;
	pthread_mutex_t l_fork;
	pthread_mutex_t r_fork;
	pthread_mutex_t display;
}	t_tlset;

/***
 *
 * @param args
 * @param m_forks
 * @param m_display
 * @param philo_id
 * @return
 */

t_ert	init_threads(t_parsed_args args, pthread_mutex_t *m_forks, pthread_mutex_t m_display,
					  pthread_t *philo_id);

#endif