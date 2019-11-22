/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:31:50 by zjamali           #+#    #+#             */
/*   Updated: 2019/11/22 10:13:11 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int fd;
	char *str;
	struct s_list *next;
}				t_list;

typedef struct s_list {

	int fd;
	char *rest;
	struct s_list *next;

} t_list;

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
char		*ft_strchr(const char *s, int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char    	*ft_strjoin(char const *s1, char const *s2);
int			get_next_line(int fd, char **line);
#endif
