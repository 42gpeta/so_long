/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 16:01:22 by gpeta             #+#    #+#             */
/*   Updated: 2023/03/24 12:11:58 by gpeta            ###   ########.fr       */
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
	// char	*file_xpm1 = "lib/libmlx/test/open30.xpm";
	// char	*file_xpm2 = "maps/xpm/basketball.xpm";
	char	*file_ber = "maps/map1.ber";

	data.file_xpm1 = "lib/libmlx/test/open30.xpm";
	data.file_xpm2 = "maps/xpm/basketball.xpm";
	
/* ************************************************************************** */
/*							      	 MAPS								      */
/* ************************************************************************** */
	
	printf("AV[1] = %s\n", av[1]);
	/* #1 version */
	// ft_map_control_extention(av[1], file_ber);
	// printf("Extension = %s\n\n", ft_map_control_extention(file_ber, &av[1]));

	/* #2 version */
	ft_map_check_extention(av[1], file_ber);
	generate.string_map_ber = ft_generate_string_map(file_ber);
	printf("\n****\tMAP\t****\n\n%s\n\n********************\n\n", generate.string_map_ber);


/* ************************************************************************** */
/*							       GRAPHIQUE							      */
/* ************************************************************************** */

/* Initialisation du programme */
	data.mlx_ptr = mlx_init();
	if (data.mlx_ptr == NULL)
		(ft_message_error_mlx_init("MLX_INIT FAIL"));

/* Ouverture de la fenêtre en affichant le nom du programme en haut */
	// data.win_ptr = mlx_new_window(data.mlx_ptr, 1920, 1080, av[0]);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDHT, WINDOW_HEIGHT, av[0]);
	if (data.win_ptr == NULL)
	{
		free(data.win_ptr);
		(ft_message_error_mlx_init("MLX_NEW_WINDOW FAIL"));
	}


/* Chemin du fichier .xpm */
	// data.img.relative_path = av[1]; // avec nom du fichier dans av[1]
	//
	// img1.relative_path = file_xpm1;
	// img2.relative_path = file_xpm2;

/* Création d'une image */ // OK
		/* Pixel */
	// data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDHT, WINDOW_HEIGHT);
	// data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
		/* XPM */
	// if (!(data.img.mlx_img = mlx_xpm_file_to_image(data.mlx_ptr, data.img.relative_path, &data.img.img_widht, &data.img.img_height)))
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
	// if (!(data.img.mlx_img = mlx_xpm_file_to_image(data.mlx_ptr, data.img.relative_path, &data.img.img_widht, &data.img.img_height)))
	// {
	// 	printf("KO mlx_xpm_file_to_image\n\n");
	// 	return(1);
	// }
	// 
	// data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	// data.img.img_widht = 0;
	// data.img.img_height = 0;
	// printf("OK (bpp: %d, line_len: %d, endian: %d)\n",data.img.bpp, data.img.line_len, data.img.endian);
	// printf("ligne l1= %d\n", data.img.img_height);
	// 
	// while (data.img.img_widht < WINDOW_WIDHT)
	// {
	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.mlx_img,data.img.img_widht, data.img.img_height);
	// data.img.img_widht += 50;
	// }
	// 
	// data.img.img_widht = 0; // remise a 0 pour revenir a la premiere colone (x ; weidht)
	// data.img.img_height += 60; // saut de ligne 
	// printf("ligne l2= %d\n", data.img.img_height);
	// 
	// while (data.img.img_widht < WINDOW_WIDHT)
	// {
	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.mlx_img, data.img.img_widht, data.img.img_height);
	// data.img.img_widht += 50;
	// }
	
/* Création de plusieurs lignes de la même image automatisé */ // OK
		/* XPM */
	// if (!(data.img.mlx_img = mlx_xpm_file_to_image(data.mlx_ptr, data.img.relative_path, &data.img.img_widht, &data.img.img_height)))
	// {
	// 	printf("KO mlx_xpm_file_to_image\n\n");
	// 	return(1);
	// }
	// 
	// data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	// data.img.img_widht = 0;
	// data.img.img_height = 0;
	// 
	// while (data.img.img_height < WINDOW_HEIGHT)
	// {
	// 	while (data.img.img_widht < WINDOW_WIDHT)
	// 	{
	// 	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img.mlx_img,data.img.img_widht, data.img.img_height);
	// 	data.img.img_widht += 50;
	// 	}
	// 	data.img.img_height += 60;
	// 	data.img.img_widht = 0;
	// }

/* Affichage de 2 XPM */
		/* XPM */
	// if (!(img1.mlx_img = mlx_xpm_file_to_image(data.mlx_ptr, img1.relative_path, &img1.img_widht, &img1.img_height)))
	// 	ft_message_error_mlx_init("Error open xpm 1 \n");
 	// if (!(img2.mlx_img = mlx_xpm_file_to_image(data.mlx_ptr, img2.relative_path, &img2.img_widht, &img2.img_height)))
	// 	ft_message_error_mlx_init("Error open xpm 2 \n");
	// 
	// img1.addr = mlx_get_data_addr(img1.mlx_img, &img1.bpp, &img1.line_len, &img1.endian);
	// img1.img_widht = 0;
	// img1.img_height = 0;
	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img1.mlx_img, img1.img_widht, img1.img_height);
	// 
	// img2.addr = mlx_get_data_addr(img2.mlx_img, &img2.bpp, &img2.line_len, &img2.endian);
	// img2.img_widht = 50;
	// img2.img_height = 50;
	// mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, img2.mlx_img,img2.img_widht, img2.img_height);


/* Affichage XPM selon chiffre de la map .ber */
		/* XPM */
	ft_generate_xpm(&data, &generate);

/* Permet d'arrêter le programme si on ne met pas de 'mlx_loop_hook'  */
	// mlx_loop_hook(data.mlx_ptr, &ft_no_event, &data);

/* Print d'un pixel/image */
	// mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_loop_hook(data.mlx_ptr, &render_no_action, &data);

/* Bouton croix pour fermer la fenêtre */
	mlx_hook(data.win_ptr, ClientMessage, StructureNotifyMask, &ft_bouton_red_cross, &data);

/* Gestion touche echap, W, A, S, D */
// mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &ft_close_s_keypress, &data);
//	mlx_key_hook(data.win_ptr, &ft_close_s_keypress, &data);
	mlx_key_hook(data.win_ptr, &ft_key_hook, &data);

	
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
	// mlx_destroy_image(data.mlx_ptr, &img1.mlx_img);
	// mlx_destroy_image(data.mlx_ptr, &img2.mlx_img);
	mlx_destroy_image(data.mlx_ptr, generate.mlx_img1);
	mlx_destroy_image(data.mlx_ptr, generate.mlx_img2);
	mlx_destroy_display(data.mlx_ptr);
	free(data.mlx_ptr);


	return (0);
}


/* int main(void)		// v1 : sans structure
{
	void	*mlx_ptr;
	void	*win_ptr;

// ** Initialisation du programme **
	mlx_ptr = mlx_init();
	if (!mlx_ptr)
		return (1);

// ** Ouverture de la fenêtre **
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "first_windows");
	if (!win_ptr)
		return (1);

// ** Nettoyage de fenêtre **
	



// ** Boucle infini qui attend des actions **
	mlx_loop(mlx_ptr);

	// printf("cool\n");
	return (0);
} */