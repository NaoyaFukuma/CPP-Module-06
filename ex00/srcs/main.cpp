/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:25:29 by nfukuma           #+#    #+#             */
/*   Updated: 2022/12/30 02:15:34 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"
#include <iostream>

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./convert [input literal]" << std::endl;
		return (EXIT_FAILURE);
	}

	try
	{
		Converter c(av[1]);
		std::cout << c;
	}
	catch(const Converter::invalidArgException& e)
	{
		std::cerr << e.what() << '\n';
	}
}
