include(FetchContent)

FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.11.0
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(battleShip_test UnitTests.cpp)

target_link_libraries(battleShip_test
        PRIVATE
        GTest::GTest
        BattleShip)

add_test(battleShip_gtests battleShip_test)
