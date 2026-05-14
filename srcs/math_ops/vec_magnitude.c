/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_magnitude.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:57:44 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/14 16:56:50 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_ops.h"

double	vec_squared_magnitude(t_vec3 v1)
{
	double	res;

	res = v1.x * v1.x + v1.y * v1.y + v1.z * v1.z;
	if (!isfinite(res))
	{
		use_status(OVERFLOW);
		return (0);
	}
	return (res);
}

double	vec_magnitude(t_vec3 v1)
{
	double	squared;
	double	res;

	squared = vec_squared_magnitude(v1);
	if (use_status(ERR_GET) != SUCCESS)
		return (0);
	res = sqrt(squared);
	if (!isfinite(res))
	{
		use_status(OVERFLOW);
		return (0);
	}
	return (res);
}
