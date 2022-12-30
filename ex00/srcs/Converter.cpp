/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:26:38 by nfukuma           #+#    #+#             */
/*   Updated: 2022/12/30 11:14:50 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Converter.hpp"
#include <iostream>
#include <iomanip>
#define isFunctionsNum 5

/*
enum	e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	LITERALS
};
*/

bool Converter::isChar() const
{
	return (inputLiterals_.length() == 1 && std::isprint(inputLiterals_[0]) && !std::isdigit(inputLiterals_[0]));
}

bool Converter::isInt() const
{
	std::string::size_type i = 0;
	while (std::isspace(inputLiterals_[i]))
		++i;
	if (inputLiterals_[i] == '-' || inputLiterals_[i] == '+')
		++i;
	for (std::string::size_type len = (int)inputLiterals_.length(); i < len; ++i)
		if (!std::isdigit(inputLiterals_[i]))
			return (false);
	return (true);
}

bool Converter::isFloat() const
{
	if (inputLiterals_.back() != 'f' || inputLiterals_.find('.') == std::string::npos || inputLiterals_[0] == '.' || inputLiterals_[inputLiterals_.length() - 2] == '.' || inputLiterals_.find('.') != inputLiterals_.rfind('.'))
		return (false);

	std::string::size_type i = 0;
	while (std::isspace(inputLiterals_[i]))
		++i;
	if (inputLiterals_[i] == '-' || inputLiterals_[i] == '+')
		++i;
	for (std::string::size_type len = (int)inputLiterals_.length(); i < len - 1; ++i)
		if (!std::isdigit(inputLiterals_[i]) && inputLiterals_[i] != '.')
			return (false);
	return (true);
}

bool Converter::isDouble() const
{
	if (inputLiterals_.find('.') == std::string::npos || inputLiterals_[0] == '.' || inputLiterals_[inputLiterals_.length() - 1] == '.' || inputLiterals_.find('.') != inputLiterals_.rfind('.'))
		return (false);

	std::string::size_type i = 0;
	while (std::isspace(inputLiterals_[i]))
		++i;
	if (inputLiterals_[i] == '-' || inputLiterals_[i] == '+')
		++i;
	for (std::string::size_type len = (int)inputLiterals_.length(); i < len; ++i)
		if (!std::isdigit(inputLiterals_[i]) && inputLiterals_[i] != '.')
			return (false);
	return (true);
}

bool Converter::isLiterals() const
{
	if ((inputLiterals_.compare("nan") == 0)
		|| (inputLiterals_.compare("nanf") == 0) || (inputLiterals_.compare("+inf") == 0)
		|| (inputLiterals_.compare("+inff") == 0) || (inputLiterals_.compare("-inf") == 0)
		|| (inputLiterals_.compare("-inff") == 0) || (inputLiterals_.compare("-inff") == 0)
		|| (inputLiterals_.compare("-inff") == 0) || (inputLiterals_.compare("+inff") == 0)
		|| (inputLiterals_.compare("+inff") == 0))
	{
		return (true);
	}
	return (false);
}

int	Converter::parseType()
{
	bool (Converter::*isFunctions[isFunctionsNum])(void) const = {
			&Converter::isChar, &Converter::isInt, &Converter::isFloat,
			&Converter::isDouble, &Converter::isLiterals
		};

	int i = 0;
	for (; i < isFunctionsNum; ++i)
		if ((this->*isFunctions[i])())
			break ;

	switch (i)
	{
		case CHAR:		return CHAR;
		case INT:		return INT;
		case FLOAT:		return FLOAT;
		case DOUBLE: 	return DOUBLE;
		case LITERALS:	return LITERALS;
		default:
			printable_ = false;
			throw invalidArgException();
	}
}

void Converter::convert()
{
	try
	{
		switch (inputLiteralsType_)
		{
		case CHAR:
			char_ = inputLiterals_[0];
			int_ = static_cast<int>(char_);
			float_ = static_cast<float>(char_);
			double_ = static_cast<double>(char_);
			break ;
		case INT:
			int_ = std::stoi(inputLiterals_);
			float_ = static_cast<float>(int_);
			double_ = static_cast<double>(int_);
			char_ = static_cast<char>(int_);
			break ;
		case FLOAT:
			float_ = std::stof(inputLiterals_);
			int_ = static_cast<int>(float_);
			double_ = static_cast<double>(float_);
			char_ = static_cast<char>(float_);
			break ;
		case DOUBLE:
			double_ = std::stod(inputLiterals_);
			int_ = static_cast<int>(double_);
			float_ = static_cast<float>(double_);
			char_ = static_cast<char>(double_);
			break ;
		default:
			break ;
		}
	}
	catch (std::invalid_argument &e)
	{
		impossible_ = true;
	}
	catch (std::out_of_range &e)
	{
		impossible_ = true;
	}
}

Converter::Converter(std::string inputLiterals)
	: inputLiterals_(inputLiterals), char_('\0'), int_(0), float_(0.0f), double_(0.0), impossible_(false), printable_(true)
{
	this->inputLiteralsType_ = parseType();
	convert();
}



Converter::Converter(const Converter &src)
{
	*this = src;
}

Converter::~Converter()
{
}

Converter &Converter::operator=(const Converter &rhs)
{
	if (this != &rhs)
	{
		this->inputLiterals_ = rhs.inputLiterals_;
		this->inputLiteralsType_ = rhs.inputLiteralsType_;
		this->char_ = rhs.char_;
		this->int_ = rhs.int_;
		this->float_ = rhs.float_;
		this->double_ = rhs.double_;
		this->impossible_ = rhs.impossible_;
	}
	return (*this);
}

void Converter::printChar() const
{
	if (inputLiteralsType_ == LITERALS || impossible_)
		std::cout << "Impossible" << std::endl;
	else if (!std::isprint(this->int_))
		std::cout << "None displayable"<< std::endl;
	else
		std::cout << "'" << char_ << "'" << std::endl;
}


void Converter::printInt() const
{
	if (this->isLiterals() || impossible_)
		std::cout << "Impossible" << std::endl;
	else
		std::cout << int_ << std::endl;
}

void Converter::printFloat() const
{
	if (impossible_)
		std::cout << "Impossible" << std::endl;
	else if (inputLiterals_.compare("nan") == 0 || inputLiterals_.compare("nanf") == 0)
		std::cout << "nanf" << std::endl;
	else if (inputLiterals_.compare("+inff") == 0 || inputLiterals_.compare("+inf") == 0)
		std::cout << "+inff" << std::endl;
	else if (inputLiterals_.compare("-inff") == 0 || inputLiterals_.compare("-inf") == 0)
		std::cout << "-inff" << std::endl;
	else
	{
		std::cout << float_ << std::flush;
		if (float_ - static_cast<int>(float_) == 0 )
			std::cout << ".0" << std::flush;
		std::cout << "f" << std::endl;
	}
}
void Converter::printDouble() const
{
	if (impossible_)
		std::cout << "Impossible" << std::endl;
	else if (inputLiterals_.compare("nan") == 0 || inputLiterals_.compare("nanf") == 0)
		std::cout << "nan" << std::endl;
	else if (inputLiterals_.compare("+inff") == 0 || inputLiterals_.compare("+inf") == 0)
		std::cout << "+inf" << std::endl;
	else if (inputLiterals_.compare("-inff") == 0 || inputLiterals_.compare("-inf") == 0)
		std::cout << "-inf" << std::endl;
	else
	{
		std::cout << double_ << std::flush;
		if (double_ - static_cast<int>(double_) == 0 )
			std::cout << ".0" << std::flush;
		std::cout << std::endl;
	}
}


std::ostream &operator<<(std::ostream &out, const Converter &rhs)
{
	out << "char: ";
	rhs.printChar();
	out << "int: ";
	rhs.printInt();
	out << "float: ";
	rhs.printFloat();
	out << "double: ";
	rhs.printDouble();
	return out;
}
