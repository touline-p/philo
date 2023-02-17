/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <bpoumeau@student.42lyon.f>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:59:21 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/17 17:20:54 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_HILO_H
# define PHILO_HILO_H

# include "libft/libft.h"

typedef struct s_philo_id
{
	int	ttd;
	int	tte;
	int	tts;
	int	philo_nb;
}	t_philo_id;

/*** INIT ***/

# define INVALID_ARG_CODE -1

/**
 * @param pattern_ptr
 * @param arguments
 * @return SUCCESS if args are valid
 * @return FAILURE if not
 */

t_ert	init_pattern(t_philo_id *pattern_ptr, char **arguments);

#endif
