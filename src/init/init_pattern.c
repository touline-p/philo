/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pattern.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpoumeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:19:06 by bpoumeau          #+#    #+#             */
/*   Updated: 2023/02/17 18:15:13 by bpoumeau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_ert	init_pattern(t_pilo_id *pattern_ptr, char **arguments)
{
	pattern_ptr->ttd = _check_then_atoi(arguments[0]);	
	if (pattern_ptr->ttd == INVALID_ARG_CODE)
		return (FAILURE);
	pattern_ptr->tte = _check_then_atoi(arguments[1]);	
	if (pattern_ptr->tte == INVALID_ARG_CODE)
		return (FAILURE);
	pattern_ptr->tts = _check_then_atoi(arguments[2]);	
	if (pattern_ptr->tts == INVALID_ARG_CODE)
		return (FAILURE);
	return (SUCCESS);
}

int	_check_then_atoi(char *msg)
{
	if (!str_is_made_of(mst, "0123456789")
		return  (INVALID_ARG_CODE);
	return (ft_atoi(msg));
}
