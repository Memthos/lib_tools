/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:15:48 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/14 12:01:02 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s == NULL || fd < 0)
		return ;
	ft_putstr_fd(s, fd);
	if (use_status(0, 0) != SUCCESS)
		return ;
	if (write(fd, "\n", 1) == -1)
		use_status(FAILURE, 1);
}
