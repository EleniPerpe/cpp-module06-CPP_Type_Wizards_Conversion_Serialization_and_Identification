/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:35:27 by eperperi          #+#    #+#             */
/*   Updated: 2025/01/09 15:08:10 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <regex>

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter&copy) {*this = copy;}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy)
{
	if (this == &copy) {}
	return *this;
}
ScalarConverter::~ScalarConverter() {}


int isValidInput(const std::string &input) {
	
    std::regex numRegex(R"(^[-+]?\d*\.?\d+([fF])?$)");

    if (input == "nan" || input == "nanf" || 
        input == "+inf" || input == "-inf" || 
        input == "+inff" || input == "-inff") {
        return 1;
    }
    if (std::regex_match(input, numRegex))
        return 2;
	return 3;
    exit (EXIT_FAILURE);
}

void inputIsPseudo(std::string& input)
{
	std::string res;
		std::cout << "  |- char\t: " << "Impossible" << std::endl;
		std::cout << "  |- int\t: " << "Impossible" << std::endl;
		if (input[0] == '+')
		{
			res = input.substr(1, 3);
			std::cout << "  |- float\t: " << res << std::endl;
			std::cout << "  |- double\t: " << res << std::endl;	
		}
		else
		{
			res = input.substr(0, 4);
			std::cout << "  |- float\t: " << res << std::endl;
			std::cout << "  |- double\t: " << res << std::endl;		
		}
}

bool inputIsChar(std::string& input)
{
	if (input.length() == 1 && !std::isdigit(input[0]))
	{
		char c = input[0];
		
		std::cout << "  |- char\t: '" << c << "'" << std::endl;
		std::cout << "  |- int\t: " << static_cast<int>(c) << std::endl;
		std::cout << "  |- float\t: " << static_cast<float>(c) << ".0f" << std::endl;
		std::cout << "  |- double\t: " << static_cast<double>(c) << ".0" << std::endl;
		return true;
	}
	return false;
}

std::string forChar(double input)
{
	if (input < CHAR_MIN || input > CHAR_MAX)
		return "Non displayable";
		
	char c = static_cast<char>(input);
	if (std::isprint(c))
		return std::string("'") + c + std::string("'");
	else
		return "Non displayable";
}

std::string forInt(double input)
{
	if (input < INT_MIN || input > INT_MAX)
		return "N/A";
	std::ostringstream oss;
	oss << static_cast<int>(input);
	return oss.str();
}

std::string forFloat(double input, bool hasDecimal, int pres)
{
	std::ostringstream oss;
	oss << std::fixed;
	if (!hasDecimal)
		oss << std::setprecision(1);
	else
		oss << std::setprecision(pres);
	oss << static_cast<float>(input) << "f";
	return oss.str();
}

std::string	forDouble(double input, bool hasDecimal, int pres)
{
	std::ostringstream oss;
	oss << std::fixed;
	if (!hasDecimal) 
        oss << std::setprecision(1);
	else
		oss << std::setprecision(pres);
    oss << input;
    return oss.str();
}

void ScalarConverter::convert(std::string input)
{
	bool hasDecimal = true;
	
	auto pos = input.find('.');
	if (pos == std::string::npos)
		hasDecimal = false;
	
	int pres = input.size() - pos - 1;
	char* end;
    double d = std::strtod(input.c_str(), &end);

	if (inputIsChar(input))
		return ;
	if (isValidInput(input) == 3)
	{
		std::cout << "Invalid input" << std::endl;
		return ;
	}
	if(isValidInput(input) == 1)
		inputIsPseudo(input);

	if (isValidInput(input) == 2)
	{
		std::cout << "  |- char\t: " << forChar(d) << std::endl;
        std::cout << "  |- int\t: " << forInt(d) << std::endl;
		std::cout << "  |- float\t: " << forFloat(d, hasDecimal, pres) << std::endl;
    	std::cout << "  |- double\t: " << forDouble(d, hasDecimal, pres) << std::endl;
	}
}

