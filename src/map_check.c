/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:28:04 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/01 17:53:41 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* Checks if the map contains one : E, C, P */
void	ft_check_content(t_data *data)
{
	int		nb_e;
	int		nb_p;
	int		i;

	nb_e = 0;
	nb_p = 0;
	i = 0;
	while (data->str_map[i] != '\0')
	{
		if (data->str_map[i] == 'E')
			nb_e++;
		else if (data->str_map[i] == 'C')
			data->gen.number_of_C++;
		else if (data->str_map[i] == 'P')
			nb_p++;
		else if (data->str_map[i] != '1' && data->str_map[i] != '0'
			&& data->str_map[i] != '\n')
			ft_message_error("This map contain an incorrect symbol !", data);
		i++;
	}
	ft_nb_presence(data, nb_e, data->gen.number_of_C, nb_p);
	ft_parsing(data, data->gen.number_of_C);
}

/* Checks if the map contains more than one : E, C, P */
void	ft_nb_presence(t_data *data, int nb_e, int nb_c, int nb_p)
{
	if (nb_e < 1 && nb_c < 1 && nb_p < 1)
		ft_message_error("Map don't have one E,C and P !", data);
	if (nb_e > 1 || nb_p > 1)
		ft_message_error("Letter E or P is present more than 1 time", data);
}

/* Checks if the map is am rectangle */
void	ft_check_map_is_an_rectangle(t_data *data)
{
	int		left;
	int		right;
	int		lst_line;

	lst_line = ft_strlen(data->gen.str_tab[data->row_size_map - 1]);
	if (ft_strlen(data->gen.str_tab[0]) != lst_line)
		ft_message_error("Map isn't a rectangle (look up and down)", data);
	left = 0;
	while (data->gen.str_tab[left][0] && left < data->row_size_map - 1)
	{
		if (data->gen.str_tab[left][0] != '1')
			ft_message_error("Map's left side isn't a wall of '1'", data);
		left++;
	}
	right = 0;
	while (data->gen.str_tab[right][data->colomn_size_map - 1]
		&& right < data->row_size_map - 1)
	{
		if (data->gen.str_tab[right][data->colomn_size_map - 1] != '1')
			ft_message_error("Map's right side isn't a wall of '1'", data);
		right++;
	}
	if (left != right)
		ft_message_error("Map isn't a rectangle (look left and right)", data);
}

/* Checks if map is surronded bye '1' */
void	ft_check_surrounded_by_one(t_data *data)
{
	ft_check_surrounded_by_one_up(data);
	ft_check_surrounded_by_one_bottom(data);
	ft_check_surrounded_by_one_left(data);
	ft_check_surrounded_by_one_right(data);
}
