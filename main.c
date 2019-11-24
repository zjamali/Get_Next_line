/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zjamali <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 09:48:08 by zjamali           #+#    #+#             */
/*   Updated: 2019/11/24 02:07:52 by zjamali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

int main()
{
	int fd;
	int fd1;
	int fd2;
	int n = 1;
//	int x = 100;	
//	int i = 0;
	char *str;
	fd = open("get_next_line.h",O_RDONLY);
	fd1 = open("get_next_line.c",O_RDONLY);
	fd2 = open("get_next_line_utils.c",O_RDONLY);

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
	   
/*
	printf("***********************************************************************************************************\n");
	while( i < x && (n = get_next_line(fd,&str)) > 0)
	{
		printf("|%s| |%d|\n",str,n);
		i++;
	}
	i = 0;
	printf("***********************************************************************************************************\n");
	while(i < x && (n = get_next_line(fd1,&str))>0)
	{
		printf("|%s| |%d|\n",str,n);
		i++;
	}
	i = 0;
	printf("************************************************************************************************************\n");
	while(i < x && (n = get_next_line(fd2,&str))>0)
	{
		printf("|%s| |%d|\n",str,n);
		i++;
	}
	i = 0;
	printf("************************************************************************************************************\n");

	while( i < x && (n = get_next_line(fd,&str)) > 0)
	{
		    printf("|%s| |%d|\n",str,n);
			i++;
	}
	i = 0;
	printf("************************************************************************************************************\n");
	while(i < x && (n = get_next_line(fd1,&str))>0)
	{
		    printf("|%s| |%d|\n",str,n);
			i++;
	}
	i = 0;
	printf("************************************************************************************************************\n");
	while(i < x && (n = get_next_line(fd2,&str))>0)
	{
		    printf("|%s| |%d|\n",str,n);
			i++;
	}
	i = 0;*/
	free(str);
	return 0;
}
