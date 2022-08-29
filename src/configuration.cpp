/*
 * @Author       : Liu Hanyu
 * @Email        : hyliu2016@buaa.edu.cn
 * @Date         : 2022-08-29 14:45:38
 * @LastEditTime : 2022-08-29 19:39:58
 * @FilePath     : /ClusterExpansion/src/configuration.cpp
 * @Description  : 
 */
#include <iostream>
#include <iomanip>
#include <vector>

#include "configuration.hpp"
#include "site.hpp"


/*
    Part I. Member function of class `Configuration`
*/
Configuration::Configuration(
        std::vector< std::vector<float> >& basis_vectors_lst_value,
        std::vector<Site>& sites_lst_value) {
    // 1. Init `this->basis_vectors_lst`
    for (std::vector<float> basis_vector: basis_vectors_lst_value)
        this->basis_vectors_lst.push_back(basis_vector);
        
    // 2. Init `this->num_atoms`
    this->num_atoms = sites_lst_value.size();
    // 3. Init `this->sites_lst`
    for (size_t idx=0; idx<this->num_atoms; idx++) {
        this->sites_lst.push_back(sites_lst_value[idx]);
    }
}


/*
    Part II. Friend functions
*/
std::ostream& operator<<(std::ostream& COUT, Configuration& configuration) {
    // 1. 输出 basis_vectors_lst_value
    COUT << "basis vectors:\n";
    for (std::vector<float> basis_vector: configuration.basis_vectors_lst) {
        COUT << '[';
        for (int idx=0; idx<3; idx++) {
            COUT << std::setw(10) << std::right << basis_vector[idx] << ',';
        }
        COUT << "]," << std::endl;
    }

    // 2. 循环输出所有的 `Site`
    for (int idx=0; idx<configuration.num_atoms; idx++) {
        COUT << "No. " << idx << ",\t"
            << "Element. " << configuration.sites_lst[idx].get_element() << std::endl;

        COUT << '[';
        for (int idx_xyz=0; idx_xyz<3; idx_xyz++) {
            COUT << std::setw(10) << std::right 
                <<configuration.sites_lst[idx].get_vec_xyz()[idx_xyz]
                << ',';
        }
        COUT << ']';
        COUT << std::endl;
    }

    COUT << "Total number of atoms = " << configuration.num_atoms << std::endl;

    return COUT;
}


/*
    Part III. Test code

int main() {
    std::vector<std::vector<float>> basis_vectors_lst_value{{1, 2, 3},
                                                            {4, 5, 6},
                                                            {7, 8, 9}};
    std::vector<float> vec_xyz_value = {1, 2, 3};
    Site site("Re", vec_xyz_value);
    std::vector<Site> sites_lst_value{site, site};

    Configuration configuration(basis_vectors_lst_value, sites_lst_value);
    std::cout << configuration;

    return 0;
}
*/