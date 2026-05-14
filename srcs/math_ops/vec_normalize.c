/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_normalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:58:06 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/14 15:58:13 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_ops.h"

t_vec3	vec_normalize(const t_vec3 v1, t_status *status)
{
	double	magnitude;
	t_vec3	res;

	magnitude = vec_magnitude(v1, status);
	if (*status)
		return ((t_vec3){0.0, 0.0, 0.0});
	if (magnitude == 0.0)
	{
		if (status)
			*status = ZERO_DIVISION;
		return ((t_vec3){0.0, 0.0, 0.0});
	}
	res = (t_vec3){v1.x / magnitude, v1.y / magnitude, v1.z / magnitude};
	return (res);
}
