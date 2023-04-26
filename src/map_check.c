/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:28:04 by gpeta             #+#    #+#             */
/*   Updated: 2023/04/26 17:31:28 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Vérification si map contient 1 : E, C, P */
void	ft_check_content(t_data *data)
{
	int		letter_E;
	int		letter_C;
	int		letter_P;
	int		i;

	letter_E = 0;
	data->generate.number_of_C = 0;
	letter_P = 0;
	i = 0;
	while (data->string_map[i] != '\0')
	{
		if (data->string_map[i] == 'E')
			letter_E++;
		else if (data->string_map[i] == 'C')
			data->generate.number_of_C++;
		else if (data->string_map[i] == 'P')
			letter_P++;
		else if (data->string_map[i] != '1' && data->string_map[i] != '0' && data->string_map[i] != '\n')
			ft_message_error("ft_check_content : This map contain an incorrect symbol !", data);
		i++;
	}
	ft_letter_presence(data, letter_E, letter_C, letter_P);
	ft_parsing(data, data->generate.number_of_C);
}

/* Vérification si map contient + de 1 : E, C, P */
void	ft_letter_presence(t_data *data, int letter_E, int letter_C, int letter_P)
{
		if (letter_E < 1 && letter_C < 1 && letter_P < 1)
			ft_message_error("ft_check_content : Map don't have one E,C and P !", data);
		if (letter_E > 1 || letter_P > 1)
			ft_message_error("ft_check_content : Letter E or P is present more than 1 time", data);
}


/* Vérification si map est un rectangle */
void	ft_check_map_is_an_rectangle(t_data *data) // ? v4
{
	int left;
    int right;

	if (ft_strlen(data->generate.string_map_ber_tab[0]) != ft_strlen(data->generate.string_map_ber_tab[data->row_size_map-1]))
		ft_message_error("ft_check_map_is_an_rectangle : Map is not a rectangle (up and down are not equal)", data);

    left = 0;
    while (data->generate.string_map_ber_tab[left][0] && left < data->row_size_map - 1)
    {
        if (data->generate.string_map_ber_tab[left][0] != '1')
            ft_message_error("ft_check_map_is_an_rectangle : The left side of the map isn't a wall of '1'", data);
        left++;
    }
    right = 0;
    while (data->generate.string_map_ber_tab[right][data->colomn_size_map - 1] && right < data->row_size_map - 1)
    {
        if (data->generate.string_map_ber_tab[right][data->colomn_size_map - 1] != '1')
            ft_message_error("ft_check_map_is_an_rectangle : The right side of the map isn't a wall of '1'", data);
        right++;
    }
	if (left != right)
		ft_message_error("ft_check_map_is_an_rectangle : Map is not a rectangle (left and right are not equal)", data);
	printf("tab[0] = %zu | tab[%d] = %zu\nleft = %d | right = %d\n",ft_strlen(data->generate.string_map_ber_tab[0]), data->row_size_map-1,ft_strlen(data->generate.string_map_ber_tab[data->row_size_map-1]), left, right); // ! a supprimer
	printf("ft_check_map_is_an_rectangle OK !\n"); // ! a supprimer
}

/* Vérification si map est entouré de '1' */
void	ft_check_surrounded_by_one(t_data *data) // ? v4
{
	ft_check_surrounded_by_one_up(data);
	ft_check_surrounded_by_one_down(data);
	ft_check_surrounded_by_one_left(data);
	ft_check_surrounded_by_one_right(data);
	printf("ft_check_surrounded_by_one OK !\n"); // ! a supprimer
}
