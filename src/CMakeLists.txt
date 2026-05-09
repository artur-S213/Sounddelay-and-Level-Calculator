
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(Sdalcal 
    main.cpp
)

slint_target_sources(Sdalcal 
    ui/app-window.slint
)

target_link_libraries(Sdalcal PRIVATE 
    Slint::Slint 
    SdalcalCore
)

target_include_directories(Sdalcal PRIVATE ${CMAKE_CURRENT_BINARY_DIR})

# include_directories(${slint_SOURCE_DIR}/api/cpp/include)
# include_directories(${slint_BINARY_DIR}/api/cpp/include)

add_subdirectory(Controller)
add_subdirectory(Core)



