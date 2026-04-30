add_library(SdalcalCore STATIC
    CoreCalculations.cpp
    CoreCalculations.h
)

target_include_directories(SdalcalCore INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
