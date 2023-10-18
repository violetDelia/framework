#include "install/include/framwork.hpp"
#include <iostream>
// g++ shape_tutorials.cpp -o shape_tutorials.exe -std=c++20
// ./shape_tutorials
int main()
{
    std::cout << "---------- shape construct ----------" << std::endl;

    std::cout << "1.use initializer_list" << std::endl;
    Framework::Shape<int> shape_1{1, 2, 3};
    std::cout << "shape_1: " << shape_1 << std::endl;
    std::cout << std::endl;

    std::cout << "2.use other Shape" << std::endl;
    Framework::Shape<int> shape_2(shape_1);
    std::cout << "shape_2: " << shape_1 << std::endl;
    std::cout << std::endl;

    std::cout << "3.use other Shape(move)" << std::endl;
    Framework::Shape<int> shape_3(std::move(shape_1));
    std::cout << "shape_3: " << shape_3 << std::endl;
    std::cout << "shape_1: " << shape_1 << std::endl;
    std::cout << std::endl;

    std::cout << "4.use iterator" << std::endl;
    std::vector<int> vector_1{1, 2, 3};
    Framework::Shape<int> shape_4(vector_1.begin(), vector_1.end());
    std::cout << "shape_4: " << shape_4 << std::endl;
    std::cout << std::endl;

    std::cout << "5.use operator=" << std::endl;
    Framework::Shape<int> shape_5;
    shape_5 = shape_4;
    std::cout << "shape_4: " << shape_4 << std::endl;
    std::cout << "shape_5: " << shape_5 << std::endl;
    std::cout << std::endl;

    std::cout << "---------- at ----------" << std::endl;
    std::cout << "shape_5: " << shape_5 << std::endl;
    std::cout << "shape_5.at(0): " << shape_5.at(0) << std::endl;
    std::cout << "shape_5.at(1): " << shape_5.at(1) << std::endl;
    std::cout << "shape_5.at(2): " << shape_5.at(2) << std::endl;
    std::cout << std::endl;

    std::cout << "---------- size ----------" << std::endl;
    std::cout << "shape_5: " << shape_5 << std::endl;
    std::cout << "shape_5.size(): " << shape_5.size() << std::endl;
    std::cout << "shape_1: " << shape_1 << std::endl;
    std::cout << "shape_1.size(): " << shape_1.size() << std::endl;
    std::cout << std::endl;

    std::cout << "---------- reshape ----------" << std::endl;

    std::cout << "1.use initializer_list" << std::endl;
    std::cout << "before reshape shape_5: " << shape_5 << std::endl;
    shape_5.reshape({7, 8, 9, 10, 11, 12});
    std::cout << "after reshape shape_5: " << shape_5 << std::endl;
    std::cout << std::endl;

    std::cout << "2.use shape" << std::endl;
    std::cout << "before reshape shape_5: " << shape_5 << std::endl;
    std::cout << "shape_4: " << shape_4 << std::endl;
    shape_5.reshape(shape_4);
    std::cout << "after reshape shape_5: " << shape_5 << std::endl;
    std::cout << std::endl;

    std::cout << "3.use iterator" << std::endl;
    std::cout << "before reshape shape_1: " << shape_1 << std::endl;
    std::cout << "shape_4: " << shape_4 << std::endl;
    shape_1.reshape(shape_4.begin(), shape_4.end());;
    std::cout << "after reshape shape_1: " << shape_1 << std::endl;
    std::cout << std::endl;

    return 0;
}