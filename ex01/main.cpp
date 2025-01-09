/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:23:17 by eperperi          #+#    #+#             */
/*   Updated: 2025/01/08 15:22:14 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data data = {42, "dataString"};

	uintptr_t uintptr = Serializer::serialize(&data);
	Data* dataptr = Serializer::deserialize(uintptr);

	std::cout << "Data : " << &data << std::endl;
	std::cout << "uintptr : " << &uintptr << std::endl;
	std::cout << "Data_ptr : " << dataptr << std::endl;
}