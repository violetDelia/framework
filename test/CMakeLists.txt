# #---------- external library ----------##
find_package(GTest 1.13.0 REQUIRED)
find_package(glog 0.6.0 REQUIRED)

# #---------- set aux variable ----------##
set(TENSOR_RELATIVE_DIR "tensor")
cmake_path(APPEND TENSOR_TEST_DIR "${TEST_DIR}" "${TENSOR_RELATIVE_DIR}")
aux_source_directory(${TENSOR_TEST_DIR} TENSOR_TEST_FILES)

set(CORE_RELATIVE_DIR "core")
cmake_path(APPEND CORE_TEST_DIR "${TEST_DIR}" "${CORE_RELATIVE_DIR}")
aux_source_directory(${CORE_TEST_DIR} CORE_TEST_FILES)

# #---------- set test option ----------##
option(TEST_FRAMWORK "test framwork" ON)


# #---------- add subdirectory ----------##
add_subdirectory(${TENSOR_TEST_DIR})
add_subdirectory(${CORE_TEST_DIR})

# executable of test
set(TEST_ALL ${FRAMEWORK_TESE_FILES} ${TENSOR_TEST_FILES} ${CORE_TEST_FILES})
message(STATUS "TEST_ALL: ${TEST_ALL}")
add_executable(${TEST_NAME} ${TEST_ALL})
set_target_properties(${TEST_NAME} PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

# #---------- set include dir ----------##
target_include_directories(${TEST_NAME}
    PUBLIC
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
    $<INSTALL_INTERFACE:include>
)
target_include_directories(${TEST_NAME} PUBLIC ${glog_INCLUDE_DIR})
target_include_directories(${TEST_NAME} PUBLIC ${GTest_INCLUDE_DIR})

# #---------- link lib ----------##
set(TEST_LINK_LIB glog GTest)

target_link_libraries(${TEST_NAME} PUBLIC FRAMEWORK ${TEST_LINK_LIB})

# define a function to simplify adding tests
function(do_test module target result)
    add_test(NAME ${module} COMMAND ${target} ${arg})
    set_tests_properties(${module}
        PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endfunction()
