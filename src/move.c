/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:37:55 by glodi             #+#    #+#             */
/*   Updated: 2023/04/28 19:30:33 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Déplace le personnage vers le haut */
void	ft_move_up(t_data *data) // ? v3
{
    if (data->generate.player.pos_y == data->generate.player.pos_exit_y && data->generate.player.pos_x == data->generate.player.pos_exit_x
        && data->generate.string_map_ber_tab[data->generate.player.pos_y - 1][data->generate.player.pos_x] != '1')
    {
        data->generate.string_map_ber_tab[data->generate.player.pos_y - 1][data->generate.player.pos_x] = 'P';
        data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = 'E';
        data->generate.player.pos_y -= 1;
        data->generate.player.mouvement++;
    }
    else if (data->generate.string_map_ber_tab[data->generate.player.pos_y - 1][data->generate.player.pos_x] == '0'
        || data->generate.string_map_ber_tab[data->generate.player.pos_y - 1][data->generate.player.pos_x] == 'C')
    {
        ft_is_collectible1(data, data->generate.player.pos_y - 1, data->generate.player.pos_x);
        data->generate.string_map_ber_tab[data->generate.player.pos_y - 1][data->generate.player.pos_x] = 'P';
        data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = '0';
        data->generate.player.pos_y -= 1;
        data->generate.player.mouvement++;
    }
    else if (data->generate.string_map_ber_tab[data->generate.player.pos_y - 1][data->generate.player.pos_x] == 'E')
    {
        data->generate.string_map_ber_tab[data->generate.player.pos_y - 1][data->generate.player.pos_x] = 'P';
        data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = '0';
        data->generate.player.pos_y -= 1;
        data->generate.player.mouvement++;
        ft_move_exit(data);
    }
}

/* Déplace le personnage vers le bas */
void	ft_move_down(t_data *data) // ? v3
{
    if (data->generate.player.pos_y == data->generate.player.pos_exit_y && data->generate.player.pos_x == data->generate.player.pos_exit_x
        && data->generate.string_map_ber_tab[data->generate.player.pos_y + 1][data->generate.player.pos_x] != '1')
    {
        data->generate.string_map_ber_tab[data->generate.player.pos_y + 1][data->generate.player.pos_x] = 'P';
        data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = 'E';
        data->generate.player.pos_y += 1;
        data->generate.player.mouvement++;
    } 
    else if (data->generate.string_map_ber_tab[data->generate.player.pos_y + 1][data->generate.player.pos_x] == '0'
        || data->generate.string_map_ber_tab[data->generate.player.pos_y + 1][data->generate.player.pos_x] == 'C')
    {
        ft_is_collectible1(data, data->generate.player.pos_y + 1, data->generate.player.pos_x);
        data->generate.string_map_ber_tab[data->generate.player.pos_y + 1][data->generate.player.pos_x] = 'P';
        data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = '0';
        data->generate.player.pos_y += 1;
        data->generate.player.mouvement++;
    }
    else if (data->generate.string_map_ber_tab[data->generate.player.pos_y + 1][data->generate.player.pos_x] == 'E')
    {
        data->generate.string_map_ber_tab[data->generate.player.pos_y + 1][data->generate.player.pos_x] = 'P';
        data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = '0';
        data->generate.player.pos_y += 1;
        data->generate.player.mouvement++;
        ft_move_exit(data);
    }
}

/* Déplace le personnage vers la gauche */
void	ft_move_left(t_data *data) // ? v2
{
    if (data->generate.player.pos_y == data->generate.player.pos_exit_y && data->generate.player.pos_x == data->generate.player.pos_exit_x
        && data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x - 1] != '1')
    {
        data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x - 1] = 'P';
        data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = 'E';
        data->generate.player.pos_x -= 1;
        data->generate.player.mouvement++;        
    }
    else if (data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x - 1] == '0'
        || data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x - 1] == 'C')
    {
        ft_is_collectible1(data, data->generate.player.pos_y, data->generate.player.pos_x - 1);
        data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x - 1] = 'P';
        data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = '0';
        data->generate.player.pos_x -= 1;
        data->generate.player.mouvement++;
    }
    else if (data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x - 1] == 'E')
    {
        data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x - 1] = 'P';
        data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = '0';
        data->generate.player.pos_x -= 1;
        data->generate.player.mouvement++;
        ft_move_exit(data);
    }
}

// void	ft_move_right(t_data *data) // ? v2
// {
//     if (data->generate.player.pos_y == data->generate.player.pos_exit_y && data->generate.player.pos_x == data->generate.player.pos_exit_x
//         && data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x + 1] != '1')
//     {
//         data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x + 1] = 'P';
//         data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = 'E';
//         data->generate.player.pos_x += 1;        
//     }
//     else if (data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x + 1] == '0'
//         || data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x + 1] == 'C')
//     {
//         // if (data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x + 1] == 'C')
//         //     data->generate.number_of_C--;
//         ft_is_collectible1(data, data->generate.player.pos_y, data->generate.player.pos_x + 1);
//         data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x + 1] = 'P';
//         data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = '0';
//         data->generate.player.pos_x += 1;
        
//     }
//     else if (data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x + 1] == 'E')
//     {
//         data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x + 1] = 'P';
//         data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = '0';
//         data->generate.player.pos_x += 1;
//         if (data->generate.number_of_C == 0)
//         {
//             mlx_destroy_window(data->mlx_ptr, data->win_ptr);
//             data->win_ptr = NULL; // fermeture de la fenêtre       
//         }
//     }
// }

/* Déplace le personnage vers la droite */
void	ft_move_right(t_data *data) // ? v3
{
    if (data->generate.player.pos_y == data->generate.player.pos_exit_y && data->generate.player.pos_x == data->generate.player.pos_exit_x
        && data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x + 1] != '1')
    {
        data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x + 1] = 'P';
        data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = 'E';
        data->generate.player.pos_x += 1;
        data->generate.player.mouvement++;
    }
    else if (data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x + 1] == '0'
        || data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x + 1] == 'C')
    {
        ft_is_collectible1(data, data->generate.player.pos_y, data->generate.player.pos_x + 1);
        data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x + 1] = 'P';
        data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = '0';
        data->generate.player.pos_x += 1;
        data->generate.player.mouvement++;
    }
    else if (data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x + 1] == 'E')
    {
        data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x + 1] = 'P';
        data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = '0';
        data->generate.player.pos_x += 1;
        data->generate.player.mouvement++;
        ft_move_exit(data);
    }
}

/* Vérifie qu'il n'y a plus de collectible */
void    ft_move_exit(t_data *data)
{
        if (data->generate.number_of_C == 0)
        {
            mlx_destroy_window(data->mlx_ptr, data->win_ptr);
            data->win_ptr = NULL;
        }
}
