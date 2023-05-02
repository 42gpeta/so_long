/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:01:31 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/01 14:52:29 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_string_map(t_data *data)
{
	if (data->str_map[0] != '1')
	{
		if (close(data->gen.fd) == -1)
			ft_message_error("Close of file failed.", data);
		ft_message_error("First line isn't wall of 1", data);
	}
}

/*** Create an array of array of str_map */
void	ft_generate_string_map_tab(t_data *data)
{
	data->gen.str_tab = ft_split(data->str_map, '\n');
	data->gen.str_map_pathfinding = ft_split(data->str_map, '\n');
	data->colomn_size_map = ft_strlen(data->gen.str_tab[0]);
	data->colomn_size_win = data->colomn_size_map * ECART_XPM;
	if (data->colomn_size_win > WINDOW_WIDHT_MAX)
		ft_message_error("Map to big. (widht)", data);
	data->row_size_win = data->row_size_map * ECART_XPM;
	if (data->row_size_win > WINDOW_HEIGHT_MAX)
		ft_message_error("Map to big. (height)", data);
}

/*** Convert $(map).ber to multiple arrays */
void	ft_generate_string_map(t_data *data)
{
	char	*line;

	data->gen.fd = open(data->filename, O_RDWR);
	if (data->gen.fd < 0 || data->gen.fd > 1024)
		ft_message_error("Cannot open this !", data);
	data->row_size_map = 0;
	data->str_map = get_next_line(data->gen.fd);
	data->row_size_map++;
	line = get_next_line(data->gen.fd);
	data->row_size_map++;
	if (data->str_map == NULL || line == NULL)
		ft_message_error("First line of this file is empty.", data);
	while (data->str_map)
	{
		data->str_map = ft_strjoin_gnl(data->str_map, line);
		free(line);
		line = get_next_line(data->gen.fd);
		if (line == NULL)
			break ;
		data->row_size_map++;
	}
	free(line);
	ft_check_string_map(data);
	ft_generate_string_map_tab(data);
}
