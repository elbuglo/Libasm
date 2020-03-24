/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulebugl <lulebugl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 00:04:40 by lulebugl          #+#    #+#             */
/*   Updated: 2020/03/24 01:06:49 by lulebugl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

# define GREEN   "\033[32m"
# define RESET   "\033[0m"
# define STRLEN(x)	printf("`%s` = %d (%d)\n", x, ft_strlen(x), (int)strlen(x));

int		ft_strlen(char const *str);

int		main(void)
{
	printf(GREEN"--strlen\n"RESET);
	STRLEN("toto")
	printf(GREEN"-done\n"RESET);
	return (0);
}