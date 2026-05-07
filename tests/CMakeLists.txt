
add_executable(CoreCalculationsTest
    test_CoreCalculations.cpp
    ../src/Core/CoreCalculations.cpp
)

target_include_directories(CoreCalculationsTest PRIVATE
    ../src/Core
)


add_test(NAME CoreCalculationsTest COMMAND CoreCalculationsTest)
