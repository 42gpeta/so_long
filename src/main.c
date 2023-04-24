/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:01:22 by gpeta             #+#    #+#             */
/*   Updated: 2023/04/24 20:46:11 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int main(int ac, char **av)		// v2 : avec structure
{
	t_data	data;
	t_generate generate;
	// t_img	img1;
	// t_img	img2;
	int		compteurWASD = 0;
	char	*file_ber = "maps/good/map-sujet.ber";
	// char	*file_ber = "maps/map1.ber";

	// data.path_xpm0 = "lib/libmlx/test/open30.xpm";

	int		element = 0;
	char * str;

/* ************************************************************************** */
/*							      	 FILES XPM							      */
/* ************************************************************************** */


	data.path_xpm0 = "maps/xpm/sol_foret.xpm";
	data.path_xpm1 = "maps/xpm/tree.xpm";
	data.path_xpmC = "maps/xpm/framboise.xpm";
	data.path_xpmE = "maps/xpm/sortie_foret.xpm";
	data.path_xpmP = "maps/xpm/randonneur.xpm";

/* ************************************************************************** */
/*							      	 MAPS								      */
/* ************************************************************************** */
	
	// data.string_map = 0;
	// data.generate.string_map_ber_tab = 0;
	// generate.string_map_ber = 0;
	// generate.string_map_ber_tab = 0;
	data.mlx_ptr = 0;
	data.generate.player.mouvement = 0;
	
	printf("AV[1] = %s\n", av[1]);
	data.filename = av[1];
	/* #1 version */
	// ft_map_control_extention(av[1], file_ber);
	// printf("Extension = %s\n\n", ft_map_control_extention(file_ber, &av[1]));

	/* extention */
	ft_map_check_extention(&data, file_ber);
	// generate.string_map_ber = ft_generate_string_map(&data, &generate);
	// str = ft_generate_string_map(&data, &generate);
	// generate.string_map_ber = str;
	ft_generate_string_map(&data);
	// data.colomn_size_map *= ECART_XPM; // ! test
	// data.row_size_map *= ECART_XPM; // ! test
	// printf("\n****\tMAP\t****\n\n%s\n\n********************\n\n", generate.string_map_ber);
	printf("\n****\tMAP\t****\n\n%s\n\n********************\n\n", data.string_map);
	printf("x / widht = %d \ny / height = %d\n\n", data.colomn_size_win, data.row_size_win);

	/* map's content */
	ft_check_content(&data);
	ft_check_surrounded_by_one(&data);
	ft_check_map_is_an_rectangle(&data);


/* ************************************************************************** */
/*							       GRAPHIQUE							      */
/* ************************************************************************** */

/* Initialisation du programme */
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		(ft_message_error("MLX_INIT FAIL", &data));
		// (ft_message_error("MLX_INIT FAIL"));

/* Ouverture de la fenêtre en affichant le nom du programme en haut */
	// data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1080, av[0]);
	// data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDHT, WINDOW_HEIGHT, av[0]); // ? v1
	data.win_ptr = mlx_new_window(data.mlx_ptr, data.colomn_size_win, data.row_size_win, av[0]); // ? v2
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		(ft_message_error("MLX_NEW_WINDOW FAIL", &data));
		// (ft_message_error("MLX_NEW_WINDOW FAIL"));
	}


/* Chemin du fichier .xpm */
	// data.img.relative_path = av[1]; // avec nom du fichier dans av[1]
	//
	// img1.relative_path = path_xpm0;
	// img2.relative_path = path_xpm1;

/* Création d'une " image " "*/ // OK
		/* Pixel */
	// data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDHT, WINDOW_HEIGHT);
	// data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
		/* XPM */
	// if (!(data.img.mlx_img = mlx_xpm_file_to_image(data.mlx_ptr, data.path_xpm0, &data.img.widht, &data.img.height)))
	// {
	// 	printf("KO mlx_xpm_file_to_image\n\n");
	// 	return(1);
	// }
	//
	// data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	// printf("OK (bpp: %d, line_len: %d, endian: %d)\n",data.img.bpp, data.img.line_len, data.img.endian);
	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.mlx_img, 0, 0);
	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.mlx_img, 50, 0);

/* Création de plusieurs lignes d'images */ // OK
		/* XPM */
	// if (!(data.img.mlx_img = mlx_xpm_file_to_image(data.mlx_ptr, data.img.relative_path, &data.img.widht, &data.img.height)))
	// {
	// 	printf("KO mlx_xpm_file_to_image\n\n");
	// 	return(1);
	// }
	// 
	// data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	// data.img.widht = 0;
	// data.img.height = 0;
	// printf("OK (bpp: %d, line_len: %d, endian: %d)\n",data.img.bpp, data.img.line_len, data.img.endian);
	// printf("ligne l1= %d\n", data.img.height);
	// 
	// while (data.img.widht < WINDOW_WIDHT)
	// {
	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.mlx_img,data.img.widht, data.img.height);
	// data.img.widht += 50;
	// }
	// 
	// data.img.widht = 0; // remise a 0 pour revenir a la premiere colone (x ; weidht)
	// data.img.height += 60; // saut de ligne 
	// printf("ligne l2= %d\n", data.img.height);
	// 
	// while (data.img.widht < WINDOW_WIDHT)
	// {
	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.mlx_img, data.img.widht, data.img.height);
	// data.img.widht += 50;
	// }
	
/* Création de plusieurs lignes de la même image automatisé */ // OK
		/* XPM */
	// if (!(data.img.mlx_img = mlx_xpm_file_to_image(data.mlx_ptr, data.img.relative_path, &data.img.widht, &data.img.height)))
	// {
	// 	printf("KO mlx_xpm_file_to_image\n\n");
	// 	return(1);
	// }
	// 
	// data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	// data.img.widht = 0;
	// data.img.height = 0;
	// 
	// while (data.img.height < WINDOW_HEIGHT)
	// {
	// 	while (data.img.widht < WINDOW_WIDHT)
	// 	{
	// 	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.mlx_img,data.img.widht, data.img.height);
	// 	data.img.widht += 50;
	// 	}
	// 	data.img.height += 60;
	// 	data.img.widht = 0;
	// }

/* Affichage de 2 XPM */
		/* XPM */
	// if (!(img1.mlx_img = mlx_xpm_file_to_image(data.mlx_ptr, img1.relative_path, &img1.widht, &img1.height)))
	// 	ft_message_error("Error open xpm 1 \n");
 	// if (!(img2.mlx_img = mlx_xpm_file_to_image(data.mlx_ptr, img2.relative_path, &img2.widht, &img2.height)))
	// 	ft_message_error("Error open xpm 2 \n");
	// 
	// img1.addr = mlx_get_data_addr(img1.mlx_img, &img1.bpp, &img1.line_len, &img1.endian);
	// img1.widht = 0;
	// img1.height = 0;
	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img1.mlx_img, img1.widht, img1.height);
	// 
	// img2.addr = mlx_get_data_addr(img2.mlx_img, &img2.bpp, &img2.line_len, &img2.endian);
	// img2.widht = 50;
	// img2.height = 50;
	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img2.mlx_img,img2.widht, img2.height);


/* Affichage XPM selon chiffre de la map .ber */
		/* XPM */
	// ft_generate_xpm(&data, &generate); // ? v1
	ft_generate_path_file(&data); // ? v2
/* Permet d'arrêter le programme si on ne met pas de 'mlx_loop_hook'  */
	// mlx_loop_hook(data.mlx_ptr, &ft_no_event, &data);

/* Print d'un pixel/image */
	// mlx_loop_hook(data.mlx_ptr, &render, &data);
	// mlx_loop_hook(data.mlx_ptr, &render_no_action, &data); // ? v1
	mlx_loop_hook(data.mlx_ptr, &render_no_action, &data); // ? v2

/* Bouton croix pour fermer la fenêtre */
	mlx_hook(data.win_ptr, ClientMessage, StructureNotifyMask, &ft_bouton_red_cross, &data);

/* Gestion touche echap, W, A, S, D */
	// mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &ft_close_s_keypress, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &ft_key_hook, &data);
	//	mlx_key_hook(data.win_ptr, &ft_close_s_keypress, &data);
	// mlx_key_hook(data.win_ptr, &ft_key_hook, &data);


/* Autres touche dont W, A, S, D */ // ne marche pas pour l'instant
	// while ((mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &ft_key_hook, &data) == 119))
	// {
	// 	printf("------------------\nCOMPTEUR MVT : %d\n------------------\n", compteurWASD);
	// 	compteurWASD++;
	// }


	// mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &ft_key_hook, &data);


/* Boucle infini qui attend des actions */
	mlx_loop(data.mlx_ptr);

/* Fermeture fenêtre */
	// mlx_destroy_image(data.mlx_ptr, data.path_xpm0);
	// mlx_destroy_image(data.mlx_ptr, &img2.mlx_img);

	mlx_destroy_image(data.mlx_ptr, data.generate.mlx_img0);
	mlx_destroy_image(data.mlx_ptr, data.generate.mlx_img1);
	mlx_destroy_image(data.mlx_ptr, data.generate.mlx_imgC);
	mlx_destroy_image(data.mlx_ptr, data.generate.mlx_imgE);
	mlx_destroy_image(data.mlx_ptr, data.generate.mlx_imgP);
	mlx_destroy_display(data.mlx_ptr);
	// free(generate.map.up);
	// free(generate.map.down);
	while (data.generate.string_map_ber_tab[element])
		free(data.generate.string_map_ber_tab[element++]);
	while (data.generate.string_map_pathfinding[element])
		free(data.generate.string_map_pathfinding[element++]);
	free(data.generate.string_map_ber_tab);
	free(data.generate.string_map_pathfinding);
	free(data.string_map);
	free(data.mlx_ptr);

	return (0);
}
