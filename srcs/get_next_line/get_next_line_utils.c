/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:05:10 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/14 10:09:33 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_strmove(char **dest, char **src, const int start, const int end)
{
	int	i;

	i = 0;
	while (end > start + i)
	{
		(*dest)[start + i] = (*src)[i];
		i++;
	}
	(*dest)[start + i] = '\0';
	free(*src);
}

int	buffer_update(char **buffer, char **read_str, const int read_len)
{
	char	*tmp;
	int		buffer_len;

	buffer_len = ft_strlen(*buffer);
	tmp = malloc(sizeof(char) * (buffer_len + 1));
	if (!tmp)
		return (ALLOCATION_FAILURE);
	ft_strmove(&tmp, buffer, 0, buffer_len);
	*buffer = malloc(sizeof(char) * (buffer_len + read_len + 1));
	if (!(*buffer))
	{
		ft_free_str(&tmp);
		return (ALLOCATION_FAILURE);
	}
	ft_strmove(buffer, &tmp, 0, ft_strlen(tmp));
	ft_strmove(buffer, read_str, buffer_len, read_len + buffer_len);
	return (SUCCESS);
}

int	check_linebreak(const char *str, int *break_pos, const int read_res)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			*break_pos = i + 1;
			return (SUCCESS);
		}
		i++;
	}
	if (str[i] == '\0' && read_res < BUFFER_SIZE)
	{
		*break_pos = i;
		return (SUCCESS);
	}
	*break_pos = 0;
	return (FAILURE);
}

int	clean_buffer(char **buffer, const char *str)
{
	char	*tmp;
	int		clean_buffer_size;
	int		buffer_size;

	buffer_size = ft_strlen(*buffer);
	clean_buffer_size = buffer_size - ft_strlen(str);
	tmp = malloc(sizeof(char) * (clean_buffer_size + 1));
	if (!tmp)
		return (ALLOCATION_FAILURE);
	tmp[clean_buffer_size] = '\0';
	while (clean_buffer_size > 0 && buffer_size > 0)
		tmp[clean_buffer_size-- - 1] = (*buffer)[buffer_size-- - 1];
	free(*buffer);
	*buffer = malloc(sizeof(char) * (ft_strlen(tmp) + 1));
	if (!*buffer)
	{
		ft_free_str(&tmp);
		return (ALLOCATION_FAILURE);
	}
	ft_strmove(buffer, &tmp, 0, ft_strlen(tmp));
	return (SUCCESS);
}
