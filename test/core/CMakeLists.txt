# #---------- set test option ----------##
if(DEFINED TEST_CORE_HELPER)
    unset(TEST_CORE_HELPER CACHE)
endif()

option(TEST_CORE_HELPER "test core_helper" ON)

if(DEFINED TEST_CORE)
    unset(TEST_CORE CACHE)
endif()

option(TEST_CORE "test core" ON)

if(DEFINED TEST_SHAPE)
    unset(TEST_SHAPE CACHE)
endif()

option(TEST_SHAPE "test shape in core" ON)

if(TEST_CORE)
    if(DEFINED TEST_BASE_TYPE)
        unset(TEST_BASE_TYPE CACHE)
    endif()

    option(TEST_BASE_TYPE "test base type in core" ON)
endif()
