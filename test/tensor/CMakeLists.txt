# #---------- set test option ----------##
if(DEFINED TEST_TENSOR)
    unset(TEST_TENSOR CACHE)
endif()

option(TEST_TENSOR "test tensor" ON)

if(DEFINED TEST_TENSOR_HELP)
    unset(TEST_TENSOR_HELPCACHE)
endif()

option(TEST_TENSOR_HELP "test tensor_help" ON)

if(TEST_TENSOR_HELP)
    if(__FRAMWORK__USE__EIGEN__)
        if(DEFINED TEST_is_Eigen_Tensor)
            unset(TEST_is_Eigen_Tensor CACHE)
        endif()

        option(TEST_is_Eigen_Tensor "test is_Eigen_Tensor" ON)
    endif()
endif()
