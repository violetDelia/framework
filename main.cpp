#include <iomanip>
#include <iostream>
#include <limits>
#include <climits>
#include <float.h>
#include "include/framwork.hpp"
#include <eigen3/unsupported/Eigen/CXX11/Tensor>
#include <stdnoreturn.h>
#include <iterator>

template <typename T>
std::ostream &operator<<(std::ostream &s, const std::vector<T> &v)
{
    s.put('[');
    char comma[3] = {'\0', ' ', '\0'};
    for (const auto &e : v)
    {
        s << comma << e;
        comma[0] = ',';
    }
    return s << ']';
}
int main()
{

    Eigen::Tensor<float, 3> e_tensor;
    Framework::Tensor_Operator<int> op_f_3;
    Framework::Tensor_Operator<int> op_f_3_other;
    Framework::Tensor_Operator<float> op_f_2;
    // std::cout << (op_f_3_other == op_f_2) << std::endl;
    // std::cout << Framework::is_instance<Framework::Tensor_Operator<Eigen::Tensor<float, 3>>, Framework::Tensor_Operator>::value << std::endl;
    // std::cout << std::is_same<int, Framework::Tensor<Eigen::Tensor<float, 3>>::value_type>::value <<std::endl;

    std::vector<std::size_t> vector2(1);
    FRAMEWORK_NAMESPACE_NAME::Shape<std::size_t> shape8(vector2);
    std::cout<<shape8<<std::endl;
    return 0;
};