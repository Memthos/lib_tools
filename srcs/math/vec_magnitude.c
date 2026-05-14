/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_magnitude.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:57:44 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/14 15:57:54 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_ops.h"

double	vec_squared_magnitude(t_vec3 v1, t_status *status)
{
	double	res;

	res = v1.x * v1.x + v1.y * v1.y + v1.z * v1.z;
	if (!isfinite(res))
	{
		if (status)
			*status = OVERFLOW;
		return (0);
	}
	return (res);
}

double	vec_magnitude(t_vec3 v1, t_status *status)
{
	double	squared;
	double	res;

	squared = vec_squared_magnitude(v1, status);
	if (*status)
		return (0);
	res = sqrt(squared);
	if (!isfinite(res))
	{
		if (status)
			*status = OVERFLOW;
		return (0);
	}
	return (res);
}
