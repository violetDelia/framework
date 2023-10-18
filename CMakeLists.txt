# #---------- cmake settings ----------##
cmake_minimum_required(VERSION 3.15)

# #---------- project settings ----------##
project(FRAMEWORK_LFR VERSION 1.0.0 LANGUAGES C CXX DESCRIPTION "AI Framwork")
set(CMAKE_DEBUG_POSTFIX _debug)
set(FRAMEWORK_INCLUDE_RELATIVE_DIR "include")
set(FRAMEWORK_SOURCE_RELATIVE_DIR "src")
set(FRAMEWORK_TEST_RELATIVE_DIR "test")

# install dir
set(INSTALL_DIR ${PROJECT_SOURCE_DIR}/install)
set(CMAKE_INSTALL_PREFIX ${INSTALL_DIR})
set(TEST_DIR ${PROJECT_SOURCE_DIR}/test)

# #---------- standard library settings ----------##
add_library(std_lib INTERFACE)
target_compile_features(std_lib INTERFACE cxx_std_20)
target_compile_features(std_lib INTERFACE c_std_11)

# #---------- set complier options ----------##
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -g -O0")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -O0")

set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -O2")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O2")

set(gcc_like_cxx "$<COMPILE_LANG_AND_ID:CXX,ARMClang,AppleClang,Clang,GNU,LCC>")
set(msvc_cxx "$<COMPILE_LANG_AND_ID:CXX,MSVC>")
target_compile_options(std_lib INTERFACE
    "$<${gcc_like_cxx}:$<BUILD_INTERFACE:-Wall;-Wextra;-Wshadow;-Wformat=2;-Wunused>>"
    "$<${msvc_cxx}:$<BUILD_INTERFACE:-W3>>"
)

# #---------- build output dirs ----------##
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}")
option(BUILD_SHARED_LIBS "Build using shared libraries" ON)

if(APPLE)
    set(CMAKE_INSTALL_RPATH "@executable_path/../lib")
elseif(UNIX)
    set(CMAKE_INSTALL_RPATH "$ORIGIN/../lib")
endif()

# #---------- set aux file variable ----------##
cmake_path(APPEND FRAMEWORK_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}" "${FRAMEWORK_INCLUDE_RELATIVE_DIR}")
cmake_path(APPEND FRAMEWORK_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}" "${FRAMEWORK_SOURCE_RELATIVE_DIR}")
aux_source_directory(${FRAMEWORK_SOURCE_DIR} FRAMEWORK_SOURCE_FILES)

# #---------- set include dir ----------##
include_directories(${FRAMEWORK_INCLUDE_DIR})
set(glog_INCLUDE_DIR "F:\\Cplus\\MSYS2\\ucrt64\\include")
set(GTest_INCLUDE_DIR "F:\\Cplus\\MSYS2\\ucrt64\\include")

option(__FRAMWORK__USE__EIGEN__ "use Eigen" ON)

if(__FRAMWORK__USE__EIGEN__)
    set(Eigen_INCLUDE_DIR "F:\\Cplus\\MSYS2\\ucrt64\\include")
endif()

# #---------- add subdirectory ----------##
add_subdirectory(${FRAMEWORK_SOURCE_DIR})

# executable of main
add_executable(main "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")
target_include_directories(main
    PUBLIC
    $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(main PUBLIC FRAMEWORK)

# #---------- generate configure header file ----------##
configure_file(config.h.in config.h)

# #---------- install ----------##
# config.h
install(FILES "${PROJECT_BINARY_DIR}/config.h"
    DESTINATION include
)

# install include dir
install(DIRECTORY "${FRAMEWORK_INCLUDE_DIR}" DESTINATION ./)

# #---------- test ----------##
option(TEST_PROJECT "test project" ON)

if(${TEST_PROJECT})
    message(STATUS "Testing project ON")
    set(TEST_NAME "${PROJECT_NAME}_test")
    enable_testing()
    configure_file(test_config.h.in test_config.h)

    # #---------- set test file variable ----------##
    cmake_path(APPEND FRAMEWORK_TEST_DIR "${CMAKE_CURRENT_SOURCE_DIR}" "${FRAMEWORK_TEST_RELATIVE_DIR}")
    aux_source_directory(${FRAMEWORK_TEST_DIR} FRAMEWORK_TESE_FILES)

    add_subdirectory(${TEST_DIR})
endif()
