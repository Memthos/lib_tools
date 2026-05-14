/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_status.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 11:12:09 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/14 15:48:20 by mperrine         ###   ########.fr       */
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
