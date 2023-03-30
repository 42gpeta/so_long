/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 15:28:04 by gpeta             #+#    #+#             */
/*   Updated: 2023/03/30 16:39:49 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
* 1) regarder si map contient E C P 
*	géré les doublons
* 
* 2) carte rectangulaire
* 
* 3) carte entouré de 1
* 
* 4) chemin valide
 */

/* Vérification si map contient 1 : E, C, P */
void	ft_check_content(t_generate *generate)
{
	int		letter_E;
	int		letter_C;
	int		letter_P;
	int		i;

	letter_E = 0;
	letter_C = 0;
	letter_P = 0;
	i = 0;

	while (generate->string_map_ber[i] != '\0')
	{
		if (generate->string_map_ber[i] == 'E')
			letter_E++;
		else if (generate->string_map_ber[i] == 'C')
			letter_C++;
		else if (generate->string_map_ber[i] == 'P')
			letter_P++;
		i++;
	}
	generate->number_of_C = letter_C;
	if (letter_E < 1 && letter_C < 1 && letter_P < 1)
		ft_message_error("Map don't have one E,C and P !");
	if (letter_E > 1 || letter_P > 1)
		ft_message_error("Letter E or P is present more than 1 time");
}

/* Vérification si map contient + de 1 : E, C, P */
// void	ft_check_content_doublon(t_generate *generate) // ! non utilisée
// {
// 	int		letter_E;
// 	int		letter_P;
// 	int		i;

// 	letter_E = 0;
// 	letter_P = 0;
// 	i = 0;

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

/* Vérification si map est un rectangle */
// void	ft_check_map_is_an_rectangle()

/* Vérification si map est entouré de 1 */
// void	ft_check_surrounded_by_one()

/* Vérification s'il est possible de sortir de la map */
// void	ft_check_possible_exit()


