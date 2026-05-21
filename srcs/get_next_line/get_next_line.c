/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:04:35 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/20 13:50:38 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_line(char **str, char **buffer, const int break_pos)
{
	*str = ft_calloc(break_pos + 1, sizeof(char));
	if (!*str)
	{
		ft_free_str(buffer);
		return (ALLOCATION_FAILURE);
	}
	ft_strlcpy(*str, *buffer, break_pos + 1);
	if (break_pos == (int)ft_strlen(*buffer))
	{
		ft_free_str(buffer);
		return (SUCCESS);
	}
	if (clean_buffer(buffer, *str) != SUCCESS)
	{
		ft_free_str(str);
		ft_free_str(buffer);
		return (ALLOCATION_FAILURE);
	}
	return (SUCCESS);
}

int	read_more(const int fd, char **buffer, int *read_len)
{
	char	*read_str;

	read_str = ft_calloc(BUFFER_SIZE, sizeof(char));
	if (!read_str)
	{
		ft_free_str(buffer);
		return (FAILURE);
	}
	*read_len = (int) read(fd, read_str, BUFFER_SIZE);
	if (*read_len < 1)
		ft_free_str(&read_str);
	if (*read_len == 0 && (*buffer)[0] != '\0')
		return (SUCCESS);
	else if (*read_len < 1)
	{
		ft_free_str(buffer);
		if (*read_len == 0)
			return (FAILURE);
		use_status(READ_FAILURE);
		print_status("get_next_line");
		return (FAILURE);
	}
	if (buffer_update(buffer, &read_str, *read_len) == SUCCESS)
		return (SUCCESS);
	return (ALLOCATION_FAILURE);
}

int	init_buffer(char **buffer)
{
	if (!*buffer)
	{
		*buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!*buffer)
		{
			*buffer = NULL;
			return (ALLOCATION_FAILURE);
		}
		(*buffer)[0] = '\0';
		return (SUCCESS);
	}
	return (SUCCESS);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*str;
	int			break_pos;
	int			read_len;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE < 1)
		return (NULL);
	if (init_buffer(&buffer) != SUCCESS)
		return (NULL);
	while (1)
	{
		if (read_more(fd, &buffer, &read_len) != SUCCESS)
			return (NULL);
		if (check_linebreak(buffer, &break_pos, read_len) == SUCCESS)
		{
			if (get_line(&str, &buffer, break_pos) != SUCCESS)
				return (NULL);
			break ;
		}
	}
	return (str);
}
