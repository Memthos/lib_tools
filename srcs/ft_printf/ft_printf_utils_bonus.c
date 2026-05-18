/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:35:14 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/18 15:04:25 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putchar(char c, t_ft_printf *data)
{
	if (write(1, &c, 1) == -1)
	{
		data->status = FAILURE;
		use_status(FAILURE);
		print_status("ft_printf");
		return ;
	}
	data->printed += 1;
}

void	ft_putstr(char *s, t_ft_printf *data)
{
	int	i;
	int	size;

	i = 0;
	size = ft_strlen(s);
	if (data->flags.wdt > size)
		size = data->flags.wdt;
	while (i < size && data->status == SUCCESS)
		ft_putchar(s[i++], data);
}

int	get_flag_value(const char *format, size_t *i)
{
	long	res;

	res = 0;
	while (ft_isdigit(format[*i]) == SUCCESS)
	{
		res = (res * 10) + (format[(*i)++]) - '0';
		if (res > INT_MAX)
			return (0);
	}
	return (res);
}
