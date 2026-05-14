/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_sep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:22:46 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/14 15:36:36 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_sep(const char *s1, char sep, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if ((!s1 && !s2) || sep == 0)
		return (NULL);
	str = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 2), sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	str[i++] = sep;
	j = 0;
	while (s2 && s2[j])
		str[i++] = s2[j++];
	return (str);
}
