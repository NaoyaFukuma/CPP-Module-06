/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 22:02:24 by nfukuma           #+#    #+#             */
/*   Updated: 2022/12/30 23:16:17 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

struct		Data
{
	int		width;
	int		height;
};

uintptr_t	serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}

int	main()
{
	Data data;
	uintptr_t raw_ptr = serialize(&data);

	std::cout << "\e[33m<< reinterpret_cast test >>\e[m" << std::endl;
	std::cout << "1. struct Data object address\t<" << &data << ">" << std::endl;
	std::cout << "2. serialize() return value\t<" << raw_ptr << ">" << std::endl;
	std::cout << "3. deserialize() return value\t<" << deserialize(raw_ptr) << ">" << std::endl;
	std::cout << "\n\e[32mCheck the results of 1 and 3, and if they match, it is a success.\e[m" << std::endl;
}
