/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:20:36 by gpeta             #+#    #+#             */
/*   Updated: 2023/03/16 13:46:59 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Replace mlx_pixel_put */
void	img_pix_put(t_img *img, int x, int y, int color) // v1
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

// void	img_pix_put(t_img *img, int x, int y, int color) // v2
// {
// 	char	*pixel;
// 	int		i;

// 	i = img->bpp - 8;
// 	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
// 	while (i >= 0)
// 	{
// 		if (img->endian != 0)
// 			*pixel++ = (color >> i) & 0xFF;
// 		else
// 			*pixel++ = (color >> (img ->bpp - 8 - i)) & 0xFF;
// 		i-= 8;
// 	}
// }