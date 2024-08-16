/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 21:25:56 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/09/19 21:35:23 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string     Contact::Get_darkest_secret(void)
{
    return (darkest_secret);
}
void Contact::Set_darkest_secret(std::string value)
{
    darkest_secret = value;
}

std::string    Contact::Get_phone_number(void)
{
    return (phone_number);
}
void Contact::Set_phone_number(std::string value)
{
    phone_number = value;
}
std::string    Contact::Get_first_name(void)
{
    return (first_name);
}
void Contact::Set_first_name(std::string value)
{
    first_name = value;
}
std::string    Contact::Get_last_name(void)
{
    return (last_name);
}
void Contact::Set_last_name(std::string value)
{
    last_name = value;
}
std::string    Contact::Get_nickname(void)
{
    return (nickname);
}
void Contact::Set_nickname(std::string value)
{
    nickname = value;
}
int    Contact::Get_index(void)
{
    return (index);
}
void     Contact::Set_index(int value)
{
    index = value;
}