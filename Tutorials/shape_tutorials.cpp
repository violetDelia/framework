#include "../install/include/framwork.hpp"
#include <iostream>
// g++ shape_tutorials.cpp -o shape_tutorials.exe -std=c++20
// ./shape_tutorials
int main()
{
    std::cout << "---------- Shape construct ----------" << std::endl;

    std::cout << "1.use initializer_list" << std::endl;
    Framework::Shape<int> shape_cons_1{1, 2, 3};
    std::cout << "shape_cons_1: " << shape_cons_1 << std::endl;
    std::cout << std::endl;

    std::cout << "2.use other Shape" << std::endl;
    Framework::Shape<int> shape_cons_2(shape_cons_1);
    std::cout << "shape_cons_2: " << shape_cons_2 << std::endl;
    std::cout << std::endl;

    std::cout << "3.use other Shape(move)" << std::endl;
    Framework::Shape<int> shape_cons_3(std::move(shape_cons_1));
    std::cout << "shape_cons_3: " << shape_cons_3 << std::endl;
    std::cout << "shape_cons_1: " << shape_cons_1 << std::endl;
    std::cout << std::endl;

    std::cout << "4.use iterator" << std::endl;
    std::vector<int> vector_cons_1{1, 2, 3};
    Framework::Shape<int> shape_cons_4(vector_cons_1.begin(), vector_cons_1.end());
    std::cout << "shape_cons_4: " << shape_cons_4 << std::endl;
    std::cout << std::endl;

    std::cout << "5.use operator=" << std::endl;
    Framework::Shape<int> shape_cons_5;
    shape_cons_5 = shape_cons_4;
    std::cout << "shape_cons_5: " << shape_cons_5 << std::endl;
    Framework::Shape<int> shape_cons_6 = {1, 2, 3};
    std::cout << "shape_cons_6: " << shape_cons_6 << std::endl;
    std::cout << std::endl;

    std::cout << "6.use Shape<Other_Ty>" << std::endl;
    Framework::Shape<short> shape_cons_7{1, 2, 3};
    Framework::Shape<int> shape_cons_8(shape_cons_7);
    std::cout << "shape_cons_7: " << shape_cons_7 << std::endl;
    std::cout << "shape_cons_8: " << shape_cons_8 << std::endl;
    std::cout << std::endl;

    std::cout << "6.use =Shape<Other_Ty>" << std::endl;
    Framework::Shape<short> shape_cons_9{1, 2, 3};
    Framework::Shape<int> shape_cons_10 = shape_cons_9;
    std::cout << "shape_cons_9: " << shape_cons_9 << std::endl;
    std::cout << "shape_cons_10: " << shape_cons_10 << std::endl;
    std::cout << std::endl;

    std::cout << "---------- Shape.at ----------" << std::endl;
    Framework::Shape<int> shape_at_1{1, 2, 3};
    std::cout << "shape_at_1: " << shape_at_1 << std::endl;
    std::cout << "shape_at_1.at(0): " << shape_at_1.at(0) << std::endl;
    std::cout << "shape_at_1.at(1): " << shape_at_1.at(1) << std::endl;
    std::cout << "shape_at_1.at(2): " << shape_at_1.at(2) << std::endl;
    std::cout << std::endl;

    std::cout << "---------- Shape.size ----------" << std::endl;
    Framework::Shape<int> shape_size_1{1, 2, 3};
    std::cout << "shape_size_1: " << shape_size_1 << std::endl;
    std::cout << "shape_size_1.size(): " << shape_size_1.size() << std::endl;
    Framework::Shape<int> shape_size_2;
    std::cout << "shape_size_2: " << shape_size_2 << std::endl;
    std::cout << "shape_size_2.size(): " << shape_size_2.size() << std::endl;
    std::cout << std::endl;

    std::cout << "---------- Shape.reshape ----------" << std::endl;

    std::cout << "1.use initializer_list" << std::endl;
    Framework::Shape<int> shape_reshape_1{1, 2, 3};
    std::cout << "shape_reshape_1: " << shape_reshape_1 << std::endl;
    shape_reshape_1.reshape({7, 8, 9, 10, 11, 12});
    std::cout << "after shape_reshape_1.reshape({7, 8, 9, 10, 11, 12}): " << std::endl
              << "shape_reshape_1: " << shape_reshape_1 << std::endl;
    std::cout << std::endl;

    std::cout << "2.use shape" << std::endl;
    Framework::Shape<int> shape_reshape_2{5, 5, 5};
    Framework::Shape<int> shape_reshape_3;
    std::cout << "shape_reshape_2: " << shape_reshape_2 << std::endl;
    std::cout << "shape_reshape_3: " << shape_reshape_3 << std::endl;
    shape_reshape_2.reshape(shape_reshape_3);
    std::cout << "after shape_reshape_2.reshape(shape_reshape_3): " << std::endl
              << "shape_reshape_2: " << shape_reshape_2 << std::endl;
    std::cout << std::endl;

    std::cout << "3.use iterator" << std::endl;
    Framework::Shape<int> shape_reshape_4{8};
    Framework::Shape<int> shape_reshape_5;
    std::cout << "shape_reshape_4: " << shape_reshape_4 << std::endl;
    std::cout << "hape_reshape_5: " << shape_reshape_5 << std::endl;
    shape_reshape_4.reshape(shape_reshape_5.begin(), shape_reshape_5.end());
    std::cout << "after shape_reshape_4.reshape(hape_reshape_5.begin(), hape_reshape_5.end()); " << std::endl
              << "shape_reshape_4: " << shape_reshape_4 << std::endl;
    std::cout << std::endl;

    std::cout << "4.use Shape<Other_Ty>" << std::endl;
    Framework::Shape<int> shape_reshape_6{8};
    Framework::Shape<short> shape_reshape_7;
    std::cout << "shape_reshape_6<int>: " << shape_reshape_6 << std::endl;
    std::cout << "hape_reshape_7<short>: " << shape_reshape_7 << std::endl;
    shape_reshape_6.reshape(shape_reshape_7);
    std::cout << "after shape_reshape_6.reshape(shape_reshape_7); " << std::endl
              << "shape_reshape_6: " << shape_reshape_6 << std::endl;
    std::cout << std::endl;

    std::cout << "---------- == and != ----------" << std::endl;

    Framework::Shape<int> shape_op_1{1, 2};
    Framework::Shape<int> shape_op_2{1, 2};
    Framework::Shape<int> shape_op_3{8, 9};
    std::cout << "Shape<int> [1,2] ==  Shape<int> [1,2]: " << (shape_op_1 == shape_op_2) << std::endl;
    std::cout << "Shape<int> [1,2] !=  Shape<int> [1,2]: " << (shape_op_1 != shape_op_2) << std::endl;
    std::cout << "Shape<int> [1,2] ==  Shape<int> [8,9]: " << (shape_op_1 == shape_op_3) << std::endl;
    std::cout << "Shape<int> [1,2] !=  Shape<int> [8,9]: " << (shape_op_1 != shape_op_3) << std::endl;
    std::cout << std::endl;

    Framework::Shape<short> shape_op_4{1, 2};
    Framework::Shape<long> shape_op_5{8, 9};
    std::cout << "Shape<int> [1,2] ==  Shape<short> [1,2]: " << (shape_op_1 == shape_op_4) << std::endl;
    std::cout << "Shape<int> [1,2] !=  Shape<short> [1,2]: " << (shape_op_1 != shape_op_4) << std::endl;
    std::cout << "Shape<int> [1,2] ==  Shape<long> [8,9]: " << (shape_op_1 == shape_op_5) << std::endl;
    std::cout << "Shape<int> [1,2] !=  Shape<long> [8,9]: " << (shape_op_1 != shape_op_5) << std::endl;
    std::cout << std::endl;

    system("pause");
    return 0;
}