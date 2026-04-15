cmake_minimum_required(VERSION 3.16)

project(Acoustic_Calculator VERSION 0.1 LANGUAGES CXX)
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

if(WIN32)
    # Unter Windows muss das Icon über eine Ressourcen-Datei (.rc) definiert werden
    # Erstelle eine temporäre .rc Datei oder lege eine im Projekt an:
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
    # Unter Linux wird das Icon meist über .desktop Files oder direkt im Code gesetzt
    # Hier fügen wir es oft als Qt-Ressource hinzu (siehe Schritt 3)
endif()


set_target_properties(app PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER com.yourdomain.acoustic-calculator
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