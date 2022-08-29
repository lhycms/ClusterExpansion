/*
 * @Author       : Liu Hanyu
 * @Email        : hyliu2016@buaa.edu.cn
 * @Date         : 2022-08-29 13:58:30
 * @LastEditTime : 2022-08-29 19:12:08
 * @FilePath     : /ClusterExpansion/src/site.hpp
 * @Description  : 
 */
#ifndef SITE_HPP
#define SITE_HPP


#include <iostream>
#include <string>
#include <vector>

#include "configuration.hpp"

class Site {
private:
    std::string element;
    std::vector<float> vec_xyz;

public:
    // Constructor
    Site(std::string element, std::vector<float>& vec_xyz_value);

    
    // Common member function
    std::string get_element(void);
    std::vector<float>& get_vec_xyz(void);


    // friend function : Overloading operator<<
    friend std::ostream& operator<<(std::ostream& COUT, Site& site);
    friend class Configuration;
};

#endif