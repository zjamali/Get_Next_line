/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 09:48:08 by zjamali           #+#    #+#             */
/*   Updated: 2019/11/26 18:28:15 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

int main(int c,char **v)
{
/*	int n = 1;
	int x = 100, i = 0;
	char *str;
	int fd = open("get_next_line.h",O_RDONLY);
	int fd1 = open("get_next_line.c",O_RDONLY);
	int fd2 = open("get_next_line_utils.c",O_RDONLY);

	   printf("***********************************************************************************************************\n");
	   while((n = get_next_line(fd,&str)) > 0)
	   {
	   printf("|%s| |%d|\n",str,n);
	   }
	   printf("***********************************************************************************************************\n");
	   while((n = get_next_line(fd1,&str))>0)
	   {
	   printf("|%s| |%d|\n",str,n);
	   }
	   printf("***************************************************************************************************************\n");
	   while((n = get_next_line(fd2,&str))>0)
	   {
	   printf("|%s| |%d|\n",str,n);
	   }
	   printf("***************************************************************************************************************\n");
	   


	printf("\n***********************************************************************************************************\n");
	while( i < x && (n = get_next_line(fd1,&str)) > 0)
	{
		printf("|%s| |%d|\n",str,n);
		i++;
		free(str);
	}
	i = 0;
	printf("\n***********************************************************************************************************\n");
	while(i < x && (n = get_next_line(fd,&str))>0)
	{
		printf("|%s| |%d|\n",str,n);
		i++;
		free(str);
	}
	i = 0;
	printf("\n************************************************************************************************************\n");
	while(i < x && (n = get_next_line(fd2,&str))>0)
	{
		printf("|%s| |%d|\n",str,n);
		i++;
		free(str);
	}
	i = 0;
	printf("\n************************************************************************************************************\n");

	while( i < x && (n = get_next_line(fd,&str)) > 0)
	{
		    printf("|%s| |%d|\n",str,n);
			i++;
			free(str);
	}
	i = 0;
	printf("\n************************************************************************************************************\n");
	while(i < x && (n = get_next_line(fd1,&str))>0)
	{
		    printf("|%s| |%d|\n",str,n);
			i++;
			free(str);
	}
	i = 0;
	printf("\n************************************************************************************************************\n");
	while(i < x && (n = get_next_line(fd2,&str))>0)
	{
		    printf("|%s| |%d|\n",str,n);
			i++;
			free(str);
	}
*/

//	str = NULL;
	char *str;
	int k;
	int fd;
	fd = open(v[c - 1] ,O_RDONLY);
	//k = get_next_line(fd,&str);
	//	printf("%s",str);
	while((k = get_next_line(fd,&str) > 0))
	{
		printf("%s\n",str);
		free(str);
	}
	close(fd);
	return 0;
}