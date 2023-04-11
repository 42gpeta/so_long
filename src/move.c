/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:37:55 by glodi             #+#    #+#             */
/*   Updated: 2023/04/11 14:54:02 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Déplace le personnage vers le haut */
void	ft_move_up(t_data *data)
{
    if (data->generate.string_map_ber_tab[data->generate.player.pos_y - 1][data->generate.player.pos_x] == '0')
    {
        data->generate.string_map_ber_tab[data->generate.player.pos_y - 1][data->generate.player.pos_x] = 'P';
        data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = '0';

        data->generate.player.pos_y -= 1;
        // ft_generate_xpm(data, generate);
    }
    else if (data->generate.string_map_ber_tab[data->generate.player.pos_y - 1][data->generate.player.pos_x] == 'C')
    {
        data->generate.string_map_ber_tab[data->generate.player.pos_y - 1][data->generate.player.pos_x] = 'P';
        data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = '0';

        data->generate.player.pos_y -= 1;
        data->generate.number_of_C--;
        // ft_generate_xpm(data, generate);        
    }
}


/* Déplace le personnage vers le bas */
void	ft_move_down(t_data *data)
{
    if (data->generate.string_map_ber_tab[data->generate.player.pos_y + 1][data->generate.player.pos_x] == '0')
    {
        data->generate.string_map_ber_tab[data->generate.player.pos_y + 1][data->generate.player.pos_x] = 'P';
        data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = '0';

        data->generate.player.pos_y += 1;
        // ft_generate_xpm(data, generate);
    }
    else if (data->generate.string_map_ber_tab[data->generate.player.pos_y + 1][data->generate.player.pos_x] == 'C')
    {
        data->generate.string_map_ber_tab[data->generate.player.pos_y + 1][data->generate.player.pos_x] = 'P';
        data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = '0';

        data->generate.player.pos_y += 1;
        data->generate.number_of_C--;
        // ft_generate_xpm(data, generate);        
    }    
}


/* Déplace le personnage vers la gauche */
void	ft_move_left(t_data *data)
{
    if (data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x - 1] == '0')
    {
        data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x - 1] = 'P';
        data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = '0';

        data->generate.player.pos_x -= 1;
        // ft_generate_xpm(data, generate);
    }
    else if (data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x - 1] == 'C')
    {
        data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x - 1] = 'P';
        data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = '0';

        data->generate.player.pos_x -= 1;
        data->generate.number_of_C--;
        // ft_generate_xpm(data, generate);        
    }    
}


/* Déplace le personnage vers la droite */
void	ft_move_right(t_data *data)
{
    if (data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x + 1] == '0')
    {
        data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x + 1] = 'P';
        data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = '0';

        data->generate.player.pos_x += 1;
        // ft_generate_xpm(data, generate);
    }
    else if (data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x + 1] == 'C')
    {
        data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x + 1] = 'P';
        data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = '0';

        data->generate.player.pos_x += 1;
        data->generate.number_of_C--;
        // ft_generate_xpm(data, generate);        
    }
}

// void    ft_move_verif(t_data *data)
// {
//     if (data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x - 1] != '0')
//         ft_message_error("ft_move_verif : ce")
// }