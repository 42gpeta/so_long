/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpeta <gpeta@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:46:33 by gpeta             #+#    #+#             */
/*   Updated: 2023/03/31 14:43:04 by gpeta            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	f_len(const char *s, char c);
static int	f_count(const char *s, char c);
static char	*f_strndup(const char *s, int nj);
static void	f_ntab_free(char **tab, int nb_word);

char	**ft_split(const char *s, char c)
{
	char	**ntab;
	int		w;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	w = f_count(s, c);
	ntab = (char **)malloc(sizeof(char *) * (w + 1));
	if (!ntab)
		return (NULL);
	i = 0;
	j = 0;
	while (i < w)
	{
		while (*s == c)
			s++;
		j = f_len(s, c);
		ntab[i] = f_strndup(s, j);
		if (!ntab[i])
			return (f_ntab_free(ntab, i), NULL);
		s += j;
		i++;
	}
	return (ntab[i] = NULL, ntab);
}

int	f_count(const char *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		i = f_len(s, c);
		s += i;
		if (i != 0)
			word++;
	}
	return (word);
}

int	f_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

char	*f_strndup(const char *s, int nj)
{
	int		i;
	char	*ps;

	i = 0;
	ps = (char *)malloc(sizeof(char) * nj + 1);
	if (!ps)
		return (NULL);
	while (s[i] && i < nj)
	{
		ps[i] = s[i];
		i++;
	}
	ps[i] = '\0';
	return (ps);
}

static void	f_ntab_free(char **tab, int nb_word)
{
	int	i;

	i = 0;
	while (i <= nb_word)
	{
		free(tab[i]);
	}
	free(tab);
}
