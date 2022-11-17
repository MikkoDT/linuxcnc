cmake_minimum_required(VERSION 3.0)
set(PROJECT "classicladder")
project(${PROJECT} CXX C) 

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")

# Set includepaths.
include_directories(${SRC_DIR})
include_directories(${SRC_DIR}/../rtapi_src)
include_directories(${SRC_DIR}/../liblinuxcnchal_src)

# Gtk include dirs.
include_directories(/usr/local/include/freetype2)

# Set prefix.
# set(CMAKE_SHARED_LIBRARY_PREFIX "")

include_directories(/usr/local/include/freetype2)
include_directories(/usr/local/include)
include_directories(/usr/include/gtk-2.0)
include_directories(/usr/lib/x86_64-linux-gnu/gtk-2.0/include)
include_directories(/usr/include/pango-1.0)
include_directories(/usr/include/atk-1.0)
include_directories(/usr/include/gdk-pixbuf-2.0)
include_directories(/usr/include/pango-1.0)
include_directories(/usr/include/libmount)
include_directories(/usr/include/blkid)
include_directories(/usr/include/fribidi)
include_directories(/usr/include/cairo)
include_directories(/usr/include/pixman-1)
include_directories(/usr/include/harfbuzz)
include_directories(/usr/include/glib-2.0)
include_directories(/usr/lib/x86_64-linux-gnu/glib-2.0/include)
include_directories(/usr/include/uuid)
include_directories(/usr/include/libpng16)

set(SOURCES
    ${SRC_DIR}/../classicladder_src/arithm_eval.c
    ${SRC_DIR}/../classicladder_src/arrays.c
    ${SRC_DIR}/../classicladder_src/calc.c
    ${SRC_DIR}/../classicladder_src/calc_sequential.c
    ${SRC_DIR}/../classicladder_src/classicladder.c
    ${SRC_DIR}/../classicladder_src/classicladder_gtk.c
    ${SRC_DIR}/../classicladder_src/config.c
    ${SRC_DIR}/../classicladder_src/config_gtk.c
    ${SRC_DIR}/../classicladder_src/drawing.c
    ${SRC_DIR}/../classicladder_src/drawing_sequential.c
    ${SRC_DIR}/../classicladder_src/edit.c
    ${SRC_DIR}/../classicladder_src/edit_gtk.c
    ${SRC_DIR}/../classicladder_src/edit_sequential.c
    ${SRC_DIR}/../classicladder_src/editproperties_gtk.c
    ${SRC_DIR}/../classicladder_src/emc_mods.c
    ${SRC_DIR}/../classicladder_src/files.c
    ${SRC_DIR}/../classicladder_src/files_project.c
    ${SRC_DIR}/../classicladder_src/files_sequential.c
    ${SRC_DIR}/../classicladder_src/manager.c
    ${SRC_DIR}/../classicladder_src/manager_gtk.c
    ${SRC_DIR}/../classicladder_src/protocol_modbus_master.c
    ${SRC_DIR}/../classicladder_src/protocol_modbus_slave.c
    ${SRC_DIR}/../classicladder_src/serial_linux.c
    ${SRC_DIR}/../classicladder_src/socket_modbus_master.c
    ${SRC_DIR}/../classicladder_src/socket_server.c
    ${SRC_DIR}/../classicladder_src/spy_vars_gtk.c
    ${SRC_DIR}/../classicladder_src/symbols.c
    ${SRC_DIR}/../classicladder_src/symbols_gtk.c
    ${SRC_DIR}/../classicladder_src/vars_names.c
    ${SRC_DIR}/../classicladder_src/vars_access.c
    # ${SRC_DIR}/../classicladder_src/print_gnome.c
    )

add_executable(${PROJECT_NAME} ${SOURCES})

add_definitions(-DULAPI -DSEQUENTIAL_SUPPORT -DHAL_SUPPORT -DDYNAMIC_PLCSIZE -DRT_SUPPORT -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER
    -DSEQUENTIAL_SUPPORT -DHAL_SUPPORT -DDYNAMIC_PLCSIZE -DRT_SUPPORT -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER
    # -DGNOME_PRINT_USE
    -DGTK_INTERFACE -DGTK2 -Wno-deprecated-declarations)

# Set include paths for libraries to link.
add_library(linuxcnchal SHARED IMPORTED) # or STATIC instead of SHARED
set_target_properties(linuxcnchal PROPERTIES
  IMPORTED_LOCATION "${SRC_DIR}/../build/liblinuxcnchal/liblinuxcnchal.so"
  INTERFACE_INCLUDE_DIRECTORIES "${SRC_DIR}/../liblinuxcnchal_src"
)

# Link to libraries.
target_link_libraries(${PROJECT_NAME} PRIVATE linuxcnchal -pthread
    -L/usr/local/lib -lgtk-x11-2.0 -lgdk-x11-2.0 -lpangocairo-1.0 -latk-1.0 -lcairo -lgdk_pixbuf-2.0
    -lgio-2.0 -lpangoft2-1.0 -lpango-1.0 -lgobject-2.0 -lglib-2.0 -lharfbuzz -lfontconfig -lfreetype
    )

# GTK2_VERSION = 2.24.33
# GTK2_CFLAGS = -pthread -I/usr/local/include/freetype2 -I/usr/local/include -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/harfbuzz -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/uuid -I/usr/include/libpng16
# GTK2_LIBS = -L/usr/local/lib -lgtk-x11-2.0 -lgdk-x11-2.0 -lpangocairo-1.0 -latk-1.0 -lcairo -lgdk_pixbuf-2.0 -lgio-2.0 -lpangoft2-1.0 -lpango-1.0 -lgobject-2.0 -lglib-2.0 -lharfbuzz -lfontconfig -lfreetype
# HAVE_GNOMEPRINT =

# Set custom output name :
# set_property(TARGET  ${PROJECT} PROPERTY OUTPUT_NAME thename)

# Make install
install(TARGETS ${PROJECT} DESTINATION ${SRC_DIR})

# Notes.
