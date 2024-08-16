/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 20:47:17 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/09/19 21:35:18 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string.h>
#include <sstream>

class Contact
{
   private:
      std::string darkest_secret;
      std::string phone_number;
      std::string first_name;
      std::string last_name;
      std::string nickname;
      int         index;

    public:
        std::string    Get_darkest_secret(void);
        void Set_darkest_secret(std::string value);
        std::string    Get_phone_number(void);
        void Set_phone_number(std::string value);
        std::string    Get_first_name(void);
        void Set_first_name(std::string value);
        std::string    Get_last_name(void);
        void Set_last_name(std::string value);
        std::string    Get_nickname(void);
        void Set_nickname(std::string value);
        int    Get_index(void);
        void     Set_index(int value);
};

#endif