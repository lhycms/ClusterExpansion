/*
 * @Author       : Liu Hanyu
 * @Email        : hyliu2016@buaa.edu.cn
 * @Date         : 2022-08-29 14:45:22
 * @LastEditTime : 2022-08-29 19:34:57
 * @FilePath     : /ClusterExpansion/src/configuration.hpp
 * @Description  : 
 */
#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP


#include <iostream>
#include <vector>
#include "site.hpp"


class Configuration {
private:
    int num_atoms;
    std::vector< std::vector<float> > basis_vectors_lst;
    std::vector<Site> sites_lst;

public:
    // Constructor
    Configuration(
            std::vector< std::vector<float> >& basis_vectors_lst_value,
            std::vector<Site>& sites_lst_value);

    // Friend functions
    friend std::ostream& operator<<(std::ostream& COUT, Configuration& configuration);
};


#endif