/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mm-furi <mm-furi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 14:25:22 by mm-furi           #+#    #+#             */
/*   Updated: 2025/08/12 14:44:38 by mm-furi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int ac, char **av)
{
	char *s;
	int i;
	int j;

	i = 1;

	if (ac == 1)
	{
		std::cout<< "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (i < ac)
	{
		s = av[i];
		j = 0;
		while (s[j])
		{
			std::cout << static_cast<char>(std::toupper(static_cast<unsigned char>(s[j])));
			j++;
		}
		if (i + 1 < ac)
			std::cout << " ";
		i++;
	}
	std::cout << std::endl;
	return 0;
}
