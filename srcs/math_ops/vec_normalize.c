/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_normalize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mperrine <mperrine@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 15:58:06 by mperrine          #+#    #+#             */
/*   Updated: 2026/05/14 16:57:09 by mperrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math_ops.h"

t_vec3	vec_normalize(const t_vec3 v1)
{
	double	magnitude;
	t_vec3	res;

	magnitude = vec_magnitude(v1);
	if (use_status(ERR_GET) != SUCCESS)
		return ((t_vec3){0.0, 0.0, 0.0});
	if (magnitude == 0.0)
	{
		use_status(ZERO_DIVISION);
		return ((t_vec3){0.0, 0.0, 0.0});
	}
	res = (t_vec3){v1.x / magnitude, v1.y / magnitude, v1.z / magnitude};
	return (res);
}
