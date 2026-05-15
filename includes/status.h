/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 11:17:39 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/15 15:54:59 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATUS_H
# define STATUS_H

# include <stdlib.h>
# include <unistd.h>

# include "types.h"

typedef enum e_status
{
	ERR_GET = -1,
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
	EMPTY_FILE,
	DUP_FAILURE,
	FILE_NOT_FOUND,
	PERMISSION_ERROR,
}	t_status;

size_t		ft_strlen(const char *s);

t_status	use_status(t_status status);
void		print_status(char *prefix);

#endif
