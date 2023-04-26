/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:01:31 by gpeta             #+#    #+#             */
/*   Updated: 2023/04/26 17:30:53 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*** Verifie si l'AV 1 est bien remplis  */
void	ft_map_control_extention(t_data *data, char *filename_main) // ? v3
{
	data->filename = filename_main;
	if (data->filename == NULL)
		ft_message_error("The program need 1 parameter", data);
}

/*** Verifie si le fichier est un ".ber" valide  */
void	ft_map_check_extention(t_data *data, char *filename_main)
{
	char	*file;
	char	*extension;
	int		result;

	file = 0;
	extension = ".ber";

	if (!(file = ft_strrchr(data->filename, '.'))
		|| !(data->generate.fd = open(data->filename, O_RDWR)))
		ft_message_error("Check the parameter", data);

	result = ft_strncmp(extension, file, 4);

	if (result != 0)
	{
		printf("STRNCMP s1 != s2 : (%d)\nextension : %s | file : %s\n", result, extension, file); // ! a supprimer
		ft_message_error("Check extension's program", data);
	}
	else
		printf("STRNCMP s1 == s2 : (%d)\nextension : %s | file : %s\n", result, extension, file); // ! a supprimer
}

/*** Génère la string_map dans un tableau  */
void	ft_generate_string_map(t_data *data) // ? v4
{
	char	*line;

	data->generate.fd = open(data->filename, O_RDWR);
	if (data->generate.fd < 0 || data->generate.fd > 1024)
		ft_message_error("ft_generate_string_map : Cannot open this !", data);
	data->row_size_map = 0;
	data->string_map = get_next_line(data->generate.fd);
	data->row_size_map++;
	line = get_next_line(data->generate.fd);
	data->row_size_map++;
	if (data->string_map == NULL || line == NULL)
		ft_message_error("ft_generate_string_map : First line of this file is empty.", data);
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
			ft_message_error("ft_generate_string_map : Close of file failed.", data);
		ft_message_error("ft_generate_string_map : First line isn't wall of 1", data);
	}
}

/*** Génère le string_map dans un tableau de tableau  */
void	ft_generate_string_map_tab(t_data *data)
{
	data->generate.string_map_ber_tab = ft_split(data->string_map, '\n'); // ? v2
	data->generate.string_map_pathfinding = ft_split(data->string_map, '\n'); // ? v2 // arret ICI
	data->colomn_size_map = ft_strlen(data->generate.string_map_ber_tab[0]); // ? v2
	data->colomn_size_win = data->colomn_size_map * ECART_XPM;
	data->row_size_win = data->row_size_map * ECART_XPM;
}

/*** Initie les XPM en image */
void	ft_generate_path_file(t_data *data)
{
	if (!(data->generate.mlx_img0 = mlx_xpm_file_to_image(data->mlx_ptr, data->path_xpm0, &data->img.widht, &data->img.height)))
		ft_message_error("ft_generate_xpm : Open xpm 0 fail", data);
 	if (!(data->generate.mlx_img1 = mlx_xpm_file_to_image(data->mlx_ptr, data->path_xpm1, &data->img.widht, &data->img.height)))
		ft_message_error("ft_generate_xpm : Open xpm 1 fail", data);
	if (!(data->generate.mlx_imgC = mlx_xpm_file_to_image(data->mlx_ptr, data->path_xpmC, &data->img.widht, &data->img.height)))
		ft_message_error("ft_generate_xpm : Open xpm C fail", data);
 	if (!(data->generate.mlx_imgE = mlx_xpm_file_to_image(data->mlx_ptr, data->path_xpmE, &data->img.widht, &data->img.height)))
		ft_message_error("ft_generate_xpm : Open xpm E fail", data);
	if (!(data->generate.mlx_imgP = mlx_xpm_file_to_image(data->mlx_ptr, data->path_xpmP, &data->img.widht, &data->img.height)))
		ft_message_error("ft_generate_xpm : Open xpm P fail", data);
}

/*** Génère l'afichage des XPM  */
void	ft_generate_xpm(t_data *data)
{
	int	x;
	int y;

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
