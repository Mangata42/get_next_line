/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnbjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 05:45:49 by nghaddar          #+#    #+#             */
/*   Updated: 2016/11/21 07:11:58 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnbjoin(char *s1, char *s2, size_t len)
{
	char	*ret;
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	if (!(ret = (char *)malloc(sizeof(char) * ft_strlen(s1) + len + 1)))
		return (NULL);
	while (s1[i] != '\0')
	{
		ret[i] = s1[i];
		i++;
	}
	while (y < len)
	{
		ret[i] = s2[y];
		i++;
		y++;
	}
	ret[i] = '\0';
	return (ret);
}
