/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 11:12:09 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/14 16:41:06 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "status.h"

t_status	use_status(t_status status)
{
	static t_status	code = SUCCESS;

	if (status != ERR_GET)
		code = status;
	return (code);
}

static char	*get_error(t_status status)
{
	const char	*data[] = {"Success", "Failure", "Bad argument",
		"Too many arguments", "Not enough arguments", "Overflow", "Underflow",
		"Division by zero", "Allocation failure", "Open failure",
		"Is a directory", "Read failure", "Dup failure",
		"No such file or directory", "Permission denied"};
	return (data[status]);
}

void	print_status(char *prefix)
{
	char	*error;

	error = use_status(ERR_GET);
	if (prefix)
	{
		if (write(2, prefix, ft_strlen(prefix)) == -1)
		{
			use_status(FAILURE);
			return ;
		}
		if (write(2, ": ", 2) == -1)
		{
			use_status(FAILURE);
			return ;
		}
	}
	if (write(2, error, ft_strlen(error)) == -1)
	{
		use_status(FAILURE);
		return ;
	}
	if (write(2, "\n", 1) == -1)
		use_status(FAILURE);
}
