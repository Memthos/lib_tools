/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:41:53 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/14 11:45:07 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*mem;

	if (nmemb == 0 || size == 0)
		return (NULL);
	if (nmemb > (size_t) -1 / size)
		return (NULL);
	mem = (void *) malloc(nmemb * size);
	if (mem == NULL)
	{
		use_status(ALLOCATION_FAILURE, 1);
		return (NULL);
	}
	ft_bzero(mem, nmemb * size);
	return (mem);
}
