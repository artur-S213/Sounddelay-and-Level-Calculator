find_package(Qt6 REQUIRED COMPONENTS Test)

add_executable(CoreCalculationsTest
    test_CoreCalculations.cpp
    ../src/Core/CoreCalculations.cpp
)

target_include_directories(CoreCalculationsTest PRIVATE
    ../src/Core
)

target_link_libraries(CoreCalculationsTest PRIVATE
    Qt6::Test
)

add_test(NAME CoreCalculationsTest COMMAND CoreCalculationsTest)
