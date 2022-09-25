/*
 * @Author       : Liu Hanyu
 * @Email        : hyliu2016@buaa.edu.cn
 * @Date         : 2022-08-29 14:06:11
 * @LastEditTime : 2022-08-29 19:12:52
 * @FilePath     : /ClusterExpansion/src/site.cpp
 * @Description  : 
 */
#include "configuration.hpp"
#include "site.hpp"

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>


/*
    Part I. Definition of `Site` class functions
*/
Site::Site(std::string element, std::vector<float>& vec_xyz_value) {
    this->element = element;
    for (size_t idx=0; idx<3; idx++)   
        // Note the error raising segmentation.
        //      this->vec_xyz[idx] = vec_xyz[idx]
        this->vec_xyz.push_back(vec_xyz_value[idx]);
}


/*
    Part II. Common member functions
*/
std::string Site::get_element(void) {
    return this->element;
}

std::vector<float>& Site::get_vec_xyz(void) {
    return this->vec_xyz;
}


/*
    Part III. Friend function
*/
std::ostream& operator<<(std::ostream& COUT, Site& site) {
    std::cout << "Element : " << site.element << ", " << std::endl;
    std::cout << std::setw(10) << std::left << site.vec_xyz[0];
    std::cout << '\t';
    std::cout << std::setw(10) << std::left << site.vec_xyz[1];
    std::cout << '\t';
    std::cout << std::setw(10) << std::left << site.vec_xyz[2];
    std::cout << std::endl;

    return COUT;
}



/* 
    Part IV. Test code
        $ g++ -std=c++20 -Og site.cpp -o test
        $ ./test

int main() {
    std::vector<float> vec_xyz_value = {1, 2, 3};
    Site site("Re", vec_xyz_value);
    std::cout << site;
    return 0;
}
*/