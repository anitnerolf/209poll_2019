/*
** EPITECH PROJECT, 2020
** poll
** File description:
** main
*/

#include "../include/Poll.hpp"
#include <iostream>
#include <cstring>
#include <string>

int	main(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-h") == 0) {
        print_usage();
    } else if (ac == 4) {
        return (get_arguments(ac, av));
    } else {
        print_usage();
        return 84;
    }
    return 0;
}

void	print_usage(void)
{
    std::cout << "USAGE\n\t./209poll pSize dSize p\n" << std::endl;
    std::cout << "DESCRIPTION\n\tpSize\tsize of the population" << std::endl;
    std::cout << "\tsSize\tsize of the sample (supposed to be representative)" << std::endl;
    std::cout << "\tp\tpercentage of voting intentions for a specific candidate" << std::endl;
}

int	get_arguments(int ac, char **av)
{
    Poll p;

    for (int i = 1; i < ac - 1; i++) {
        if (check_if_number(av[i]) != 0) {
            std::cout << "You must enter a valid size!" << std::endl;
            return (84);
        }
    }
    if (check_if_float_number(av[3]) != 0) {
        std::cout << "You must enter a valid percentage!" << std::endl;
        return (84);
    }
    return (p.SaveValues(av));
}

int	check_if_float_number(std::string str)
{
    int count = 0;
    int number = 0;

    if (str.find('.') != std::string::npos) {
        for (int i = 0; i < str.length(); i++) {
            if ((str[i] >= 48 && str[i] <= 57) || str[i] == '.') {
                if (str[i] == '.') {
                    count++;
                }
            } else
                return 84;
        }
        if (count > 1)
            return 84;
    } else {
        if (check_if_number(str) != 0) {
            return 84;
        }
    }
    return 0;
}

int	check_if_number(std::string str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] > 57 || str[i] < 48)
            return 84;
        i++;
    }
    return 0;
}
