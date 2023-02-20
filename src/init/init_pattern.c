/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pattern.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:19:06 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/20 11:57:57 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

t_ert	_check_then_atoi_on(char *msg, int *int_pt);

t_ert	init_pattern(t_parsed_args *pattern_ptr, char **arguments)
{
	if (_check_then_atoi_on(arguments[0], &philo_nb)
			|| pattern_ptr->philo_nb > 1024)
			|| _check_then_atoi_on(arguments[1], &pattern_ptr->ttd)
			|| _check_then_atoi_on(arguments[2], &pattern_ptr->tte)
			|| _check_then_atoi_on(arguments[3], pattern_ptr->tts))
		return (FAILURE);
	return (SUCCESS);
}

t_ert	_check_then_atoi_on(char *msg, int *int_pt)
{
	if (!str_is_made_of(msg, "0123456789"))
		return  (FAILURE);
	return (ft_atoi_on(msg, int_pt));
}
