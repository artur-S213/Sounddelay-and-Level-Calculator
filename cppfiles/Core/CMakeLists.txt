add_library(AcousticCore STATIC
    CoreCalculations.cpp
    CoreCalculations.h
)

target_include_directories(AcousticCore INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
