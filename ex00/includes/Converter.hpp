/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfukuma <nfukuma@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:26:08 by nfukuma           #+#    #+#             */
/*   Updated: 2022/12/30 11:11:18 by nfukuma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_HPP
# define CONVERTER_HPP

# include <string>
# include <limits>

enum	e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	LITERALS,
};

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


// class Converter
// {
//   private:
// 	char _c;
// 	int _n;
// 	float _f;
// 	double _d;
//
// 	bool _impossible;
//
// 	std::string _str;
// 	e_type _type;
//
//   public:
// 	Converter(void);
// 	Converter(const Converter &src);
// 	~Converter(void);
//
// 	Converter &operator=(const Converter &rhs);
//
// 	char getC(void) const;
// 	void setC(char c);
//
// 	int getI(void) const;
// 	void setI(int n);
//
// 	float getF(void) const;
// 	void setF(float f);
//
// 	double getD(void) const;
// 	void setD(double d);
//
// 	void convert(void);
//
// 	void setStr(std::string str);
// 	std::string getStr(void) const;
//
// 	e_type getType(void) const;
// 	void setType(void);
//
// 	bool isChar(void) const;
// 	bool isInt(void) const;
// 	bool isFloat(void) const;
// 	bool isDouble(void) const;
//
// 	bool isImpossible(void);
//
// 	void printChar(void) const;
// 	void printInt(void) const;
// 	void printFloat(void) const;
// 	void printDouble(void) const;
//
// 	bool isLiterals(void) const;
//
// 	class ConverterException : public std::exception
// 	{
// 		virtual const char *what() const throw()
// 		{
// 			return ("Unknown type");
// 		}
// 	};
// };


#endif // CONVERTER_HPP
