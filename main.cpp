#include <iomanip>
#include <iostream>
#include <limits>
#include <climits>
#include <float.h>
#include "include/framwork.hpp"
int main()

{
    std::cout<<std::numeric_limits<Framework::float32_t>::is_bounded<<std::endl;
    std::cout<<FLT_TRUE_MIN<<std::endl;
    return 0;

};