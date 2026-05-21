/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:22:15 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/21 13:46:27 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_status	check_overflow(int nb, int sign, int c)
{
	t_status	status;

	status = SUCCESS;
	if (nb * sign > (INT_MAX - (c - '0')) / 10)
		status = OVERFLOW;
	else if (nb * sign < (INT_MIN + (c - '0')) / 10)
		status = UNDERFLOW;
	if (use_status(status) != SUCCESS)
		print_status("ft_atoi");
	return (status);
}

int	ft_atoi(const t_string str)
{
	size_t	i;
	int		nb;
	int		sign;

	i = 0;
	nb = 0;
	sign = 1;
	if (!str)
	{
		use_status(FAILURE);
		print_status("ft_atoi");
		return (0);
	}
	while (ft_isspace(str[i]) == SUCCESS)
		i++;
	if (str[i] == '-' || str[i] == '+')
		sign = (str[i++] % 43) * -1 + 1;
	while (ft_isdigit(str[i]) == SUCCESS)
	{
		if (check_overflow(nb, sign, str[i]) != SUCCESS)
			return (0);
		nb = nb * 10 + (str[i++] - '0');
	}
	return (nb);
}
