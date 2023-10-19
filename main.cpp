
#include <iomanip>
#include <iostream>
#include <limits>
#include <climits>
#include <float.h>
#include "include/framwork.hpp"
#include <eigen3/unsupported/Eigen/CXX11/Tensor>
#include <stdnoreturn.h>
#include <iterator>
#include <vector>
#include <map>

int main()
{

    Framework::Tensor<Eigen::Tensor<float, 3>> tensor;
    auto a = tensor.shape();
    std::cout << a << std::endl;

    //  std::cout<<Eigen::Tensor<float, 3>::Scalar_<<std::endl;
    //   std::cout << "adress of _operator" << std::addressof(tensor._operator) << std::endl;
    //   std::cout << typeid(tensor._operator).name() << std::endl;
    //  Framework::Tensor_Operator<Eigen::Tensor<float, 3>> op;
    //  std::cout << is_template_of<std::vector, std::vector<float>>::value << std::endl;
    //  std::cout<<is_template_of <Eigen::Tensor,Eigen::Tensor<float, 3>>::value<<std::endl;
    //   Framework::Tensor_Operator<int> op1();

    return 0;
};