/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 14:37:13 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/11/22 14:37:14 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**ft_tabnew(size_t n)
{
	char		**tab;
	size_t		i;

	i = 0;
	if (!(tab = (char**)malloc(sizeof(char**) * (n + 1))))
		return (NULL);
	while (i < n)
	{
		if (!(tab[i] = (char*)ft_memalloc(sizeof(char*) * 1)))
			return (NULL);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
