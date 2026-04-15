cmake_minimum_required(VERSION 3.16)

project(Sdalcal VERSION 0.1 LANGUAGES CXX)
if(POLICY QTP0001)
    qt_policy(SET QTP0001 NEW)
endif()

set(QT_QML_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/qml)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Test)


add_subdirectory(src)

enable_testing()
add_subdirectory(tests)


set(ICON_SOURCES "")
# --- CPack Configuration ---
set(CPACK_PACKAGE_NAME ${PROJECT_NAME}")
set(CPACK_PACKAGE_VENDOR "Artur")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "A calculator to get the sounddelay between two louspeaker positions with a given distance and the soundlevel of the second loudspeakers.")
set(CPACK_PACKAGE_VERSION ${PROJECT_VERSION})

if(WIN32)
    # Create .rc file
    set(RES_FILE "${CMAKE_CURRENT_BINARY_DIR}/resources.rc")
    file(WRITE "${RES_FILE}" "IDI_ICON1 ICON DISCARDABLE \"${CMAKE_CURRENT_SOURCE_DIR}/icons/icon.ico\"")
    list(APPEND ICON_SOURCES "${RES_FILE}")
    
elseif(APPLE)
    # Unter macOS wird das .icns File in das App-Bundle kopiert
    set(MACOSX_BUNDLE_ICON_FILE icon.icns)
    # Das File muss als Source hinzugefügt werden und die Location "Resources" erhalten
    set(APP_ICON_FILE "${CMAKE_CURRENT_SOURCE_DIR}/icons/icon.icns")
    set_source_files_properties("${APP_ICON_FILE}" PROPERTIES MACOSX_PACKAGE_LOCATION Resources)
    list(APPEND ICON_SOURCES "${APP_ICON_FILE}")

elseif(UNIX AND NOT APPLE)
    set(CPACK_GENERATOR "DEB;RPM")
    set(CPACK_DEBIAN_PACKAGE_MAINTAINER "arthur.scheling@gmail.com")
    set(CPACK_DEBIAN_PACKAGE_SECTION "utils")
    set(CPACK_DEBIAN_PACKAGE_DEPENDS "libqt6quick6, libqt6widgets6") # Wichtige Abhängigkeiten
    
    set(CPACK_RPM_PACKAGE_LICENSE "GPLv3") 
    set(CPACK_RPM_PACKAGE_GROUP "Applications/Utils")
endif()

include(CPack)

set_target_properties(app PROPERTIES
    MACOSX_BUNDLE_BUNDLE_NAME "Sdalcal"
    MACOSX_BUNDLE_EXECUTABLE_NAME "Sdalcal"
    MACOSX_BUNDLE_GUI_IDENTIFIER com.artur_s213.sdalcal
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE_ICON_FILE icon.icns
)

install(TARGETS app
    BUNDLE DESTINATION .   # Für macOS (.app)
    RUNTIME DESTINATION .  # Für Windows (.exe)
    LIBRARY DESTINATION .  # Für Linux/Unix (.so)
)