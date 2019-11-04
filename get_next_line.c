/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:18:21 by jopaning          #+#    #+#             */
/*   Updated: 2019/11/04 12:12:10 by selgrabl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_new_line(char **s, char **line, int fd, int ret)
{
	char	*temp;
	int		len;

	len = 0;
	while (s[fd][len] != '\n' && s[fd][len] != '\0')
		len++;
	if (s[fd][len] == '\n')
	{
		if (!(*line = ft_strsub(s[fd], 0, len)))
			return (-1);
		if (!(temp = ft_strdup(s[fd] + len + 1)))
			return (-1);
		free(s[fd]);
		s[fd] = temp;
		if (s[fd][0] == '\0')
			ft_strdel(&s[fd]);
	}
	else if (s[fd][len] == '\0')
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	int		verif;
	char		buffer[BUFF_SIZE + 1];
	char		*temp;
	static char	*str[2147483647];

	if (fd < 0 || line == 0 || BUFF_SIZE)
		return (-1);
	while ((verif = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[verif] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strnew(1);
		temp = ft_strjoin(str[fd], buffer);
		free(str[fd]);
		str[fd] = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	if (verif < 0)
		return (-1);
	if (verif == 0 && (str[fd] == 0 || str[fd][0] == '\0'))
		return (0);
	return (ft_new_line(str, line, fd, verif));
}
