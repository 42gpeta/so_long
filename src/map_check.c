/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:28:04 by gpeta             #+#    #+#             */
/*   Updated: 2023/03/31 18:03:40 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
* OK	1) regarder si map contient E C P 
*	géré les doublons
* 
* 2) carte rectangulaire
* 
* ON WORK	3) carte entouré de 1
* 
* 4) chemin valide
 */

/* Vérification si map contient 1 : E, C, P */
void	ft_check_content(t_generate *generate, t_data *data)
{
	int		letter_E;
	int		letter_C;
	int		letter_P;
	int		i;

	letter_E = 0;
	letter_C = 0;
	letter_P = 0;
	i = 0;

	while (data->string_map[i] != '\0')
	{
		if (data->string_map[i] == 'E')
			letter_E++;
		else if (data->string_map[i] == 'C')
			letter_C++;
		else if (data->string_map[i] == 'P')
			letter_P++;
		i++;
	}
	generate->number_of_C = letter_C;
	if (letter_E < 1 && letter_C < 1 && letter_P < 1)
		ft_message_error("Map don't have one E,C and P !", data, generate);
		// ft_message_error("Map don't have one E,C and P !");
	if (letter_E > 1 || letter_P > 1)
		ft_message_error("Letter E or P is present more than 1 time", data, generate);
		// ft_message_error("Letter E or P is present more than 1 time");
}

/* Vérification si map contient + de 1 : E, C, P */
// void	ft_check_content_doublon(t_generate *generate) // ! non utilisée
// {
// 	int		letter_E;
// 	int		letter_P;
// 	int		i;
// 
// 	letter_E = 0;
// 	letter_P = 0;
// 	i = 0;
// 
// 	while (generate->string_map_ber[i] != '\0')
// 	{
// 		if (generate->string_map_ber[i] == 'e')
// 		{
// 			letter_E++;
// 			if (letter_E > 1)
// 				ft_message_error("Double exit on the map !");
// 		}
// 		else if (generate->string_map_ber[i] == 'p')
// 		{
// 			letter_P++;
// 			if (letter_P > 1)
// 				ft_message_error("Double character on the map !");
// 		}
// 		i++;
// 	}
// }

/* Vérification si map est un rectangle */ // TODO 
// void	ft_check_map_is_an_rectangle()

/* Vérification si map est entouré de 1 */ // TODO 
// void	ft_check_surrounded_by_one(t_generate *generate) // ? v1
// {
// 	char **first;
// 
// 	*first = generate->map.up;
// 
// 	*first = (char *)ft_split(generate->string_map_ber, '\n');
// 	generate->map.down = ft_substr(generate->string_map_ber,
// 		(ft_strlen(generate->string_map_ber) - ft_strlen(ft_strrchr(generate->string_map_ber, '\n'))),
// 		(ft_strlen(generate->string_map_ber) - (ft_strlen(generate->string_map_ber) - ft_strlen(ft_strrchr(generate->string_map_ber, '\n')))));
// 	// printf("up : %s\ndown : %s\n", generate->map.up, generate->map.down);
// 	printf("up : %s\ndown : %s\n", *first, generate->map.down);
// }

void	ft_check_surrounded_by_one(t_generate *generate, t_data *data) // ? v2  // TODO finir la vérif des côtés
{
	int i;

	i = 0;
	generate->map.up = 0;
	generate->map.down = 0;

	generate->map.up = ft_substr(data->string_map, 0, (ft_strlen(data->string_map) - ft_strlen(ft_strchr(data->string_map, '\n'))));

	generate->map.down = ft_substr(data->string_map,
		(ft_strlen(data->string_map) - ft_strlen(ft_strrchr(data->string_map, '\n'))) + 1,
		(ft_strlen(data->string_map) - (ft_strlen(data->string_map) - ft_strlen(ft_strrchr(data->string_map, '\n')))));
	printf("up :\n%s\ndown :\n%s\n", generate->map.up, generate->map.down);

	if (generate->map.up[i] != '1' || generate->map.down[i] != '1')
		ft_message_error("Wall on top or on bottom is not complete. (1)", data, generate);
	while (generate->map.up[i] == '1' && generate->map.down[i] == '1')
	{
		if (generate->map.up[i] != '1' || generate->map.down[i] != '1')
			ft_message_error("Wall on top or on bottom is not complete. (2)", data, generate);
		i++;
		// generate->map.up++;
		// generate->map.down++;
	}
}

/* Vérification s'il est possible de sortir de la map */
// void	ft_check_possible_exit()  // TODO 


