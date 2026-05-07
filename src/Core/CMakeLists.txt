add_library(SdalcalCore STATIC
    SdalcalCore.cpp
    SdalcalCore.h
)

target_include_directories(SdalcalCore INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
