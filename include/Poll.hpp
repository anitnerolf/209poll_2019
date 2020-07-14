/*
** EPITECH PROJECT, 2020
** poll
** File description:
** header file
*/

#ifndef POLL_HPP_
#define POLL_HPP_

#include <string>

class Poll {
public:
    Poll();
    ~Poll();
    int	SaveValues(char **);
    void Print_result(void);
    // int Loop(void);
    // double ArithmeticMean(int);
    // double HarmonicMean(int);
    // double StandardDeviation(int);
private:
    int pSize;
    int sSize;
    double p;
//     double a;
//     double h;
//     double sd;
//     std::string next_value;
};

void	print_usage(void);
int	get_arguments(int, char **);
int	check_if_number(std::string);
int	check_if_float_number(std::string);

#endif /* POLL_HPP_ */
