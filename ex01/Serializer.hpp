/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eperperi <eperperi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:07:35 by eperperi          #+#    #+#             */
/*   Updated: 2025/01/08 15:10:09 by eperperi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Data.hpp"

class Serializer
{
	private:
		Serializer();
		Serializer(const Serializer& copy);
		Serializer& operator=(const Serializer& copy);
		~Serializer();
	
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
		
};