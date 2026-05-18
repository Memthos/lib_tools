/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:43:24 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/18 14:52:59 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int nb)
{
	int		intlen;
	int		start;
	char	*s;

	intlen = ft_intlen(nb);
	s = ft_calloc(intlen + 1, sizeof(char));
	if (s == NULL)
		return (NULL);
	start = 0;
	if (nb < 0)
		start = 1;
	while (intlen > start)
	{
		s[intlen - 1] = ((nb % 10) * (1 - (2 * start))) + 48;
		nb /= 10;
		intlen--;
	}
	if (start == 1)
		s[0] = '-';
	return (s);
}
