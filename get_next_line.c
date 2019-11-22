/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 22:26:31 by zjamali           #+#    #+#             */
/*   Updated: 2019/11/20 06:17:40 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

int leak(char **buff)
{
	if(buff != NULL || *buff != NULL)
	{
		free(*buff);
		buff = NULL;
	}
	return (-1);
}
int 	continuey(char **str,char **line,int n)
{
	char *tmp ;
	tmp= *str;

	int i = 0;
	if (n < 0)
		return (0);
	if(!*str && !n)
		return 0;
	while((*str)[i] != '\n' && (*str)[i] != '\0')
		i++;
	*line = ft_substr((*str),0,i);
	if ((*str)[i] == '\n')
		(*str) = ft_strdup((*str) + i + 1);
	else
		(*str) = NULL;
	leak(&tmp);
	return (1);
}
int		get_next_line(int fd, char **line)
{
	int n;
	int i;
	char *buff;
	char	*tmp;
	static char *str;

	i = 0;
	buff = malloc((BUFFER_SIZE));
	if(buff == NULL | fd < 0 | fd > 4682 | read(fd,buff,0) | line == NULL)
		return(leak(&buff));
	while((n = read(fd,buff,BUFFER_SIZE)) > 0)
	{
		tmp = str;
		buff[n] = '\0';
		if(!str)
			str = ft_strdup(buff);
		else
			str = ft_strjoin(str,buff);
		leak(&tmp);
		if(ft_strchr(str,'\n'))
			break;
	}
	leak(&buff);
	if (n < 0)
		return (0);
	return (continuey(&str,line,n));
}

int main()

{
	int fd;
	int n ;
	char *str;
	fd = open("get_next_line.c",O_RDONLY);
	//printf("%d",get_next_line(fd,&str));
	while((n = get_next_line(fd,&str))> 0)
	{
		printf("|%s| |%d|\n",str,n);
		free(str);
	}
	return 0;
}
