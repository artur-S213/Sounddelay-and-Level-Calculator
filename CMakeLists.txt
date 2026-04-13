cmake_minimum_required(VERSION 3.16)

project(Acoustic_Calculator VERSION 0.1 LANGUAGES CXX)

set(QT_QML_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/qml)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Test)


add_subdirectory(src)

enable_testing()
add_subdirectory(tests)


if(WIN32)
    # Bindet die .rc Datei ein, die auf icon.ico verweist
    # Pfad ist relativ zur CMakeLists.txt
    set(SOURCES ${SOURCES} icons/resources.rc)

elseif(APPLE)
    # Icon für das macOS .app Bundle
    set(MACOSX_BUNDLE_ICON_FILE icons/icon.icns)
    set_source_files_properties(icons/icon.icns PROPERTIES MACOSX_PACKAGE_LOCATION Resources)
    set(SOURCES ${SOURCES} icons/icon.icns)

endif()




# # Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# # If you are developing for iOS or macOS you should consider setting an
# # explicit, fixed bundle identifier manually though.
# set_target_properties(appAcoustic_Calculator PROPERTIES
# #    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appAcoustic_Calculator
#     MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
#     MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
#     MACOSX_BUNDLE TRUE
#     WIN32_EXECUTABLE TRUE
# )

# include(GNUInstallDirs)
# install(TARGETS appAcoustic_Calculator
#     BUNDLE DESTINATION .
#     LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
#     RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
# )
