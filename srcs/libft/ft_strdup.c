/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 13:57:04 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/14 12:13:30 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*cpy;

	if (!s)
		return (NULL);
	cpy = (char *) ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (cpy == NULL)
		return (NULL);
	ft_strlcpy(cpy, s, ft_strlen(s) + 1);
	return (cpy);
}
