
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
template <typename Ty>
struct _Is_Eigen_Tensor_Implement : public std::false_type
{
};

template <template <typename, int, int, typename> typename Ty, typename Scalar_, int NumIndices_, int Options_, typename IndexType_>
struct _Is_Eigen_Tensor_Implement<Ty<Scalar_, NumIndices_, Options_, IndexType_>> : public std::is_same<Ty<Scalar_, NumIndices_, Options_, IndexType_>, Eigen::Tensor<Scalar_, NumIndices_, Options_, IndexType_>>
{
};

template <typename Ty>
concept is_Eigen_Tensor = _Is_Eigen_Tensor_Implement<Ty>::value;
// //--------- implement of is_Eigen_Tensor ----------//
template <typename Base, typename = void>
class A
{
public:
    A() { std::cout << "base" << std::endl; }
};
template <Framework::is_Eigen_Tensor Base>
class A<Base, void>
{
public:
    A() { std::cout << "tensor" << std::endl; }
};
int main()
{

    Framework::Tensor<Eigen::Tensor<float, 3>> tensor;
    std::cout<<typeid(tensor._base).name()<<std::endl;
    std::cout<<sizeof(tensor._base)<<std::endl;
    std::cout<<tensor._base.dimensions()[1]<<std::endl;
    std::cout<<tensor._base.NumDimensions<<std::endl;
    //std::cout<<tensor.shape()<<std::endl;
    // std::cout<<Eigen::Tensor<float, 3>::Scalar_<<std::endl;
    //  std::cout << "adress of _operator" << std::addressof(tensor._operator) << std::endl;
    //  std::cout << typeid(tensor._operator).name() << std::endl;
    // Framework::Tensor_Operator<Eigen::Tensor<float, 3>> op;
    // std::cout << is_template_of<std::vector, std::vector<float>>::value << std::endl;
    // std::cout<<is_template_of <Eigen::Tensor,Eigen::Tensor<float, 3>>::value<<std::endl;
    //  Framework::Tensor_Operator<int> op1();

    return 0;
};