/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:21:42 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/14 10:52:01 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_status	ft_isspace(int c)
{
	if (!c)
		return (FAILURE);
	if ((c >= 9 && c <= 13) || c == 32)
		return (SUCCESS);
	return (FAILURE);
}
