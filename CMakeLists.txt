cmake_minimum_required(VERSION 3.16)
project(TaskManager)

# Find Qt6 packages (fallback to Qt5 if Qt6 not found)
find_package(Qt6 COMPONENTS Core Sql Widgets QUIET)
if(NOT Qt6_FOUND)
    find_package(Qt5 5.15 REQUIRED COMPONENTS Core Sql Widgets)
else()
    set(QT_VERSION_MAJOR 6)
endif()

# Enable automatic moc, uic, and rcc
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Qt6 specific settings
if(QT_VERSION_MAJOR EQUAL 6)
    qt_standard_project_setup()
endif()

# Include headers directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# Add resource file
set(RESOURCE_FILES
    resources.qrc
)

# Add executable
add_executable(TaskManager
    src/main.cpp
    src/database.cpp
    src/mainwindow.cpp
    include/mainwindow.h
    include/task.h
    include/todo.h
    include/database.h
    include/template.h
    include/calendardelegate.h
    src/calendardelegate.cpp
    ${RESOURCE_FILES}
)

# Link Qt modules
if(QT_VERSION_MAJOR EQUAL 6)
    target_link_libraries(TaskManager
        Qt6::Core
        Qt6::Sql
        Qt6::Widgets
    )
else()
    target_link_libraries(TaskManager
        Qt5::Core
        Qt5::Sql
        Qt5::Widgets
    )
endif()

install(CODE "
    file(MAKE_DIRECTORY \"\$ENV{HOME}/.local/share/TaskManager\")
")

# Include directories
target_include_directories(TaskManager PRIVATE include)

install(TARGETS TaskManager RUNTIME DESTINATION bin)