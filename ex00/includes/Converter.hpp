/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:26:08 by nfukuma           #+#    #+#             */
/*   Updated: 2023/01/03 22:49:25 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <string>
# include <limits>

class Converter
{
  private:
	std::string inputLiterals_;
	int inputLiteralsType_;

	char char_;
	int  int_;
	float float_;
	double double_;

	bool impossible_;
	bool printable_;

	Converter();

	int parseType();
	bool isChar() const;
	bool isInt() const;
	bool isDouble() const;
	bool isFloat() const;
	bool isLiterals() const;

	void convert();

  public:
	void printChar() const;
	void printInt() const;
	void printFloat() const;
	void printDouble() const;
	Converter(std::string inputLiterals);
	Converter(const Converter &src);
	Converter &operator=(const Converter &rhs);
	~Converter();
	class invalidArgException : public std::exception
	{
		public:
		virtual const char *what() const throw()
		{
			return ("\e[31mError: invalid argument.\nThis argument literal must belong to one of the following a scalar types:\nchar, int, float or double.\nExcept for char parameters, only the decimal notation will be used.\e[m");
		}
	};

};

std::ostream &operator<<(std::ostream &out, const Converter &rhs);

#endif
