/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopaning <jopaning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 17:24:41 by jopaning          #+#    #+#             */
/*   Updated: 2019/11/04 12:14:11 by selgrabl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1

# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>
# include <fcntl.h>


int	get_next_line(int fd, char **line);
size_t	ft_strlen(const char *str);
void	ft_strdel(char **as);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *str);
char	*ft_strchr(const char *p, int c);
char	*ft_strnew(size_t size);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
