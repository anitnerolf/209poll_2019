/*
** EPITECH PROJECT, 2020
** poll
** File description:
** poll
*/

#include "../include/Poll.hpp"
#include <iostream>
#include <iomanip>
#include <cmath>

Poll::Poll()
{
}

Poll::~Poll()
{
}

int	Poll::SaveValues(char **av)
{
    this->pSize = atoi(av[1]);
    this->sSize = atoi(av[2]);
    this->p = atof(av[3]);
    if (this->p < 0 || this->p > 100) {
        std::cout << "You must enter a valid percentage!" << std::endl;
        return 84;
    } else if (this->pSize <= 1 || this->sSize <= 0) {
        std::cout << "Error division by zero!" << std::endl;
        return 84;
    } else {
        this->Print_result();
        return 0;
    }
    return 0;
}

void	Poll::Print_result(void)
{
    double variance = ((this->p / 100 * (1 - (this->p / 100))) \
                       / (double)this->sSize) * (((double)this->pSize - (double)this->sSize) / ((double)this->pSize - 1.0));
    double i95 = ((2.0 * 1.96 * sqrt(variance)) / 2) * 100;
    double i95first = this->p - i95;
    double i95second = this->p + i95;
    double i99 = ((2.0 * 2.58 * sqrt(variance)) / 2) * 100;
    double i99first = this->p - i99;
    double i99second = this->p + i99;

    if (i95first < 0)
        i95first = 0.0;
    if (i95second < 0)
        i95second = 0.0;
    if (i99first < 0)
        i99first = 0.0;
    if (i99second < 0)
        i99second = 0.0;

    std::cout << "Population size:\t" << this->pSize << std::endl;
    std::cout << "Sample size:\t\t" << this->sSize << std::endl;
    std::cout << "Voting intentions:\t" << std::fixed << std::setprecision(2) << this->p << std::endl;
    std::cout << "Variance:\t\t" << std::fixed << std::setprecision(6) << variance << std::endl;
   std::cout << "95% confidence interval: [" << std::fixed << std::setprecision(2) << i95first << "%; " << i95second << "%]" << std::endl;
   std::cout << "99% confidence interval: [" << std::fixed << std::setprecision(2) << i99first << "%; " << i99second << "%]" << std::endl;
}
