/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:03:50 by eperperi          #+#    #+#             */
/*   Updated: 2025/01/08 14:19:36 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int c, char *argv[])
{
	if (c != 2)
	{
		std::cout << "Invalid number of arguments" << std::endl;
		return (1);
	}
	ScalarConverter::convert(argv[1]);
}