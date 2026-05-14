/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_status.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 11:12:09 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/14 11:20:37 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "status.h"

t_status	use_status(t_status status, int should_set)
{
	static t_status	code = SUCCESS;

	if (should_set)
		code = status;
	return (code);
}
