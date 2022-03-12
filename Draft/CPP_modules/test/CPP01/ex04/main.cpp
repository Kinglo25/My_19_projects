/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jandre <ajuln@hotmail.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 18:47:23 by jandre            #+#    #+#             */
/*   Updated: 2021/08/17 19:56:54 by jandre           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>

int    replace(std::string filename, std::string s1, std::string s2)
{
    std::ifstream   infile;
    std::ofstream   outfile;
    std::string     line;
    size_t          i;
    int             test;
    
    infile.open(filename);
    outfile.open(filename + ".replace");
    if (!infile.is_open() || !outfile.is_open())
    {
        std::cout << "Error opening file" << std::endl;
        return (0);
    }
    test = 0;
    while (std::getline(infile, line))
    {
        if (test == 1)
            outfile << std::endl;
        i = 0;
        test = 1;
        while (i < line.length())
        {
            if (line.substr(i, s1.length()) == s1)
            {
                outfile << s2;
                i += s1.length();
            }
            else
            {
                outfile << line.substr(i, 1);
                i++;
            }
        }

    }
    return (0);
}

int main(int argc, char **argv)
{
    std::string     filename;
    std::string     s1;
    std::string     s2;

    if (argc != 4)
    {
        std::cout << "Use the program like that :" << std::endl << "./replace file_to_open string_to_replace string_to_replace_with" << std::endl;
        return (0);
    }
    filename = argv[1];
    s1 = argv[2];
    s2 = argv[3];
    return (replace(filename, s1, s2));
}