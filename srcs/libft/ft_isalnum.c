/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 12:15:11 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/14 16:54:12 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_status	ft_isalnum(int c)
{
	if (ft_isalpha(c) == SUCCESS || ft_isdigit(c) == SUCCESS)
		return (SUCCESS);
	return (FAILURE);
}
