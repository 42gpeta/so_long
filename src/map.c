/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:01:31 by gpeta             #+#    #+#             */
/*   Updated: 2023/03/28 19:23:45 by gpeta            ###   ########.fr       */
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

// char	*ft_generate_string_map(char *file_ber) // ? v1

// char	*ft_generate_string_map(char *file_ber, t_data *data) // ? v2
// {
// 	int		fd;
// 	char	*line;
// 	char	*string_map;
// 
// 	fd = open(file_ber, O_RDONLY);
// 	data->row_size = 0;
// 	/* v1 */
// 	// line = get_next_line(fd);
// 	// 
// 	// if (line == NULL)
// 	// 	printf("c'est NULL 1\n");
// 	// 
// 	// line = get_next_line(fd);
// 	// string_map = ft_strdup(line);
// 	// line = get_next_line(fd);
// 	// string_map = ft_strjoin(line, string_map);
// 	// line = get_next_line(fd);
// 	// string_map = ft_strjoin(line, string_map);
// 	// 
// 	// 
// 	// line = get_next_line(fd);
// 	// while (line)
// 	// {
// 	// 	string_map = ft_strdup(line);
// 	// 	string_map = ft_strjoin(line, string_map);
// 	// 	free(line);
// 	// 	line = get_next_line(fd);
// 	// 
// 	// }
// 	// free(line);
// 
// 
// 	/* v2 */ // OK
// 	// string_map = get_next_line(fd);
// 	// line = get_next_line(fd);
// 	// if (string_map == NULL || line == NULL)
// 	// 	printf("c'est NULL 1\n");
// 	// while (string_map)
// 	// {
// 	// 	string_map = ft_strjoin(string_map, line);
// 	// 	free(line);
// 	// 	line = get_next_line(fd);
// 	// 	if (line == NULL)
// 	// 		break;
// 	// }
// 	// free(line);
// 
// 	/* v3 */ // OK
// 	string_map = get_next_line(fd);
// 	data->colomn_size = ft_strlen(string_map);
// 	data->row_size++;
// 	line = get_next_line(fd);
// 	data->row_size++;
// 	if (string_map == NULL || line == NULL)
// 		printf("c'est NULL 1\n");
// 	while (string_map)
// 	{
// 		string_map = ft_strjoin(string_map, line);
// 		// free(string_map);
// 		free(line);
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break;
// 		data->row_size++;
// 	}
// 	free(line);
// 
// 	if (close(fd) == -1)
// 		return (NULL);
// 
// 	return (string_map);
// }

char	*ft_generate_string_map(char *file_ber, t_data *data) // ? v3
{
	int		fd;
	char	*line;

	fd = open(file_ber, O_RDONLY);
	data->row_size = 0;

	/* v3 */ // OK
	data->string_map = get_next_line(fd);
	data->colomn_size = ft_strlen(data->string_map);
	data->row_size++;
	line = get_next_line(fd);
	data->row_size++;
	if (data->string_map == NULL || line == NULL)
		printf("c'est NULL 1\n");
	while (data->string_map)
	{
		data->string_map = ft_strjoin_gnl(data->string_map, line);
		// free(data->string_map);
		free(line);
		line = get_next_line(fd);
		if (line == NULL)
			break;
		data->row_size++;
	}
	free(line);

	if (close(fd) == -1)
		return (NULL);

	return (data->string_map);
}

void	ft_generate_xpm(t_data *data, t_generate *generate)
{
	t_img	img0;
	t_img	img1;
	t_img	imgC;
	t_img	imgE;
	t_img	imgP;

	img0.relative_path = data->file_xpm0;
	img1.relative_path = data->file_xpm1;
	imgC.relative_path = data->file_xpmC;
	imgE.relative_path = data->file_xpmE;
	imgP.relative_path = data->file_xpmP;

	/* classic */
	// if (!(img0.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, img0.relative_path, &img0.img_widht, &img0.img_height)))
	// 	ft_message_error("Error open xpm 1 \n");
 	// if (!(img1.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, img1.relative_path, &img1.img_widht, &img1.img_height)))
	// 	ft_message_error("Error open xpm 2 \n");
	// 
	// img0.addr = mlx_get_data_addr(img0.mlx_img, &img0.bpp, &img0.line_len, &img0.endian);
	// img0.img_widht = 0;
	// img0.img_height = 0;
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img0.mlx_img, img0.img_widht, img0.img_height);
	// 
	// img1.addr = mlx_get_data_addr(img1.mlx_img, &img1.bpp, &img1.line_len, &img1.endian);
	// img1.img_widht = 50;
	// img1.img_height = 50;
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img1.mlx_img,img1.img_widht, img1.img_height);	

	if (!(generate->mlx_img0 = mlx_xpm_file_to_image(data->mlx_ptr, img0.relative_path, &img0.img_widht, &img0.img_height)))
		ft_message_error("Error open xpm 0 \n");

 	if (!(generate->mlx_img1 = mlx_xpm_file_to_image(data->mlx_ptr, img1.relative_path, &img1.img_widht, &img1.img_height)))
		ft_message_error("Error open xpm 1 \n");

	if (!(generate->mlx_imgC = mlx_xpm_file_to_image(data->mlx_ptr, imgC.relative_path, &imgC.img_widht, &imgC.img_height)))
		ft_message_error("Error open xpm C \n");

 	if (!(generate->mlx_imgE = mlx_xpm_file_to_image(data->mlx_ptr, imgE.relative_path, &imgE.img_widht, &imgE.img_height)))
		ft_message_error("Error open xpm E \n");

	if (!(generate->mlx_imgP = mlx_xpm_file_to_image(data->mlx_ptr, imgP.relative_path, &imgP.img_widht, &imgP.img_height)))
		ft_message_error("Error open xpm P \n");

	img0.addr = mlx_get_data_addr(generate->mlx_img0, &img0.bpp, &img0.line_len, &img0.endian);
	img0.img_widht = 0;
	img0.img_height = 0;
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, generate->mlx_img0, img0.img_widht, img0.img_height);

	img1.addr = mlx_get_data_addr(generate->mlx_img1, &img1.bpp, &img1.line_len, &img1.endian);
	img1.img_widht = 0;
	img1.img_height = 0;
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, generate->mlx_img1,img1.img_widht, img1.img_height);

	imgC.addr = mlx_get_data_addr(generate->mlx_imgC, &imgC.bpp, &imgC.line_len, &imgC.endian);
	imgC.img_widht = 0;
	imgC.img_height = 0;

	imgE.addr = mlx_get_data_addr(generate->mlx_imgE, &imgE.bpp, &imgE.line_len, &imgE.endian);
	imgE.img_widht = 0;
	imgE.img_height = 0;

	imgP.addr = mlx_get_data_addr(generate->mlx_imgP, &imgP.bpp, &imgP.line_len, &imgP.endian);
	imgP.img_widht = 0;
	imgP.img_height = 0;


	// char *ber = "212122110111111111111111112";
	char *ber = generate->string_map_ber;
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
	// 				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, generate->mlx_img0, img0.img_widht + x, img0.img_height + y);
	// 			else if (ber[i] == '2')
	// 				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, generate->mlx_img1, img1.img_widht + x, img1.img_height + y);
	// 			i++;
	// 		}
	// 		x += 60;
	// 	}
	// 	x = 0;
	// 	y += 60;
	// }	

		/* v2 : echap, red cross OK mais affiche toutes les images mais ne poursuit pas le programme */
	// if (data->row_size > WINDOW_HEIGHT_MAX || data->colomn_size > WINDOW_WIDHT_MAX)
		// ft_message_error("Error : map's height or map's widht is too big");

	// while (ber[i] != '\0' || y < WINDOW_HEIGHT) // ? v1
	while (ber[i] != '\0' || y < data->row_size)
	{
		// while (ber[i] != '\0' && x < WINDOW_WIDHT) // ? v1
		while (ber[i] != '\0' && x < data->colomn_size)
		{
			if (ber[i] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, generate->mlx_img0, img0.img_widht + x, img0.img_height + y);
			else if (ber[i] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, generate->mlx_img1, img1.img_widht + x, img1.img_height + y);
			else if (ber[i] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, generate->mlx_imgC, imgC.img_widht + x, imgC.img_height + y);
			else if (ber[i] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, generate->mlx_imgE, imgE.img_widht + x, imgE.img_height + y);
			else if (ber[i] == 'P')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, generate->mlx_imgP, imgP.img_widht + x, imgP.img_height + y);
			i++;
			x += 70;
		}
		x = 0;
		y += 70;
	}
}
