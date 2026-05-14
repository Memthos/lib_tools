/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:43:24 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/14 15:49:41 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int nb)
{
	int		intlen;
	int		start;
	char	*s;

	intlen = ft_intlen(nb);
	s = (char *) malloc((intlen + 1) * sizeof(char));
	if (s == NULL)
	{
		use_status(ALLOCATION_FAILURE);
		return (NULL);
	}
	s[intlen] = '\0';
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
