/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:37:55 by glodi             #+#    #+#             */
/*   Updated: 2023/04/14 16:05:54 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	ft_move_up(t_data *data) // ? v1
// {
//     if (data->generate.string_map_ber_tab[data->generate.player.pos_y - 1][data->generate.player.pos_x] == '0')
//     {
//         data->generate.string_map_ber_tab[data->generate.player.pos_y - 1][data->generate.player.pos_x] = 'P';
//         data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = '0';
//
//         data->generate.player.pos_y -= 1;
//     }
//     else if (data->generate.string_map_ber_tab[data->generate.player.pos_y - 1][data->generate.player.pos_x] == 'C')
//     {
//         data->generate.string_map_ber_tab[data->generate.player.pos_y - 1][data->generate.player.pos_x] = 'P';
//         data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = '0';
//
//         data->generate.player.pos_y -= 1;
//         data->generate.number_of_C--;
//     }
//     else if (data->generate.string_map_ber_tab[data->generate.player.pos_y - 1][data->generate.player.pos_x] == 'E' && data->generate.number_of_C == 0)
//     {
//         // printf("You finish !\n");
//         data->generate.player.pos_y -= 1;
//         mlx_destroy_window(data->mlx_ptr, data->win_ptr);
//         data->win_ptr = NULL; // fermeture de la fenêtre       
//     }
// }

/* Déplace le personnage vers le haut */
void	ft_move_up(t_data *data) // ? v2
{
    if (data->generate.string_map_ber_tab[data->generate.player.pos_y - 1][data->generate.player.pos_x] == '0'
        || data->generate.string_map_ber_tab[data->generate.player.pos_y - 1][data->generate.player.pos_x] == 'C')
    {
        data->generate.string_map_ber_tab[data->generate.player.pos_y - 1][data->generate.player.pos_x] = 'P';
        data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = '0';
        data->generate.player.pos_y -= 1;

        if (data->generate.string_map_ber_tab[data->generate.player.pos_y - 1][data->generate.player.pos_x] == 'C')
            data->generate.number_of_C--;
    }
    else if (data->generate.string_map_ber_tab[data->generate.player.pos_y - 1][data->generate.player.pos_x] == 'E' && data->generate.number_of_C == 0)
    {
        data->generate.player.pos_y -= 1;
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        data->win_ptr = NULL; // fermeture de la fenêtre       
    }
}

// void	ft_move_down(t_data *data) // ? v1
// {
//     if (data->generate.string_map_ber_tab[data->generate.player.pos_y + 1][data->generate.player.pos_x] == '0')
//     {
//         data->generate.string_map_ber_tab[data->generate.player.pos_y + 1][data->generate.player.pos_x] = 'P';
//         data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = '0';
//
//         data->generate.player.pos_y += 1;
//     }
//     else if (data->generate.string_map_ber_tab[data->generate.player.pos_y + 1][data->generate.player.pos_x] == 'C')
//     {
//         data->generate.string_map_ber_tab[data->generate.player.pos_y + 1][data->generate.player.pos_x] = 'P';
//         data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = '0';
//
//         data->generate.player.pos_y += 1;
//         data->generate.number_of_C--;
//     }
//     else if (data->generate.string_map_ber_tab[data->generate.player.pos_y + 1][data->generate.player.pos_x] == 'E' && data->generate.number_of_C == 0)
//     {
//         data->generate.player.pos_y += 1;
//         mlx_destroy_window(data->mlx_ptr, data->win_ptr);
//         data->win_ptr = NULL; // fermeture de la fenêtre       
//     }    
// }

/* Déplace le personnage vers le bas */
void	ft_move_down(t_data *data) // ? v2
{
    if (data->generate.string_map_ber_tab[data->generate.player.pos_y + 1][data->generate.player.pos_x] == '0'
        || data->generate.string_map_ber_tab[data->generate.player.pos_y + 1][data->generate.player.pos_x] == 'C')
    {
        data->generate.string_map_ber_tab[data->generate.player.pos_y + 1][data->generate.player.pos_x] = 'P';
        data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = '0';
        data->generate.player.pos_y += 1;

        if (data->generate.string_map_ber_tab[data->generate.player.pos_y + 1][data->generate.player.pos_x] == 'C')
            data->generate.number_of_C--;
    }
    else if (data->generate.string_map_ber_tab[data->generate.player.pos_y + 1][data->generate.player.pos_x] == 'E' && data->generate.number_of_C == 0)
    {
        data->generate.player.pos_y += 1;
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        data->win_ptr = NULL; // fermeture de la fenêtre       
    }
}

// void	ft_move_left(t_data *data) // ? v1
// {
//     if (data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x - 1] == '0')
//     {
//         data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x - 1] = 'P';
//         data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = '0';
//
//         data->generate.player.pos_x -= 1;
//     }
//     else if (data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x - 1] == 'C')
//     {
//         data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x - 1] = 'P';
//         data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = '0';
//
//         data->generate.player.pos_x -= 1;
//         data->generate.number_of_C--;
//     }
//     else if (data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x - 1] == 'E' && data->generate.number_of_C == 0)
//     {
//         data->generate.player.pos_x -= 1;
//         mlx_destroy_window(data->mlx_ptr, data->win_ptr);
//         data->win_ptr = NULL; // fermeture de la fenêtre       
//     }
// }

/* Déplace le personnage vers la gauche */
void	ft_move_left(t_data *data) // ? v2
{
    if (data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x - 1] == '0'
        || data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x - 1] == 'C')
    {
        data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x - 1] = 'P';
        data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = '0';
        data->generate.player.pos_x -= 1;

        if (data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x - 1] == 'C')
            data->generate.number_of_C--;
    }
    else if (data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x - 1] == 'E' && data->generate.number_of_C == 0)
    {
        data->generate.player.pos_x -= 1;
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        data->win_ptr = NULL; // fermeture de la fenêtre       
    }
}

// void	ft_move_right(t_data *data)v // ? v1
// {
//     if (data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x + 1] == '0')
//     {
//         data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x + 1] = 'P';
//         data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = '0';
//
//         data->generate.player.pos_x += 1;
//     }
//     else if (data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x + 1] == 'C')
//     {
//         data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x + 1] = 'P';
//         data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = '0';
//
//         data->generate.player.pos_x += 1;
//         data->generate.number_of_C--;
//     }
//     else if (data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x + 1] == 'E' && data->generate.number_of_C == 0)
//     {
//         data->generate.player.pos_x += 1;
//         mlx_destroy_window(data->mlx_ptr, data->win_ptr);
//         data->win_ptr = NULL; // fermeture de la fenêtre       
//     }
// }

/* Déplace le personnage vers la droite */
void	ft_move_right(t_data *data) // ? v2
{
    if (data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x + 1] == '0'
        || data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x + 1] == 'C')
    {
        data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x + 1] = 'P';
        data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = '0';
        data->generate.player.pos_x += 1;

        if (data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x + 1] == 'C')
            data->generate.number_of_C--;
    }
    else if (data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x + 1] == 'E' && data->generate.number_of_C == 0)
    {
        data->generate.player.pos_x += 1;
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        data->win_ptr = NULL; // fermeture de la fenêtre       
    }
}




// void    ft_move_exit(t_data *data)
// {
// /*     if (data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x - 1] == 'E'
//         || data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x + 1] == 'E'
//         || data->generate.string_map_ber_tab[data->generate.player.pos_y - 1][data->generate.player.pos_x] == 'E'
//         || data->generate.string_map_ber_tab[data->generate.player.pos_y + 1][data->generate.player.pos_x] == 'E')
//         // && data->generate.number_of_C == 0 ) */
//     if (data->generate.string_map_ber_tab[data->generate.player.pos_y - 1][data->generate.player.pos_x] == 'E' && data->generate.number_of_C == 0)
//     {
//         data->generate.string_map_ber_tab[data->generate.player.pos_y - 1][data->generate.player.pos_x] = 'P';
//         data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = '0';

//         data->generate.player.pos_y -= 1;
//         if (data->generate.player.pos_y == data->generate.player.pos_exit_y && data->generate.player.pos_x == data->generate.player.pos_exit_x)
//         {
            // printf("You finish !\n");
            // data->generate.player.pos_x += 1;
//             mlx_destroy_window(data->mlx_ptr, data->win_ptr);
//             data->win_ptr = NULL; // fermeture de la fenêtre
//         }
//     }
// }