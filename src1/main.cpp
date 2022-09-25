/*
 * @Author       : Liu Hanyu
 * @Email        : hyliu2016@buaa.edu.cn
 * @Date         : 2022-08-29 16:17:29
 * @LastEditTime : 2022-08-29 19:34:25
 * @FilePath     : /ClusterExpansion/src/main.cpp
 * @Description  : 
 */
#include <iostream>
#include <string>
#include <vector>

#include "configuration.hpp"
#include "site.hpp"


int main() {
    std::vector< std::vector<float> > basis_vectors_lst_value{{1,2,3},
                                                            {4,5,6},
                                                            {7,8,9}};

    std::vector<float> vec_xyz_value = {1, 2, 3};
    Site site("Re", vec_xyz_value);
    std::vector<Site> sites_lst_value{site, site};

    Configuration configuration(basis_vectors_lst_value, sites_lst_value);
    std::cout << configuration;
    
    return 0;
}