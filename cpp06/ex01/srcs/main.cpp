/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlonka <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:59:35 by nlonka            #+#    #+#             */
/*   Updated: 2023/10/19 15:12:59 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data data;

	data.num = 37;

	uintptr_t cereal = Serializer::serialize(&data);
	Data *decereal = Serializer::deserialize(cereal);
	std::cout << "original[" << &data << "] = " << data.num << std::endl;
	std::cout << "deserialized[" << decereal << "] = " << decereal->num << std::endl;
	return (0);
}
