/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:01:31 by gpeta             #+#    #+#             */
/*   Updated: 2023/03/24 10:26:10 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_map_control_extention(char *filename, char *filename_main)
{
	int i;
	int len;
	char *endfile;

	if (filename == NULL)
	{
		filename = filename_main;
		printf("** filename du main\n"); // a supprimer
	}

	len = ft_strlen(filename) - 4;
	endfile = malloc(sizeof(char) * (4 + 1));
	if (!endfile)
		return (NULL);
		// exit(EXIT_FAILURE);
	i = 0;

	printf("Filename = %s\n", filename);
	while (filename[len] != '\0')
	{
		endfile[i] = filename[len];
		i++;
		len++;
	}
	endfile[i] = '\0';
	return (endfile);
}

int	ft_map_check_extention(char *filename, char *filename_main)
{
	char	*file;
	char	*extension;
	int		result;

	extension = ".ber";
	file = ft_map_control_extention(filename, filename_main);
	result = ft_strncmp(extension, file, 4);

	if(result == 0)
		printf("STRNCMP s1 == s2 : (%d)\nextension : %s | file : %s\n", result, extension, file); // a supprimer
	else
		printf("STRNCMP s1 != s2 : (%d)\nextension : %s | file : %s\n", result, extension, file); // a supprimer

	free(file);
	return (1);
}

char	*ft_generate_string_map(char *file_ber)
{
	int		fd;
	int		index;
	char	*line;
	char	*string_map;

	fd = open(file_ber, O_RDONLY);

	line = 0;
	line = get_next_line(fd);
	string_map = ft_strdup(line);		

	if (line == NULL)
		printf("c'est NULL 1\n");

	while (line)
	{
		if (!line)
			break;
		free(line);
		line = get_next_line(fd);
		string_map = ft_strdup(line);		
		if (line == NULL)
			break;
	}
	free(line);

	if (close(fd) == -1)
	{
		printf("close() fail : %d\n", fd);
		return (NULL);
		// return (1);
	}
	else
		printf("close() succes : %d\n", fd);
	
	return (string_map);
}

void	ft_generate_xpm(t_data *data, t_generate *generate)
{
	t_img	img1;
	t_img	img2;
	// t_img	img3;
	// t_img	img4;
	// t_img	img5;

	img1.relative_path = data->file_xpm1;
	img2.relative_path = data->file_xpm2;
	// img3.relative_path = data->file_xpm3;
	// img4.relative_path = data->file_xpm4;
	// img5.relative_path = data->file_xpm5;

	/* classic */
	// if (!(img1.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, img1.relative_path, &img1.img_widht, &img1.img_height)))
	// 	ft_message_error_mlx_init("Error open xpm 1 \n");
 	// if (!(img2.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, img2.relative_path, &img2.img_widht, &img2.img_height)))
	// 	ft_message_error_mlx_init("Error open xpm 2 \n");
	// img1.addr = mlx_get_data_addr(img1.mlx_img, &img1.bpp, &img1.line_len, &img1.endian);
	// img1.img_widht = 0;
	// img1.img_height = 0;
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img1.mlx_img, img1.img_widht, img1.img_height);
	// img2.addr = mlx_get_data_addr(img2.mlx_img, &img2.bpp, &img2.line_len, &img2.endian);
	// img2.img_widht = 50;
	// img2.img_height = 50;
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img2.mlx_img,img2.img_widht, img2.img_height);	

	if (!(generate->mlx_img1 = mlx_xpm_file_to_image(data->mlx_ptr, img1.relative_path, &img1.img_widht, &img1.img_height)))
		ft_message_error_mlx_init("Error open xpm 1 \n");

 	if (!(generate->mlx_img2 = mlx_xpm_file_to_image(data->mlx_ptr, img2.relative_path, &img2.img_widht, &img2.img_height)))
		ft_message_error_mlx_init("Error open xpm 2 \n");

	img1.addr = mlx_get_data_addr(generate->mlx_img1, &img1.bpp, &img1.line_len, &img1.endian);
	img1.img_widht = 0;
	img1.img_height = 0;
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, generate->mlx_img1, img1.img_widht, img1.img_height);

	img2.addr = mlx_get_data_addr(generate->mlx_img2, &img2.bpp, &img2.line_len, &img2.endian);
	img2.img_widht = 0;
	img2.img_height = 0;
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, generate->mlx_img2,img2.img_widht, img2.img_height);
	
	char *ber = "212122110111111111111111112";
	int	i = 0;
	int	x = 0;
	int y = 0;
	
		/* v1 : echap, red cross OK mais affiche qu'une image */
	// while (y < WINDOW_HEIGHT) 
	// {
	// 	while (x < WINDOW_WIDHT)
	// 	{
	// 		while (ber[i] != '\0')
	// 		{
	// 			if (ber[i] == '1')
	// 				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, generate->mlx_img1, img1.img_widht + x, img1.img_height + y);
	// 			else if (ber[i] == '2')
	// 				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, generate->mlx_img2, img2.img_widht + x, img2.img_height + y);
	// 			i++;
	// 		}
	// 		x += 60;
	// 	}
	// 	x = 0;
	// 	y += 60;
	// }	

		/* v2 : echap, red cross OK mais affiche toutes les images mais ne poursuit pas le programme */

	while (ber[i] != '\0' || y < WINDOW_HEIGHT)
	{
		while (ber[i] != '\0' && x < WINDOW_WIDHT)
		{
			if (ber[i] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, generate->mlx_img1, img1.img_widht + x, img1.img_height + y);
			else if (ber[i] == '2')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, generate->mlx_img2, img2.img_widht + x, img2.img_height + y);

			i++;
			x += 70;
		}
		x = 0;
		y += 70;
	}
}
