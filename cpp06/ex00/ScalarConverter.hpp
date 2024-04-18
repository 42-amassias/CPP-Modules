#pragma once

#include <iostream>

class ScalarConverter
{
	private:
		typedef enum e_type {
			TYPE_CHAR,
			TYPE_INT,
			TYPE_FLOAT,
			TYPE_DOUBLE,
			TYPE_UNKNOWN,
			TYPE__COUNT,
		}	type_t;

	public:
		static void		convert(const std::string &litteral);

	private:
		ScalarConverter(void);

		static type_t	guessType(const std::string &litteral);
		static bool		isTypeChar(const std::string &litteral);
		static bool		isTypeInt(const std::string &litteral);
		static bool		isTypeFloat(const std::string &litteral);
		static bool		isTypeDouble(const std::string &litteral);
};