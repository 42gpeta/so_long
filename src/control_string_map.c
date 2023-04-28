/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_string_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 14:33:05 by gpeta             #+#    #+#             */
/*   Updated: 2023/04/28 14:34:22 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


/*** Verifie si l'AV 1 est bien remplis  */
void	ft_map_control_extention(t_data *data, char *filename_main) // ? v3
{
	data->filename = filename_main;
	if (data->filename == NULL)
		ft_message_error("The program need 1 parameter", data);
}

/*** Verifie si le fichier est un ".ber" valide  */
void	ft_map_check_extention(t_data *data, char *filename_main)
{
	char	*file;
	char	*extension;
	int		result;

	file = 0;
	extension = ".ber";
	if (!(file = ft_strrchr(data->filename, '.'))
		|| !(data->generate.fd = open(data->filename, O_RDWR)))
		ft_message_error("Check the parameter", data);
	result = ft_strncmp(extension, file, 4);
	if (result != 0)
		ft_message_error("Check extension's program", data);
}
