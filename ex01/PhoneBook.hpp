/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:49:27 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/09/20 10:09:52 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string.h>
#include <sstream>
#include "Contact.hpp"

class PhoneBook
{
   public:
      Contact contact[8];
};

void	print_data(PhoneBook new_phonebook, int i);
void	print_10(std::string str);
void	check_and_print(PhoneBook new_phonebook, int i);
void	print_info(PhoneBook new_phonebook, int counter);
void  fill_phonebook(PhoneBook   &phonebook, Contact new_contact, int *i, int *counter);

#endif