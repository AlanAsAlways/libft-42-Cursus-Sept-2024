/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astaffa- <astaffa-@student.42malaga.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 22:46:48 by astaffa-          #+#    #+#             */
/*   Updated: 2024/09/19 22:46:57 by astaffa-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*destcpy;
	const unsigned char	*srccpy;
	size_t				i;

	if ((dest == NULL) && (src == NULL))
		return (NULL);
	destcpy = (unsigned char *)dest;
	srccpy = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		destcpy[i] = srccpy[i];
		i++;
	}
	return (dest);
}
