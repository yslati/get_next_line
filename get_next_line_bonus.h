/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 17:38:32 by yslati            #+#    #+#             */
/*   Updated: 2019/12/16 17:38:34 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# define MAX 4864

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE -1
# endif

size_t					ft_strlen(const char *str);
int						check_static(char *t);
int						line_len(const char *str);
char					*ft_strjoin(char *line, char *stc, char c);
char					*ft_strdup(const char *s1);
int						fill_line(char **line, char **stc, int fd);
int						get_next_line(int fd, char **line);

#endif
