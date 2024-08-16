/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 17:46:05 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/09/20 10:05:02 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

Contact  fill_contact(void)
{
   Contact     new_contact;
   std::string darkest_secret;
   std::string phone_number;
   std::string first_name;
   std::string last_name;
   std::string nickname;

   std::cout << std::endl << "Enter your nickname :" << std::endl;
   std::getline(std::cin, nickname, '\n');
   new_contact.Set_nickname(nickname);
   std::cout << "Enter your first name :" << std::endl;
   std::getline(std::cin, first_name, '\n');
   new_contact.Set_first_name(first_name);
   std::cout << "Enter your last name :" << std::endl;
   std::getline(std::cin, last_name, '\n');
   new_contact.Set_last_name(last_name);
   std::cout << "Enter your phone number :" << std::endl;
   std::getline(std::cin, phone_number, '\n');
   new_contact.Set_phone_number(phone_number);
   std::cout << "Enter your darkest secret :" << std::endl;
   std::getline(std::cin, darkest_secret, '\n');
   new_contact.Set_darkest_secret(darkest_secret);
   return (new_contact);
}

int   is_done(std::string str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '	')
		i++;
	if (str[i] == '\0')
		return (1);
	return (0);
}

void  fill_phonebook(PhoneBook   &phonebook, Contact new_contact, int *i, int *counter)
{
   if ((new_contact.Get_first_name() != "" && !is_done(new_contact.Get_first_name())) \
      && (new_contact.Get_last_name() != "" && !is_done(new_contact.Get_last_name())) \
      && (new_contact.Get_nickname() != "" && !is_done(new_contact.Get_nickname())) \
      && (new_contact.Get_phone_number() != "" && !is_done(new_contact.Get_phone_number())) \
      && (new_contact.Get_darkest_secret() != "" && !is_done(new_contact.Get_darkest_secret())))
   {
		if ((*i) == 8)
			(*i) = 0;
      phonebook.contact[*i].Set_index(*i);
      phonebook.contact[*i].Set_nickname(new_contact.Get_nickname());
      phonebook.contact[*i].Set_first_name(new_contact.Get_first_name());
      phonebook.contact[*i].Set_last_name(new_contact.Get_last_name());
      phonebook.contact[*i].Set_phone_number(new_contact.Get_phone_number());
      phonebook.contact[*i].Set_darkest_secret(new_contact.Get_darkest_secret());
		(*counter)++;
		(*i) = (*i) + 1;
   }
}

int   index_check(int index, int counter)
{
   if (index < counter)
      return (1);
   return (0);
}

int	ft_isdigit(std::string c, int x)
{
	std::string Num;
	int i;
	
	Num = "0123456789";
	i = 0;
	while (Num[i])
	{
		if (c[x] == Num[i])
			return (1);
		i++;
	}
	return (0);
}

int	checkdigit(std::string str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str, i))
			return (0);
		i++;
	}
	return (1);
}

void  search_or_exit(PhoneBook new_phonebook, int counter, std::string cmd)
{
   int					index;
   int					status;
   std::stringstream	convert;

	index = 0;
	status = 0;
   if (cmd == "SEARCH")
   {
      if (counter > 0)
      {
         print_info(new_phonebook, counter);
         std::cout << std::endl << "Enter Contact index : ";
         std::string str;
         std::getline(std::cin, str);
         if (checkdigit(str))
         {
            std::cout << "Invalid index" << std::endl;
            status = 1;
         }
         convert << str;
         convert >> index;
         if (std::cin.fail() || index > counter)
         {
            std::cout << "Invalid index " << std::endl;
            std::cin.clear();
            return ;
         }
         if (index_check(index, counter) && counter > 0 && status != 1)
         {
            print_data(new_phonebook, index);
         }
         else if (status != 1)
         {
            std::cout << "Invalid index" << std::endl;
         }
      }
      else
         std::cout << "Phone Book is empty" << std::endl;
   }
   else if (cmd == "EXIT")
   {
      exit(1);
   }
}

int main(void)
{
   PhoneBook   phonebook;
   Contact     new_contact;
   int         counter;
   int         status;
   std::string cmd;
   int         i;

   i = 0;
   counter = 0;
   status = 0;
   cmd = "";
   while (1)
   {
      if (cmd != "\0" || status != 1 || cmd == "")
      {
         std::cout << "Enter your Command : ";
         std::getline(std::cin, cmd);
         if (std::cin.fail())
         {
               exit(1);
         }
      }
      if (cmd == "ADD")
      {
         new_contact = fill_contact();
         fill_phonebook(phonebook, new_contact, &i, &counter);
         status = 0;
      }
      else if (cmd == "EXIT" || cmd == "SEARCH")
      {
         search_or_exit(phonebook, counter, cmd);
		   status = 1;
      }
	   else
      {
        std::cout << std::endl << "Invalid command " << cmd << std::endl << std::endl;
      }
   }
}
