cmake_minimum_required(VERSION 3.16)

project(VaultTones01 VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Quick Core5Compat)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
qt_standard_project_setup()

qt_add_executable(appVaultTones01
    main.cpp
)

qt_add_qml_module(appVaultTones01
    URI VaultTones01
    VERSION 1.0
    QML_FILES
        Main.qml
        QML_FILES QML/Library/LibraryA.qml
        QML_FILES QML/Library/DelegateAlbun.qml
        QML_FILES QML/Utilities/Pallete.qml
        SOURCES librarybackend.h librarybackend.cpp
        RESOURCES Tasks.md
        QML_FILES QML/Library/SearchBar.qml
        RESOURCES sources.qrc
        QML_FILES QML/Library/IconColor.qml
        QML_FILES QML/Library/DelegateSearchBar.qml
        QML_FILES QML/Library/MiniDelegatesSearchBar.qml
        SOURCES proxylibrary.h proxylibrary.cpp
        QML_FILES QML/Textplaylist/TextPlaylist.qml
        SOURCES palettemaster.h palettemaster.cpp
        QML_FILES QML/Textplaylist/MusicAnnotator.qml
)

# Qt for iOS sets MACOSX_BUNDLE_GUI_IDENTIFIER automatically since Qt 6.1.
# If you are developing for iOS or macOS you should consider setting an
# explicit, fixed bundle identifier manually though.
set_target_properties(appVaultTones01 PROPERTIES
#    MACOSX_BUNDLE_GUI_IDENTIFIER com.example.appVaultTones01
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)
target_include_directories(appVaultTones01 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/QML)
target_include_directories(appVaultTones01 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/QML/Library)
target_include_directories(appVaultTones01 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/QML/Utilities)


target_link_libraries(appVaultTones01
    PRIVATE Qt6::Quick Qt6::Core5Compat
)

include(GNUInstallDirs)
install(TARGETS appVaultTones01
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
