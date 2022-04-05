/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kwarpath <kwarpath@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 19:43:02 by kwarpath          #+#    #+#             */
/*   Updated: 2021/11/30 13:33:48 by kwarpath         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	num;
	long	znaki;

	num = 0;
	znaki = 1;
	while (str[0] == 32 || (str[0] >= 9 && str[0] <= 13))
		str++;
	if (*str == '-')
		znaki = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (str[0] >= '0' && str[0] <= '9')
	{
		num = num * 10 + str[0] - '0';
		if (num > 2147483648 && znaki == -1)
			return (0);
		if (num > 2147483647 && znaki == 1)
			return (-1);
		str++;
	}		
	num = num * znaki;
	return ((int)num);
}
