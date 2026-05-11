if(WIN32)
    set(RES_FILE "${CMAKE_CURRENT_BINARY_DIR}/resources.rc")
    file(WRITE "${RES_FILE}" "IDI_ICON1 ICON DISCARDABLE \"${CMAKE_CURRENT_SOURCE_DIR}/../icons/icon.ico\"")
    set(ICON_SOURCES ${RES_FILE})
endif()


include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(Sdalcal 
    main.cpp
    ${ICON_SOURCES}

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



