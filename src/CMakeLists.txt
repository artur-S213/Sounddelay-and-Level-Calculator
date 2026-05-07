
add_executable(Sdalcal 
    main.cpp
)

add_subdirectory(Controller)
add_subdirectory(Core)

target_link_libraries(Sdalcal PRIVATE Slint::Slint SdalcalCore)

slint_target_sources(Sdalcal 
    ui/app-window.slint
)

