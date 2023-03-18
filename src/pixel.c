/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:09:45 by gpeta             #+#    #+#             */
/*   Updated: 2023/03/18 14:09:34 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// int	render(t_data *data) // v1
// {
// 	/* verif sur la window n'est pas détruite */
// 	if (data->win_ptr != NULL)
// 		mlx_pixel_put(data->mlx_ptr, data->win_ptr, WINDOW_WIDHT / 2, WINDOW_HEIGHT / 2, RED_PIXEL);
// 	return (0);
// }

int	render(t_data *data) // v2
{
	if (data->win_ptr == NULL)
		return (1);
	render_background(&data->img, BLUE_PIXEL);
	/* Affiche 2 carrés : 1 en haut à gauche l'autre en bas à droite */
	// render_rect(&data->img, (t_rect){WINDOW_WIDHT - 50, WINDOW_HEIGHT - 50, 50, 50, GREEN_PIXEL}); // y < nombre soustrait a WINDOW_HEIGHT
	// render_rect(&data->img, (t_rect){0, 0, 50, 50, RED_PIXEL});

	/* Affiche 2 carrés cote à cote */
	render_rect(&data->img, (t_rect){WINDOW_WIDHT / 2 + 30, WINDOW_HEIGHT / 2, 50, 50, GREEN_PIXEL}); // y < nombre soustrait a WINDOW_HEIGHT
	render_rect(&data->img, (t_rect){WINDOW_WIDHT / 2 - 30, WINDOW_HEIGHT / 2, 50, 50, RED_PIXEL});

	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);

	return(0);
}

int	render_rect(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDHT)
			img_pix_put(img, j++, i, color);
		++i;
	}
}

int	render_img(t_data *data)
{
	// data->img_reading = mlx_xpm_file_to_image(data->mlx_ptr, data->img.relative_path, 0, 0);
	// data->img.mlx_img = mlx_new_image(data->mlx_ptr, 50, 50);
	// data->img_reading = mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, data->img.img_widht, data->img.img_height);
	// data->img.mlx_img = mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 50, 50);
	return (0);
}
