/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulebugl <lulebugl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 00:04:40 by lulebugl          #+#    #+#             */
/*   Updated: 2020/03/24 00:06:35 by lulebugl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

# define STRLEN(x)	printf("`%s` = %d (%d)\n", x, ft_strlen(x), (int)strlen(x));

int		ft_strlen(char const *str);

int		main(void)
{
	STRLEN("toto")
	return (0);
}