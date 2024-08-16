/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbouyahy <mbouyahy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:45:23 by mbouyahy          #+#    #+#             */
/*   Updated: 2023/09/19 15:05:18 by mbouyahy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int check_apha(char c)
{
    if (c >= 'a' && c <= 'z')
        return (1);
    return (0);
}

int main(int ac, char **av)
{
    int i;
    int j;

    i = 1;
    if (ac > 1)
    {
        while (av[i])
        {
            j = 0;
            while (av[i][j])
            {
                if (check_apha(av[i][j]) == 1)
                {
                    av[i][j] -= 32;
                }
                j++;
            }
            std::cout << av[i];
            i++;
        }
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
}