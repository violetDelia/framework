# #---------- set test option ----------##
option(TEST_TENSOR "test tensor" ON)
option(TEST_TENSOR_HELP "test tensor_help" ON)

if(TEST_TENSOR_HELP)
    if(__FRAMWORK__USE__EIGEN__)
        option(TEST_is_Eigen_Tensor "test is_Eigen_Tensor" ON)
    endif()
endif()
