/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 11:17:39 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/14 11:20:31 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATUS_H
# define STATUS_H

# include "types.h"

typedef enum e_status
{
	SKIP = -1,
	SUCCESS,
	FAILURE,
	BAD_ARG,
	TOO_MANY_ARG,
	NOT_ENOUGH_ARG,
	OVERFLOW,
	UNDERFLOW,
	ZERO_DIVISION,
	ALLOCATION_FAILURE,
	OPEN_FAILURE,
	IS_DIRECTORY,
	READ_FAILURE,
	DUP_FAILURE,
	FILE_NOT_FOUND,
	PERMISSION_ERROR,
}	t_status;

t_status	use_status(t_status status, int should_set);

#endif
