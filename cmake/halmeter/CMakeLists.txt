cmake_minimum_required(VERSION 3.0)
set(PROJECT "halmeter")
project(${PROJECT} CXX C) 

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")

# Set includepaths.
include_directories(${SRC_DIR})
include_directories(${SRC_DIR}/../rtapi_src)
include_directories(${SRC_DIR}/../liblinuxcnchal_src)
include_directories(${SRC_DIR}/../common_src)

# Gtk include dirs.
include_directories(/usr/local/include/freetype2)
include_directories(/usr/local/include)
include_directories(/usr/include/gtk-3.0)
include_directories(/usr/include/at-spi2-atk/2.0)
include_directories(/usr/include/at-spi-2.0)
include_directories(/usr/include/dbus-1.0)
include_directories(/usr/lib/x86_64-linux-gnu/dbus-1.0/include)
include_directories(/usr/include/gtk-3.0)
include_directories(/usr/include/gio-unix-2.0)
include_directories(/usr/include/cairo)
include_directories(/usr/include/pango-1.0)
include_directories(/usr/include/fribidi)
include_directories(/usr/include/harfbuzz)
include_directories(/usr/include/atk-1.0)
include_directories(/usr/include/pixman-1)
include_directories(/usr/include/uuid)
include_directories(/usr/include/libpng16)
include_directories(/usr/include/gdk-pixbuf-2.0)
include_directories(/usr/include/libmount)
include_directories(/usr/include/blkid)
include_directories(/usr/include/glib-2.0)
include_directories(/usr/lib/x86_64-linux-gnu/glib-2.0/include)

# Set prefix.
# set(CMAKE_SHARED_LIBRARY_PREFIX "")

set(SOURCES
    ${SRC_DIR}/../halmeter_src/meter.c
    ${SRC_DIR}/../common_src/miscgtk.c
)

add_executable(${PROJECT_NAME} ${SOURCES})

add_definitions(-DULAPI)

# Set include paths for libraries to link.
#target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR}/libnml)

# Link to libraries.
target_link_libraries(${PROJECT_NAME} PRIVATE liblinuxcnchal -pthread
    -lgtk-3 -lgdk-3 -lpangocairo-1.0 -lpango-1.0 -lharfbuzz -latk-1.0
    -lcairo-gobject -lcairo -lgdk_pixbuf-2.0 -lgio-2.0 -lgobject-2.0
    -lglib-2.0
)

# Set custom output name :
# set_property(TARGET  ${PROJECT} PROPERTY OUTPUT_NAME thename)

# Make install
install(TARGETS ${PROJECT} DESTINATION ${BUILD_DIR}/../../../bin)

# Notes.
