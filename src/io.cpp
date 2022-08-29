/*
 * @Author       : Liu Hanyu
 * @Email        : hyliu2016@buaa.edu.cn
 * @Date         : 2022-08-29 13:41:03
 * @LastEditTime : 2022-08-29 13:50:14
 * @FilePath     : /ClusterExpansion/src/io.cpp
 * @Description  : 
 */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>


int main() {
    std::ifstream myfile("/Users/mac/我的文件/Mycode/new/new/ClusterExpansion/POSCAR");
    std::vector<std::string> vector_str;
    std::string tmp_str;

    if ( myfile.is_open() ) {
        while ( std::getline(myfile, tmp_str) )
            vector_str.push_back(tmp_str);
    }

    for (auto a: vector_str)
        std::cout << a << std::endl;

    return 0;
}