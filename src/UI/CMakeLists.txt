qt_add_qml_module(UIModule
    URI AcousticUI
    VERSION 1.0
    QML_FILES
        Main.qml
        AICode.qml
        AICode2.qml
        NewAICode.qml
)

# set_source_files_properties(Main.qml PROPERTIES QT_QML_SINGLETON_TYPE FALSE)

target_link_libraries(UIModule PRIVATE ControllerModule)
