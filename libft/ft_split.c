/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwarpath <kwarpath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:48:10 by kwarpath          #+#    #+#             */
/*   Updated: 2021/11/30 13:34:15 by kwarpath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*new_stroka(char const *s, char c)
{
	int		len;
	char	*pointer;

	len = 0;
	while (s[len] != c && s[len])
		len++;
	pointer = (char *)malloc(sizeof(char) * (len + 1));
	if (!pointer)
		return (NULL);
	ft_strlcpy(pointer, s, len + 1);
	return (pointer);
}

static void	ft_free(char **stroki)
{
	int	i;

	i = 0;
	while (stroki[i])
	{
		free(stroki[i]);
		i++;
	}
	free(stroki);
	return ;
}

static int	ft_chetchik(char const *s, char c)
{
	int	i;
	int	chetchik;

	i = 0;
	chetchik = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] != c)
		{
			chetchik++;
			while (s[i] != c && s[i])
				i++;
			if (s[i] == '\0')
				return (chetchik);
		}
		i++;
	}
	return (chetchik);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		dlina;
	char	**stroki;

	dlina = ft_chetchik(s, c);
	stroki = (char **)malloc(sizeof(char *) * (dlina + 1));
	if (!stroki)
		return (NULL);
	i = 0;
	while (i < dlina)
	{
		while (s[0] == c)
			s++;
		stroki[i] = new_stroka(s, c);
		if (!stroki[i])
		{
			ft_free(stroki);
			return (NULL);
		}
		s = s + ft_strlen(stroki[i]);
		i++;
	}
	stroki[i] = 0;
	return (stroki);
}
