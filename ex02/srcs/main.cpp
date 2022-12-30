/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 23:20:09 by nfukuma           #+#    #+#             */
/*   Updated: 2022/12/30 23:51:31 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <A.hpp>
#include <B.hpp>
#include <Base.hpp>
#include <C.hpp>
#include <iostream>

Base	*generate()
{
	switch (rand() % 3)
	{
	case 0:
		return (new A());
	case 1:
		return (new B());
	case 2:
		return (new C());
	}
	return NULL;
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "A" << std::endl;
	if (dynamic_cast<B *>(p) != NULL)
		std::cout << "B" << std::endl;
	if (dynamic_cast<C *>(p) != NULL)
		std::cout << "C" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
	}
	catch (std::bad_cast)
	{
	}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
	}
	catch (std::bad_cast)
	{
	}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
	}
	catch (std::bad_cast)
	{
	}
}

int	main()
{
	Base	*p;

	srand(time(NULL));
		std::cout << "\e[33mWhat is the identity of the derived class?\nA class? B class? C class?\nLet's use the base class \"Base\" to check derived class.\e[m\n" << std::endl;
	for (int i = 0; i < 5; i++)
	{
		p = generate();

		std::cout << "Use a \e[3;32mreference\e[m to the base class.\n --> " << std::flush;
		identify(p);
		std::cout << "Use a \e[3;34mpointer\e[m to the base class.\n --> " << std::flush;
		identify(*p);
		std::cout << std::endl;
		delete p;
	}
}
