/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgoncalv <jgoncalv@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:22:44 by jgoncalv          #+#    #+#             */
/*   Updated: 2016/12/15 11:33:08 by jgoncalv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_lstline	*ft_lstnewline(int fd, char *str, t_lstline **alst)
{
	t_lstline *newlst;

	if (!(newlst = (t_lstline*)malloc(sizeof(t_lstline))))
		return (NULL);
	if (!(newlst->str = (char*)ft_strnew(sizeof(char) * ft_strlen(str))))
		return (NULL);
	ft_strcpy(newlst->str, str);
	newlst->fd = fd;
	newlst->next = NULL;
	if (*alst == NULL)
		*alst = newlst;
	else
	{
		newlst->next = *alst;
		*alst = newlst;
	}
	return (newlst);
}

static int			ft_lstline_fd(t_lstline *tmp, int fd)
{
	if (tmp)
	{
		while (tmp->fd != fd && tmp->next != NULL)
			tmp = tmp->next;
		if (tmp->fd == fd)
			return (1);
	}
	return (0);
}

static	char		*ft_line(t_lstline *tmp, int fd)
{
	char			*line;
	char			*str;
	char			*str2;
	unsigned int	j;

	while (tmp->fd != fd && tmp)
		tmp = tmp->next;
	str = tmp->str;
	j = 0;
	if (str[0] == '\0')
		return (NULL);
	if (!(str2 = ft_strchr(str, '\n')))
		str2 = str + ft_strlen(str);
	while (str + j < str2)
		j++;
	if (!(line = ft_strsub(str, 0, j)))
		return (NULL);
	if (str2[0] == '\0')
		tmp->str = str + j;
	else
		tmp->str = str + (j + 1);
	return (line);
}

int					get_next_line(const int fd, char **line)
{
	static t_lstline	*alst;
	char				*buf;
	char				*str;
	int					ret;

	if (!(ft_lstline_fd(alst, fd)))
	{
		if (!(buf = (char*)ft_strnew(sizeof(*buf) * BUFF_SIZE)) ||
			!(str = (char*)ft_strnew(sizeof(*buf) * BUFF_SIZE)))
			return (-1);
		while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
		{
			if (!(str = ft_realloc(str, ft_strlen(str) + ft_strlen(buf))))
				return (-1);
			str = ft_strcat(str, buf);
			ft_bzero(buf, BUFF_SIZE);
		}
		if (ret == -1 || !(ft_lstnewline(fd, str, &alst)))
			return (-1);
		ft_strdel(&str);
	}
	if (!(*line = ft_line(alst, fd)))
		return (0);
	return (1);
}
