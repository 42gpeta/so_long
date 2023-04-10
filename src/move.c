/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glodi <glodi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 11:37:55 by glodi             #+#    #+#             */
/*   Updated: 2023/04/10 17:02:04 by glodi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Déplace le personnage vers le haut */
void	ft_move_up(t_data *data, t_generate *generate)
{
    // char **first;
 
    // first = data->generate.string_map_ber_tab;
    // first = generate->string_map_ber_tab;
    // printf("pos before ft_move_up %c\n", first[0][0]);
    // printf("pos before ft_move_up %c\n", generate->string_map_ber_tab[0][0]);
    // printf("pos before ft_move_up %s\n", generate->string_map_ber[0]);

    data->generate.string_map_ber_tab[data->generate.player.pos_y - 1][data->generate.player.pos_x] = 'P';
    data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = '0';
    // generate->string_map_ber_tab[generate->player.pos_y - 1][generate->player.pos_x] = 'P';
    // generate->string_map_ber_tab[generate->player.pos_y][generate->player.pos_x] = '0';

    data->generate.player.pos_y -= 1;
    // generate->player.pos_y -= 1;
    ft_generate_xpm(data, generate);
    // printf("ft_generate_xpm : pos player : [%d][%d]\n", data->generate.player.pos_y, data->generate.player.pos_x); // ? v2

}


/* Déplace le personnage vers le bas */
void	ft_move_down(t_data *data, t_generate *generate)
{
    data->generate.string_map_ber_tab[data->generate.player.pos_y + 1][data->generate.player.pos_x] = 'P';
    data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = '0';

    data->generate.player.pos_y += 1;
    ft_generate_xpm(data, generate);
    
}


/* Déplace le personnage vers la gauche */
void	ft_move_left(t_data *data, t_generate *generate)
{
    data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x - 1] = 'P';
    data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = '0';

    data->generate.player.pos_x -= 1;
    ft_generate_xpm(data, generate);
    
}


/* Déplace le personnage vers la droite */
void	ft_move_right(t_data *data, t_generate *generate)
{
    data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x + 1] = 'P';
    data->generate.string_map_ber_tab[data->generate.player.pos_y][data->generate.player.pos_x] = '0';

    data->generate.player.pos_x += 1;
    ft_generate_xpm(data, generate);
    
}

