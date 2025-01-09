/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:28:27 by eperperi          #+#    #+#             */
/*   Updated: 2025/01/09 15:13:38 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>


Base* generate()
{
	int random = std::rand() % 3;
	switch(random)
	{
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
	}
	return NULL;
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "Identified by pointer : A" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "Identified by pointer : B" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "Identified by pointer : C" << std::endl;
	else
		std::cout << "Error : Not of them" << std::endl;
}

// void identify(Base& p)
// {
//     // Χρησιμοποιούμε dynamic_cast για αναφορές και ελέγχουμε την τύχη της μετατροπής
//     if (dynamic_cast<A*>(&p) != nullptr) {
//         std::cout << "Identified by reference : A" << std::endl;
//     } else if (dynamic_cast<B*>(&p) != nullptr) {
//         std::cout << "Identified by reference : B" << std::endl;
//     } else if (dynamic_cast<C*>(&p) != nullptr) {
//         std::cout << "Identified by reference : C" << std::endl;
//     } else {
//         std::cout << "Error : Not of them" << std::endl;
//     }
// }

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Identified by reference : A" << std::endl;
	}
	catch(const std::exception& e)
	{
		try
		{
			(void)dynamic_cast<B&>(p);
			std::cout << "Identified by reference : B" << std::endl;
		}
		catch(const std::exception& e)
		{
			try
			{
				(void)dynamic_cast<C&>(p);
				std::cout << "Identified by reference : C" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
	}
}

int main ()
{
	std::srand(time(NULL));
	{
		Base * gen = generate();
		if (gen == NULL)
		{
			std::cerr << "Generate issue" << std::endl;
			return (1);
		}
		Base & ref = *gen;
		identify(gen);
		identify(ref);
		delete gen;	
	}
	return 0;
}