/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:13:10 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/14 10:51:29 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_status	ft_isdigit(int c)
{
	if (!c)
		return (FAILURE);
	if (c >= 48 && c <= 57)
		return (SUCCESS);
	return (FAILURE);
}
