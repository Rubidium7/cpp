/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarikha <asarikha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 13:39:27 by asarikha          #+#    #+#             */
/*   Updated: 2023/11/01 14:09:18 by nlonka           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

#define MAX_VAL 750

int main ( void ){
	// char name[] = "Ramswarup Tushar Nilesh Subhash";
 
    // // Both of the statement prints same thing
    // std::cout << name[5] << std::endl;
    // std::cout << 5 [name] << std::endl;

	// int intArray[1024];
    // for (int i = 0, j = 0; i < 1024; i++) {
    //     intArray[i] = j++;
    // }
 
    // // 512
    // cout << intArray[512] << endl;
 
    // // 257
    // cout << 257 [intArray] << endl;
 
    // // pointer to the middle of the array
    // int* midArray = &intArray[512];
 
    // // 256
    // cout << midArray[-256] << endl;
 
    // // unpredictable, may crash
    // //cout << intArray[-256] << endl;
	
	Array<int> numbers(MAX_VAL);
    numbers[0] = 9;
    const Array<int> const_numbers(numbers);
    std::cout << const_numbers[0] << std::endl;
    const_numbers[0] = 8; //doesn't work
    
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
   
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}
