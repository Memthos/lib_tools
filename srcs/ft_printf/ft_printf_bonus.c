/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 00:34:05 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/18 15:03:03 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_dprintf(int fd, const char *format, ...)
{
	t_ft_printf	data;
	va_list		args;
	size_t		i;

	if (!format || fd < 0 || fd > 1023)
		return (-1);
	i = 0;
	va_start(args, format);
	data = (t_ft_printf){&args, fd, 0, SUCCESS, {0, 0, 0, 0, 0, 0, -1, -1}};
	while (data.status == SUCCESS && format[i++])
	{
		if (format[i - 1] == '%')
		{
			if (conversion(format + i, &data, &i) == SUCCESS)
				print(&data);
		}
		else
			ft_putchar(format[i - 1], &data);
	}
	va_end(args);
	use_status(data.status);
	if (data.status != SUCCESS)
		return (-1);
	return (data.printed);
}

int	ft_printf(const char *format, ...)
{
	t_ft_printf	data;
	va_list		args;
	size_t		i;

	if (!format)
		return (-1);
	i = 0;
	va_start(args, format);
	data = (t_ft_printf){&args, 1, 0, SUCCESS, {0, 0, 0, 0, 0, 0, -1, -1}};
	while (data.status == SUCCESS && format[i++])
	{
		if (format[i - 1] == '%')
		{
			if (conversion(format + i, &data, &i) == SUCCESS)
				print(&data);
		}
		else
			ft_putchar(format[i - 1], &data);
	}
	va_end(args);
	use_status(data.status);
	if (data.status != SUCCESS)
		return (-1);
	return (data.printed);
}
