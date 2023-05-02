/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:31:37 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/02 20:19:44 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_xpm_to_img(t_data *data)
{
	data->gen.mlx_img0 = mlx_xpm_file_to_image(data->mlx_p,
			data->path_xpm0, &data->img.w, &data->img.h);
	data->gen.mlx_img1 = mlx_xpm_file_to_image(data->mlx_p,
			data->path_xpm1, &data->img.w, &data->img.h);
	data->gen.mlx_imgc = mlx_xpm_file_to_image(data->mlx_p,
			data->path_xpmc, &data->img.w, &data->img.h);
	data->gen.mlx_imge = mlx_xpm_file_to_image(data->mlx_p,
			data->path_xpme, &data->img.w, &data->img.h);
	data->gen.mlx_imgp = mlx_xpm_file_to_image(data->mlx_p,
			data->path_xpmp, &data->img.w, &data->img.h);
	if (!data->gen.mlx_img0)
		ft_message_error("Open xpm 0 fail", data);
	if (!data->gen.mlx_img1)
		ft_message_error("Open xpm 1 fail", data);
	if (!data->gen.mlx_imgc)
		ft_message_error("Open xpm C fail", data);
	if (!data->gen.mlx_imge)
		ft_message_error("Open xpm E fail", data);
	if (!data->gen.mlx_imgp)
		ft_message_error("Open xpm P fail", data);
}

void	ft_put_img(t_data *data, char *img, int w, int h)
{
	mlx_put_image_to_window(data->mlx_p, data->win_p, img, w, h);
}

void	ft_img_configuration(t_data *data, int y, int x)
{
	char	*text;
	int		w;
	int		h;

	data->gen.man.move = ft_itoa(data->gen.man.nb_move);
	if (data->gen.man.move == NULL)
		ft_message_error("Itoa fail", data);
	text = ft_strjoin("Number of movements : ", data->gen.man.move);
	w = data->img.w * x;
	h = data->img.h * y;
	if (data->gen.str_tab[y][x] == '0')
		ft_put_img(data, data->gen.mlx_img0, w, h);
	else if (data->gen.str_tab[y][x] == '1')
		ft_put_img(data, data->gen.mlx_img1, w, h);
	else if (data->gen.str_tab[y][x] == 'C')
		ft_put_img(data, data->gen.mlx_imgc, w, h);
	else if (data->gen.str_tab[y][x] == 'E')
		ft_put_img(data, data->gen.mlx_imge, w, h);
	else if (data->gen.str_tab[y][x] == 'P')
		ft_put_img(data, data->gen.mlx_imgp, w, h);
	mlx_string_put(data->mlx_p, data->win_p, 50, 50, WHITE_PIXEL, text);
	free(data->gen.man.move);
	free(text);
}

void	ft_display_xpm(t_data *data)
{
	int		x;
	int		y;

	y = -1;
	while (data->gen.str_tab[++y])
	{
		x = -1;
		while (data->gen.str_tab[y][++x])
			ft_img_configuration(data, y, x);
	}
}
