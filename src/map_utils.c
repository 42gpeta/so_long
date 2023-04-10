/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:01:31 by gpeta             #+#    #+#             */
/*   Updated: 2023/04/10 18:22:08 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// char	*ft_map_control_extention(char *filename, char *filename_main) // ? v1
// {
// 	int i;
// 	int len;
// 	char *endfile;
// 
// 	if (filename == NULL)
// 	{
// 		filename = filename_main;
// 		printf("** filename du main\n"); // ! a supprimer
// 	}
// 
// 	len = ft_strlen(filename) - 4;
// 	endfile = malloc(sizeof(char) * (4 + 1));
// 	if (!endfile)
// 		return (NULL);
// 		// exit(EXIT_FAILURE);
// 	i = 0;
// 
// 	printf("Filename = %s\n", filename);
// 	while (filename[len] != '\0')
// 	{
// 		endfile[i] = filename[len];
// 		i++;
// 		len++;
// 	}
// 	endfile[i] = '\0';
// 	return (endfile);
// }

/*** Verifie si l'AV 1 est bien remplis  */
char	*ft_map_control_extention(t_data *data, char *filename_main) // ? v2
{
	int i;
	int len;
	char *endfile;

	if (data->filename == NULL)
	{
		data->filename = filename_main;
		printf("** filename du main : %s **\n\n", data->filename); // ! a supprimer
	}
	else
		printf("** filename AV[1] : %s **\n\n", data->filename); // ! a supprimer

	len = ft_strlen(data->filename) - 4;
	endfile = malloc(sizeof(char) * (4 + 1));
	if (!endfile)
		return (NULL);
		// exit(EXIT_FAILURE);
	i = 0;

	// printf("Filename = %s\n", data->filename);
	while (data->filename[len] != '\0')
	{
		endfile[i] = data->filename[len];
		i++;
		len++;
	}
	endfile[i] = '\0';
	return (endfile);
}


/*** Verifie si le fichier est un ".ber"  */
void	ft_map_check_extention(t_data *data, char *filename_main)
{
	char	*file;
	char	*extension;
	int		result;

	extension = ".ber";
	file = ft_map_control_extention(data, filename_main);
	result = ft_strncmp(extension, file, 4);

	if(result == 0)
		printf("STRNCMP s1 == s2 : (%d)\nextension : %s | file : %s\n", result, extension, file); // ! a supprimer
	else
		printf("STRNCMP s1 != s2 : (%d)\nextension : %s | file : %s\n", result, extension, file); // ! a supprimer

	free(file);
}

// char	*ft_generate_string_map(char *file_ber) // ? v1

// char	*ft_generate_string_map(char *file_ber, t_data *data) // ? v2
// {
// 	int		fd;
// 	char	*line;
// 	char	*string_map;
// 
// 	fd = open(file_ber, O_RDONLY);
// 	data->row_size_map = 0;
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
// 	data->colomn_size_map = ft_strlen(string_map);
// 	data->row_size_map++;
// 	line = get_next_line(fd);
// 	data->row_size_map++;
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
// 		data->row_size_map++;
// 	}
// 	free(line);
// 
// 	if (close(fd) == -1)
// 		return (NULL);
// 
// 	return (string_map);
// }

// char	*ft_generate_string_map(char *file_ber, t_data *data) // ? v3
// {
// 	int		fd;
// 	char	*line;
//
// 	fd = open(file_ber, O_RDONLY);
// 	data->row_size_map = 0;
//
// 	/* v3 */ // OK
// 	data->string_map = get_next_line(fd);
// 	data->colomn_size_map = ft_strlen(data->string_map);
// 	data->row_size_map++;
// 	line = get_next_line(fd);
// 	data->row_size_map++;
// 	if (data->string_map == NULL || line == NULL)
// 		printf("c'est NULL 1\n");
// 	while (data->string_map)
// 	{
// 		data->string_map = ft_strjoin_gnl(data->string_map, line);
// 		free(line);
// 		line = get_next_line(fd);
// 		if (line == NULL)
// 			break;
// 		data->row_size_map++;
// 	}
// 	free(line);
//
// 	if (close(fd) == -1)
// 		return (NULL);
//
// 	return (data->string_map);
// }

/*** Génère le string_map dans un tableau  */
void	ft_generate_string_map(t_data *data, t_generate *generate) // ? v4
{
	char	*line;

	generate->fd = open(data->filename, O_RDWR);
	if (generate->fd < 0 || generate->fd > 1024)
		ft_message_error("ft_generate_string_map : Cannot open this !", data, generate);
	data->row_size_map = 0;
	/* v3 */ // OK
	data->string_map = get_next_line(generate->fd);

	data->row_size_map++;
	line = get_next_line(generate->fd);
	data->row_size_map++;
	if (data->string_map == NULL || line == NULL)
		ft_message_error("ft_generate_string_map : First line of this file is empty.", data, generate);
		// printf("c'est NULL 1\n"); // ! a supprimer
	while (data->string_map)
	{
		data->string_map = ft_strjoin_gnl(data->string_map, line);
		free(line);
		line = get_next_line(generate->fd);
		if (line == NULL)
			break;
		data->row_size_map++;
	}
	if (!(data->string_map[0] == '1'))
	{
		// printf("bonjour\n");
		// free(data->string_map);
		close(generate->fd);
		ft_message_error("ft_generate_string_map : First line isn't wall of 1", data, generate);
	}
	free(line);
	if (close(generate->fd) == -1)
		ft_message_error("ft_generate_string_map : Close of file failed.", data, generate);
	ft_generate_string_map_tab(data, generate);
}

/*** Génère le string_map dans un tableau de tableau  */
void	ft_generate_string_map_tab(t_data *data, t_generate *generate)
{
	// generate->string_map_ber_tab = ft_split(data->string_map, '\n'); // ? v1
	data->generate.string_map_ber_tab = ft_split(data->string_map, '\n'); // ? v2
	// data->colomn_size_map = ft_strlen(generate->string_map_ber_tab[0]); // ? v1
	data->colomn_size_map = ft_strlen(data->generate.string_map_ber_tab[0]); // ? v2
	
	data->colomn_size_win = data->colomn_size_map * ECART_XPM;
	data->row_size_win = data->row_size_map * ECART_XPM;
	// int x = 0; // ! a supprimer
	// int y = 0; // ! a supprimer
	//  // ! a supprimer
	// x = 0; // ! a supprimer
	// y = 0; // ! a supprimer
	// while (generate->string_map_ber_tab[y]) // ! a supprimer
	// { // ! a supprimer
	// 	// x = 0; // ! a supprimer
	// 	printf("\n~ string_map_ber_tab[%d] : %s\n", y, generate->string_map_ber_tab[y]); // ! a supprimer
	// 	y++; // ! a supprimer
	// 	// while (generate->string_map_ber_tab[y][x]) // ! a supprimer
	// 	// { // ! a supprimer
	// 	// } // ! a supprimer
	// } // ! a supprimer
}


/*** Génère l'afichage des XPM  */
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
		ft_message_error("ft_generate_xpm : Open xpm 0 fail", data, generate);
		// ft_message_error("Open xpm 0 fail");

 	if (!(generate->mlx_img1 = mlx_xpm_file_to_image(data->mlx_ptr, img1.relative_path, &img1.img_widht, &img1.img_height)))
		ft_message_error("ft_generate_xpm : Open xpm 1 fail", data, generate);
		// ft_message_error("Open xpm 1 fail");

	if (!(generate->mlx_imgC = mlx_xpm_file_to_image(data->mlx_ptr, imgC.relative_path, &imgC.img_widht, &imgC.img_height)))
		ft_message_error("ft_generate_xpm : Open xpm C fail", data, generate);
		// ft_message_error("Open xpm C fail");

 	if (!(generate->mlx_imgE = mlx_xpm_file_to_image(data->mlx_ptr, imgE.relative_path, &imgE.img_widht, &imgE.img_height)))
		ft_message_error("ft_generate_xpm : Open xpm E fail", data, generate);
		// ft_message_error("Open xpm E fail");

	if (!(generate->mlx_imgP = mlx_xpm_file_to_image(data->mlx_ptr, imgP.relative_path, &imgP.img_widht, &imgP.img_height)))
		ft_message_error("ft_generate_xpm : Open xpm P fail", data, generate);
		// ft_message_error("Open xpm P fail");

	// img0.addr = mlx_get_data_addr(generate->mlx_img0, &img0.bpp, &img0.line_len, &img0.endian); // ! fonctionne sans
	// img0.img_widht = 0;
	// img0.img_height = 0;
	// // mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, generate->mlx_img0, img0.img_widht, img0.img_height);

	// // img1.addr = mlx_get_data_addr(generate->mlx_img1, &img1.bpp, &img1.line_len, &img1.endian); // ! fonctionne sans
	// img1.img_widht = 0;
	// img1.img_height = 0;
	// // mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, generate->mlx_img1,img1.img_widht, img1.img_height);

	// // imgC.addr = mlx_get_data_addr(generate->mlx_imgC, &imgC.bpp, &imgC.line_len, &imgC.endian); // ! fonctionne sans
	// imgC.img_widht = 0;
	// imgC.img_height = 0;

	// // imgE.addr = mlx_get_data_addr(generate->mlx_imgE, &imgE.bpp, &imgE.line_len, &imgE.endian); // ! fonctionne sans
	// imgE.img_widht = 0;
	// imgE.img_height = 0;

	// // imgP.addr = mlx_get_data_addr(generate->mlx_imgP, &imgP.bpp, &imgP.line_len, &imgP.endian); // ! fonctionne sans
	// imgP.img_widht = 0;
	// imgP.img_height = 0;


	// char *ber = "212122110111111111111111112";
	
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
	// char *ber = data->string_map;
	// // if (data->row_size_map > WINDOW_HEIGHT_MAX || data->colomn_size_map > WINDOW_WIDHT_MAX)
	// 	// ft_message_error("Error : map's height or map's widht is too big");
	//
	// // while (ber[i] != '\0' || y < WINDOW_HEIGHT) // ? v1
	// while (ber[i] != '\0' || y < data->row_size_win)
	// {
	// 	// while (ber[i] != '\0' && x < WINDOW_WIDHT) // ? v1
	// 	while (ber[i] != '\0' && x < data->colomn_size_win)
	// 	{
	// 		if (ber[i] == '0')
	// 			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, generate->mlx_img0, generate->string_map_ber_tab[x], img0.img_height + y);
	// 			// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, generate->mlx_img0, img0.img_widht + x, img0.img_height + y);
	// 		else if (ber[i] == '1')
	// 			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, generate->mlx_img1, img1.img_widht + x, img1.img_height + y);
	// 		else if (ber[i] == 'C')
	// 			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, generate->mlx_imgC, imgC.img_widht + x, imgC.img_height + y);
	// 		else if (ber[i] == 'E')
	// 			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, generate->mlx_imgE, imgE.img_widht + x, imgE.img_height + y);
	// 		else if (ber[i] == 'P')
	// 			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, generate->mlx_imgP, imgP.img_widht + x, imgP.img_height + y);
	// 		i++;
	// 		x += ECART_XPM;
	// 	}
	// 	x = 0;
	// 	y += ECART_XPM;
	// }

	/* v3 : */
	
	// char **ber = generate->string_map_ber_tab; // ? v1
	char **ber = data->generate.string_map_ber_tab; // ? v2
	
	while (ber[y])
	{
		x = 0;
		while (ber[y][x])
		{
			if (ber[y][x] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, generate->mlx_img0, img0.img_widht * x, img0.img_height * y);
				// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, generate->mlx_img0, generate->string_map_ber_tab[x], img0.img_height + y);
			else if (ber[y][x] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, generate->mlx_img1, img1.img_widht * x, img1.img_height * y);
			else if (ber[y][x] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, generate->mlx_imgC, imgC.img_widht * x, imgC.img_height * y);
			else if (ber[y][x] == 'E')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, generate->mlx_imgE, imgE.img_widht * x, imgE.img_height * y);
			else if (ber[y][x] == 'P')
			{
				// generate->player.pos_y = y; // ? v1
				// generate->player.pos_x = x; // ? v1
				data->generate.player.pos_y = y; // ? v2
				data->generate.player.pos_x = x; // ? v2
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, generate->mlx_imgP, imgP.img_widht * x, imgP.img_height * y);
			}
			x++;
			// x += ECART_XPM;
		}
		y++;
		// y += ECART_XPM;
	}
}
