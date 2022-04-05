/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwarpath <kwarpath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 16:20:27 by kwarpath          #+#    #+#             */
/*   Updated: 2021/11/30 13:50:52 by kwarpath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	int		i;
	int		j;
	size_t	d;
	size_t	s;

	d = ft_strlen(dst);
	s = ft_strlen(src);
	i = 0;
	if (dstsize < d + 1)
		return (dstsize + s);
	while (dst[i])
	{
		i++;
		dstsize--;
	}
	j = 0;
	while (0 < dstsize - 1 && src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
		dstsize--;
	}
	dst[i] = '\0';
	return (d + s);
}
