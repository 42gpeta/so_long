/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:01:31 by gpeta             #+#    #+#             */
/*   Updated: 2023/04/28 14:30:05 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


/*** Génère la string_map dans un tableau  */
void	ft_generate_string_map(t_data *data) // ? v4
{
	char	*line;

	data->generate.fd = open(data->filename, O_RDWR);
	if (data->generate.fd < 0 || data->generate.fd > 1024)
		ft_message_error("Cannot open this !", data);
	data->row_size_map = 0;
	data->string_map = get_next_line(data->generate.fd);
	data->row_size_map++;
	line = get_next_line(data->generate.fd);
	data->row_size_map++;
	if (data->string_map == NULL || line == NULL)
		ft_message_error("First line of this file is empty.", data);
	while (data->string_map)
	{
		data->string_map = ft_strjoin_gnl(data->string_map, line);
		free(line);
		line = get_next_line(data->generate.fd);
		if (line == NULL)
			break;
		data->row_size_map++;
	}
	free(line);
	ft_check_string_map(data);
	ft_generate_string_map_tab(data);
}

/*** Vérifie l'existence de la string_map dans un tableau  */
void	ft_check_string_map(t_data *data)
{
	if (data->string_map[0] != '1')
	{
		if (close(data->generate.fd) == -1)
			ft_message_error("Close of file failed.", data);
		ft_message_error("First line isn't wall of 1", data);
	}
}

/*** Génère le string_map dans un tableau de tableau  */
void	ft_generate_string_map_tab(t_data *data)
{
	data->generate.string_map_ber_tab = ft_split(data->string_map, '\n'); // ? v2
	data->generate.string_map_pathfinding = ft_split(data->string_map, '\n'); // ? v2 // arret ICI
	data->colomn_size_map = ft_strlen(data->generate.string_map_ber_tab[0]); // ? v2
	data->colomn_size_win = data->colomn_size_map * ECART_XPM;
	if (data->colomn_size_win > WINDOW_WIDHT_MAX)
		ft_message_error("Map to big. (widht)", data);
	data->row_size_win = data->row_size_map * ECART_XPM;
	if (data->row_size_win > WINDOW_HEIGHT_MAX)
		ft_message_error("Map to big. (height)", data);
}

/*** Initie les XPM en image */
void	ft_generate_path_file(t_data *data)
{
	if (!(data->generate.mlx_img0 = mlx_xpm_file_to_image(data->mlx_ptr, data->path_xpm0, &data->img.widht, &data->img.height)))
		ft_message_error("Open xpm 0 fail", data);
 	if (!(data->generate.mlx_img1 = mlx_xpm_file_to_image(data->mlx_ptr, data->path_xpm1, &data->img.widht, &data->img.height)))
		ft_message_error("Open xpm 1 fail", data);
	if (!(data->generate.mlx_imgC = mlx_xpm_file_to_image(data->mlx_ptr, data->path_xpmC, &data->img.widht, &data->img.height)))
		ft_message_error("Open xpm C fail", data);
 	if (!(data->generate.mlx_imgE = mlx_xpm_file_to_image(data->mlx_ptr, data->path_xpmE, &data->img.widht, &data->img.height)))
		ft_message_error("Open xpm E fail", data);
	if (!(data->generate.mlx_imgP = mlx_xpm_file_to_image(data->mlx_ptr, data->path_xpmP, &data->img.widht, &data->img.height)))
		ft_message_error("Open xpm P fail", data);
}

/*** Génère l'afichage des XPM  */
// void	ft_generate_xpm(t_data *data) // ? v1
// {
// 	int	x;
// 	int y;

// 	ft_generate_offset(data);
// 	y = 0;
// 	while (data->generate.string_map_ber_tab[y])
// 	{
// 		x = 0;
// 		while (data->generate.string_map_ber_tab[y][x])
// 		{
// 			if (data->generate.string_map_ber_tab[y][x] == '0')
// 				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->generate.mlx_img0, data->img.widht * x, data->img.height * y);
// 			else if (data->generate.string_map_ber_tab[y][x] == '1')
// 				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->generate.mlx_img1, data->img.widht * x, data->img.height * y);
// 			else if (data->generate.string_map_ber_tab[y][x] == 'C')
// 				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->generate.mlx_imgC, data->img.widht * x, data->img.height * y);
// 			else if (data->generate.string_map_ber_tab[y][x] == 'E')
// 				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->generate.mlx_imgE, data->img.widht * x, data->img.height * y);
// 			else if (data->generate.string_map_ber_tab[y][x] == 'P')
// 				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->generate.mlx_imgP, data->img.widht * x, data->img.height * y);
// 			x++;
// 		}
// 		y++;
// 	}
// }

/*** Génère l'afichage des XPM  */
void	ft_generate_xpm(t_data *data) // ? v2
{
	int	x;
	int y;

	// ft_generate_offset(data);
	y = 0;
	while (data->generate.string_map_ber_tab[y])
	{
		x = 0;
		while (data->generate.string_map_ber_tab[y][x])
		{
			if (data->generate.string_map_ber_tab[y][x] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->generate.mlx_img0, data->img.widht * x, data->img.height * y);
			else if (data->generate.string_map_ber_tab[y][x] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->generate.mlx_img1, data->img.widht * x, data->img.height * y);
			else if (data->generate.string_map_ber_tab[y][x] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->generate.mlx_imgC, data->img.widht * x, data->img.height * y);
			else if (data->generate.string_map_ber_tab[y][x] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->generate.mlx_imgE, data->img.widht * x, data->img.height * y);
			else if (data->generate.string_map_ber_tab[y][x] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->generate.mlx_imgP, data->img.widht * x, data->img.height * y);
			x++;
		}
		y++;
	}
}

// void	ft_generate_offset(t_data *data)
// {
// 	data->offset_y = 0;
// 	data->offset_x = 0;

// 	if (data->row_size_win > WINDOW_HEIGHT_MAX)
// 		data->offset_y -= 40;
// 	if (data->colomn_size_win > WINDOW_WIDHT_MAX)
// 		data->offset_x -= 22;
// }
