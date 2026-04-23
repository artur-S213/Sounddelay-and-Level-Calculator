qt_add_executable(Sdalcal
    main.cpp
)

target_link_libraries(Sdalcal
    PRIVATE
        Qt6::Quick
        Qt6::Core
        UIModule
        AcousticCore
        ControllerModule
)


qt_add_qml_module(ControllerModule
    URI AcousticController
    VERSION 1.0
    SOURCES
        controller.h
        controller.cpp
)

target_link_libraries(ControllerModule PRIVATE AcousticCore)


