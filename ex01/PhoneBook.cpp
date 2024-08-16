/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:26:00 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/09/20 10:09:10 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void  print_data(PhoneBook new_phonebook, int i)
{
   std::cout << std::endl << "Index : ";
   std::cout << new_phonebook.contact[i].Get_index() << std::endl;
   std::cout << "Nickname : ";
   std::cout << new_phonebook.contact[i].Get_nickname() << std::endl;
   std::cout << "First name : ";
   std::cout << new_phonebook.contact[i].Get_first_name() << std::endl;
   std::cout << "last name : ";
   std::cout << new_phonebook.contact[i].Get_last_name() << std::endl;
   std::cout << "phone number : ";
   std::cout << new_phonebook.contact[i].Get_phone_number() << std::endl;
   std::cout << "darkest secret : ";
   std::cout << new_phonebook.contact[i].Get_darkest_secret() << std::endl << std::endl;
}

void	print_10(std::string str)
{
	int i;

	i = 0;
	while (str[i] && i < 9)
	{
		std::cout << str[i];
		i++;
	}
	if (str[i] != '\0')
		std::cout << ".|";
}

void  check_and_print(PhoneBook new_phonebook, int i)
{
   if (new_phonebook.contact[i].Get_last_name().size() <= 10)
   {
      std::cout.width(10); std::cout << std::right << new_phonebook.contact[i].Get_last_name() << "|";
   }
   else
      print_10(new_phonebook.contact[i].Get_last_name());
   if (new_phonebook.contact[i].Get_phone_number().size() <= 10)
   {
      std::cout.width(10); std::cout << std::right << new_phonebook.contact[i].Get_phone_number() << "|";
   }
   else
      print_10(new_phonebook.contact[i].Get_phone_number());
   if (new_phonebook.contact[i].Get_darkest_secret().size() <= 10)
   {
      std::cout.width(10); std::cout << std::right << new_phonebook.contact[i].Get_darkest_secret() << "|";
   }
   else
   {
      print_10(new_phonebook.contact[i].Get_darkest_secret());
      std::cout << std::endl;
   }
}

void  print_info(PhoneBook new_phonebook, int counter)
{
   int i;
   int status;

   i = 0;
   if (counter > 8)
      counter = 8;
   status = 0;
   while (i < counter)
   {
      if (status == 0)
      {
         std::cout << "    Index |";
         std::cout << "  Nickname|";
         std::cout << " Firstname|";
         std::cout << "  Lastname|";
         std::cout << " Phone_num|";
         std::cout << "  D_secret|";
         status = 1;
      }
      std::cout.width(10); std::cout << std::right << std::endl << new_phonebook.contact[i].Get_index() << "|";
      if (new_phonebook.contact[i].Get_nickname().size() <= 10)
      {
         std::cout.width(10); std::cout << std::right << new_phonebook.contact[i].Get_nickname() << "|";
      }
      else
         print_10(new_phonebook.contact[i].Get_nickname());
      if (new_phonebook.contact[i].Get_first_name().size() <= 10)
      {
         std::cout.width(10); std::cout << std::right << new_phonebook.contact[i].Get_first_name() << "|";
      }
      else
         print_10(new_phonebook.contact[i].Get_first_name());
      check_and_print(new_phonebook, i);
      i++;
   }
}
