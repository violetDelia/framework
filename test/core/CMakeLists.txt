# #---------- set test option ----------##
option(TEST_CORE_HELPER "test core_helper" ON)
option(TEST_CORE "test core" ON)
option(TEST_SHAPE "test shape in core" ON)

if(TEST_CORE)
    option(TEST_BASE_TYPE "test base type in core" ON)
endif()
