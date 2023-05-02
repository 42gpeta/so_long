/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_string_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:33:05 by gpeta             #+#    #+#             */
/*   Updated: 2023/05/02 20:39:15 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*** Checks av[1] and ac */
void	ft_map_control_extention(t_data *data, char *filename_main, int ac)
{
	data->ac = ac;
	if (ac != 2)
		ft_message_error("You can write only 1 parameter", data);
	data->filename = filename_main;
	if (data->filename == NULL)
		ft_message_error("The program need 1 parameter", data);
}

/*** Checks the map's file extension */
void	ft_map_check_extention(t_data *data)
{
	char	*file;
	char	*extension;
	int		result;

	file = 0;
	extension = ".ber";
	file = ft_strrchr(data->filename, '.');
	data->gen.fd = open(data->filename, O_RDWR);
	if (!file || !data->gen.fd)
		ft_message_error("Check the parameter", data);
	result = ft_strncmp(extension, file, 4);
	if (result != 0)
		ft_message_error("Check extension's program", data);
}
