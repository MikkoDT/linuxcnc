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
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR}/liblinuxcnchal)

# Link to libraries.
target_link_libraries(${PROJECT_NAME} PRIVATE liblinuxcnchal -pthread
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
#[[Compiling hal/classicladder/arithm_eval.c
gcc -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer
-Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc
-Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9
-Os -fwrapv  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2  -DULAPI -std=gnu11 -Werror=implicit-function-declaration
-g -O2  -pthread -I/usr/local/include/freetype2 -I/usr/local/include -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include
-I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/libmount
-I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/harfbuzz -I/usr/include/glib-2.0
-I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/uuid -I/usr/include/libpng16 -DGTK_INTERFACE -DGTK2 -Wno-deprecated-declarations
-DSEQUENTIAL_SUPPORT -DHAL_SUPPORT -DDYNAMIC_PLCSIZE -DRT_SUPPORT -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER \
        -MP -MD -MF "objects/hal/classicladder/arithm_eval.d" -MT "objects/hal/classicladder/arithm_eval.o" \
        hal/classicladder/arithm_eval.c -o objects/hal/classicladder/arithm_eval.o
Compiling hal/classicladder/arrays.c
gcc -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9 -Os -fwrapv  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2  -DULAPI -std=gnu11 -Werror=implicit-function-declaration -g -O2  -pthread -I/usr/local/include/freetype2 -I/usr/local/include -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/harfbuzz -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/uuid -I/usr/include/libpng16 -DGTK_INTERFACE -DGTK2 -Wno-deprecated-declarations -DSEQUENTIAL_SUPPORT -DHAL_SUPPORT -DDYNAMIC_PLCSIZE -DRT_SUPPORT -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER \
        -MP -MD -MF "objects/hal/classicladder/arrays.d" -MT "objects/hal/classicladder/arrays.o" \
        hal/classicladder/arrays.c -o objects/hal/classicladder/arrays.o
Compiling hal/classicladder/calc.c
gcc -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9 -Os -fwrapv  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2  -DULAPI -std=gnu11 -Werror=implicit-function-declaration -g -O2  -pthread -I/usr/local/include/freetype2 -I/usr/local/include -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/harfbuzz -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/uuid -I/usr/include/libpng16 -DGTK_INTERFACE -DGTK2 -Wno-deprecated-declarations -DSEQUENTIAL_SUPPORT -DHAL_SUPPORT -DDYNAMIC_PLCSIZE -DRT_SUPPORT -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER \
        -MP -MD -MF "objects/hal/classicladder/calc.d" -MT "objects/hal/classicladder/calc.o" \
        hal/classicladder/calc.c -o objects/hal/classicladder/calc.o
Compiling hal/classicladder/calc_sequential.c
gcc -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9 -Os -fwrapv  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2  -DULAPI -std=gnu11 -Werror=implicit-function-declaration -g -O2  -pthread -I/usr/local/include/freetype2 -I/usr/local/include -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/harfbuzz -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/uuid -I/usr/include/libpng16 -DGTK_INTERFACE -DGTK2 -Wno-deprecated-declarations -DSEQUENTIAL_SUPPORT -DHAL_SUPPORT -DDYNAMIC_PLCSIZE -DRT_SUPPORT -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER \
        -MP -MD -MF "objects/hal/classicladder/calc_sequential.d" -MT "objects/hal/classicladder/calc_sequential.o" \
        hal/classicladder/calc_sequential.c -o objects/hal/classicladder/calc_sequential.o
Compiling hal/classicladder/classicladder.c
gcc -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9 -Os -fwrapv  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2  -DULAPI -std=gnu11 -Werror=implicit-function-declaration -g -O2  -pthread -I/usr/local/include/freetype2 -I/usr/local/include -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/harfbuzz -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/uuid -I/usr/include/libpng16 -DGTK_INTERFACE -DGTK2 -Wno-deprecated-declarations -DSEQUENTIAL_SUPPORT -DHAL_SUPPORT -DDYNAMIC_PLCSIZE -DRT_SUPPORT -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER \
        -MP -MD -MF "objects/hal/classicladder/classicladder.d" -MT "objects/hal/classicladder/classicladder.o" \
        hal/classicladder/classicladder.c -o objects/hal/classicladder/classicladder.o
Compiling hal/classicladder/classicladder_gtk.c
gcc -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9 -Os -fwrapv  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2  -DULAPI -std=gnu11 -Werror=implicit-function-declaration -g -O2  -pthread -I/usr/local/include/freetype2 -I/usr/local/include -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/harfbuzz -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/uuid -I/usr/include/libpng16 -DGTK_INTERFACE -DGTK2 -Wno-deprecated-declarations -DSEQUENTIAL_SUPPORT -DHAL_SUPPORT -DDYNAMIC_PLCSIZE -DRT_SUPPORT -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER \
        -MP -MD -MF "objects/hal/classicladder/classicladder_gtk.d" -MT "objects/hal/classicladder/classicladder_gtk.o" \
        hal/classicladder/classicladder_gtk.c -o objects/hal/classicladder/classicladder_gtk.o
Compiling hal/classicladder/config.c
gcc -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9 -Os -fwrapv  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2  -DULAPI -std=gnu11 -Werror=implicit-function-declaration -g -O2  -pthread -I/usr/local/include/freetype2 -I/usr/local/include -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/harfbuzz -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/uuid -I/usr/include/libpng16 -DGTK_INTERFACE -DGTK2 -Wno-deprecated-declarations -DSEQUENTIAL_SUPPORT -DHAL_SUPPORT -DDYNAMIC_PLCSIZE -DRT_SUPPORT -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER \
        -MP -MD -MF "objects/hal/classicladder/config.d" -MT "objects/hal/classicladder/config.o" \
        hal/classicladder/config.c -o objects/hal/classicladder/config.o
Compiling hal/classicladder/config_gtk.c
gcc -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9 -Os -fwrapv  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2  -DULAPI -std=gnu11 -Werror=implicit-function-declaration -g -O2  -pthread -I/usr/local/include/freetype2 -I/usr/local/include -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/harfbuzz -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/uuid -I/usr/include/libpng16 -DGTK_INTERFACE -DGTK2 -Wno-deprecated-declarations -DSEQUENTIAL_SUPPORT -DHAL_SUPPORT -DDYNAMIC_PLCSIZE -DRT_SUPPORT -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER \
        -MP -MD -MF "objects/hal/classicladder/config_gtk.d" -MT "objects/hal/classicladder/config_gtk.o" \
        hal/classicladder/config_gtk.c -o objects/hal/classicladder/config_gtk.o
Compiling hal/classicladder/drawing.c
gcc -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9 -Os -fwrapv  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2  -DULAPI -std=gnu11 -Werror=implicit-function-declaration -g -O2  -pthread -I/usr/local/include/freetype2 -I/usr/local/include -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/harfbuzz -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/uuid -I/usr/include/libpng16 -DGTK_INTERFACE -DGTK2 -Wno-deprecated-declarations -DSEQUENTIAL_SUPPORT -DHAL_SUPPORT -DDYNAMIC_PLCSIZE -DRT_SUPPORT -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER \
        -MP -MD -MF "objects/hal/classicladder/drawing.d" -MT "objects/hal/classicladder/drawing.o" \
        hal/classicladder/drawing.c -o objects/hal/classicladder/drawing.o
Compiling hal/classicladder/drawing_sequential.c
gcc -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9 -Os -fwrapv  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2  -DULAPI -std=gnu11 -Werror=implicit-function-declaration -g -O2  -pthread -I/usr/local/include/freetype2 -I/usr/local/include -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/harfbuzz -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/uuid -I/usr/include/libpng16 -DGTK_INTERFACE -DGTK2 -Wno-deprecated-declarations -DSEQUENTIAL_SUPPORT -DHAL_SUPPORT -DDYNAMIC_PLCSIZE -DRT_SUPPORT -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER \
        -MP -MD -MF "objects/hal/classicladder/drawing_sequential.d" -MT "objects/hal/classicladder/drawing_sequential.o" \
        hal/classicladder/drawing_sequential.c -o objects/hal/classicladder/drawing_sequential.o
Compiling hal/classicladder/edit.c
gcc -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9 -Os -fwrapv  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2  -DULAPI -std=gnu11 -Werror=implicit-function-declaration -g -O2  -pthread -I/usr/local/include/freetype2 -I/usr/local/include -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/harfbuzz -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/uuid -I/usr/include/libpng16 -DGTK_INTERFACE -DGTK2 -Wno-deprecated-declarations -DSEQUENTIAL_SUPPORT -DHAL_SUPPORT -DDYNAMIC_PLCSIZE -DRT_SUPPORT -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER \
        -MP -MD -MF "objects/hal/classicladder/edit.d" -MT "objects/hal/classicladder/edit.o" \
        hal/classicladder/edit.c -o objects/hal/classicladder/edit.o
Compiling hal/classicladder/edit_gtk.c
gcc -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9 -Os -fwrapv  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2  -DULAPI -std=gnu11 -Werror=implicit-function-declaration -g -O2  -pthread -I/usr/local/include/freetype2 -I/usr/local/include -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/harfbuzz -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/uuid -I/usr/include/libpng16 -DGTK_INTERFACE -DGTK2 -Wno-deprecated-declarations -DSEQUENTIAL_SUPPORT -DHAL_SUPPORT -DDYNAMIC_PLCSIZE -DRT_SUPPORT -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER \
        -MP -MD -MF "objects/hal/classicladder/edit_gtk.d" -MT "objects/hal/classicladder/edit_gtk.o" \
        hal/classicladder/edit_gtk.c -o objects/hal/classicladder/edit_gtk.o
Compiling hal/classicladder/edit_sequential.c
gcc -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9 -Os -fwrapv  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2  -DULAPI -std=gnu11 -Werror=implicit-function-declaration -g -O2  -pthread -I/usr/local/include/freetype2 -I/usr/local/include -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/harfbuzz -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/uuid -I/usr/include/libpng16 -DGTK_INTERFACE -DGTK2 -Wno-deprecated-declarations -DSEQUENTIAL_SUPPORT -DHAL_SUPPORT -DDYNAMIC_PLCSIZE -DRT_SUPPORT -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER \
        -MP -MD -MF "objects/hal/classicladder/edit_sequential.d" -MT "objects/hal/classicladder/edit_sequential.o" \
        hal/classicladder/edit_sequential.c -o objects/hal/classicladder/edit_sequential.o
Compiling hal/classicladder/editproperties_gtk.c
gcc -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9 -Os -fwrapv  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2  -DULAPI -std=gnu11 -Werror=implicit-function-declaration -g -O2  -pthread -I/usr/local/include/freetype2 -I/usr/local/include -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/harfbuzz -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/uuid -I/usr/include/libpng16 -DGTK_INTERFACE -DGTK2 -Wno-deprecated-declarations -DSEQUENTIAL_SUPPORT -DHAL_SUPPORT -DDYNAMIC_PLCSIZE -DRT_SUPPORT -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER \
        -MP -MD -MF "objects/hal/classicladder/editproperties_gtk.d" -MT "objects/hal/classicladder/editproperties_gtk.o" \
        hal/classicladder/editproperties_gtk.c -o objects/hal/classicladder/editproperties_gtk.o
Compiling hal/classicladder/emc_mods.c
gcc -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9 -Os -fwrapv  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2  -DULAPI -std=gnu11 -Werror=implicit-function-declaration -g -O2  -pthread -I/usr/local/include/freetype2 -I/usr/local/include -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/harfbuzz -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/uuid -I/usr/include/libpng16 -DGTK_INTERFACE -DGTK2 -Wno-deprecated-declarations -DSEQUENTIAL_SUPPORT -DHAL_SUPPORT -DDYNAMIC_PLCSIZE -DRT_SUPPORT -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER \
        -MP -MD -MF "objects/hal/classicladder/emc_mods.d" -MT "objects/hal/classicladder/emc_mods.o" \
        hal/classicladder/emc_mods.c -o objects/hal/classicladder/emc_mods.o
Compiling hal/classicladder/files.c
gcc -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9 -Os -fwrapv  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2  -DULAPI -std=gnu11 -Werror=implicit-function-declaration -g -O2  -pthread -I/usr/local/include/freetype2 -I/usr/local/include -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/harfbuzz -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/uuid -I/usr/include/libpng16 -DGTK_INTERFACE -DGTK2 -Wno-deprecated-declarations -DSEQUENTIAL_SUPPORT -DHAL_SUPPORT -DDYNAMIC_PLCSIZE -DRT_SUPPORT -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER \
        -MP -MD -MF "objects/hal/classicladder/files.d" -MT "objects/hal/classicladder/files.o" \
        hal/classicladder/files.c -o objects/hal/classicladder/files.o
Compiling hal/classicladder/files_project.c
gcc -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9 -Os -fwrapv  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2  -DULAPI -std=gnu11 -Werror=implicit-function-declaration -g -O2  -pthread -I/usr/local/include/freetype2 -I/usr/local/include -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/harfbuzz -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/uuid -I/usr/include/libpng16 -DGTK_INTERFACE -DGTK2 -Wno-deprecated-declarations -DSEQUENTIAL_SUPPORT -DHAL_SUPPORT -DDYNAMIC_PLCSIZE -DRT_SUPPORT -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER \
        -MP -MD -MF "objects/hal/classicladder/files_project.d" -MT "objects/hal/classicladder/files_project.o" \
        hal/classicladder/files_project.c -o objects/hal/classicladder/files_project.o
Compiling hal/classicladder/files_sequential.c
gcc -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9 -Os -fwrapv  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2  -DULAPI -std=gnu11 -Werror=implicit-function-declaration -g -O2  -pthread -I/usr/local/include/freetype2 -I/usr/local/include -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/harfbuzz -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/uuid -I/usr/include/libpng16 -DGTK_INTERFACE -DGTK2 -Wno-deprecated-declarations -DSEQUENTIAL_SUPPORT -DHAL_SUPPORT -DDYNAMIC_PLCSIZE -DRT_SUPPORT -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER \
        -MP -MD -MF "objects/hal/classicladder/files_sequential.d" -MT "objects/hal/classicladder/files_sequential.o" \
        hal/classicladder/files_sequential.c -o objects/hal/classicladder/files_sequential.o
Compiling hal/classicladder/manager.c
gcc -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9 -Os -fwrapv  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2  -DULAPI -std=gnu11 -Werror=implicit-function-declaration -g -O2  -pthread -I/usr/local/include/freetype2 -I/usr/local/include -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/harfbuzz -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/uuid -I/usr/include/libpng16 -DGTK_INTERFACE -DGTK2 -Wno-deprecated-declarations -DSEQUENTIAL_SUPPORT -DHAL_SUPPORT -DDYNAMIC_PLCSIZE -DRT_SUPPORT -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER \
        -MP -MD -MF "objects/hal/classicladder/manager.d" -MT "objects/hal/classicladder/manager.o" \
        hal/classicladder/manager.c -o objects/hal/classicladder/manager.o
Compiling hal/classicladder/manager_gtk.c
gcc -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9 -Os -fwrapv  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2  -DULAPI -std=gnu11 -Werror=implicit-function-declaration -g -O2  -pthread -I/usr/local/include/freetype2 -I/usr/local/include -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/harfbuzz -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/uuid -I/usr/include/libpng16 -DGTK_INTERFACE -DGTK2 -Wno-deprecated-declarations -DSEQUENTIAL_SUPPORT -DHAL_SUPPORT -DDYNAMIC_PLCSIZE -DRT_SUPPORT -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER \
        -MP -MD -MF "objects/hal/classicladder/manager_gtk.d" -MT "objects/hal/classicladder/manager_gtk.o" \
        hal/classicladder/manager_gtk.c -o objects/hal/classicladder/manager_gtk.o
Compiling hal/classicladder/protocol_modbus_master.c
gcc -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9 -Os -fwrapv  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2  -DULAPI -std=gnu11 -Werror=implicit-function-declaration -g -O2  -pthread -I/usr/local/include/freetype2 -I/usr/local/include -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/harfbuzz -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/uuid -I/usr/include/libpng16 -DGTK_INTERFACE -DGTK2 -Wno-deprecated-declarations -DSEQUENTIAL_SUPPORT -DHAL_SUPPORT -DDYNAMIC_PLCSIZE -DRT_SUPPORT -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER \
        -MP -MD -MF "objects/hal/classicladder/protocol_modbus_master.d" -MT "objects/hal/classicladder/protocol_modbus_master.o" \
        hal/classicladder/protocol_modbus_master.c -o objects/hal/classicladder/protocol_modbus_master.o
Compiling hal/classicladder/protocol_modbus_slave.c
gcc -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9 -Os -fwrapv  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2  -DULAPI -std=gnu11 -Werror=implicit-function-declaration -g -O2  -pthread -I/usr/local/include/freetype2 -I/usr/local/include -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/harfbuzz -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/uuid -I/usr/include/libpng16 -DGTK_INTERFACE -DGTK2 -Wno-deprecated-declarations -DSEQUENTIAL_SUPPORT -DHAL_SUPPORT -DDYNAMIC_PLCSIZE -DRT_SUPPORT -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER \
        -MP -MD -MF "objects/hal/classicladder/protocol_modbus_slave.d" -MT "objects/hal/classicladder/protocol_modbus_slave.o" \
        hal/classicladder/protocol_modbus_slave.c -o objects/hal/classicladder/protocol_modbus_slave.o
Compiling hal/classicladder/serial_linux.c
gcc -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9 -Os -fwrapv  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2  -DULAPI -std=gnu11 -Werror=implicit-function-declaration -g -O2  -pthread -I/usr/local/include/freetype2 -I/usr/local/include -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/harfbuzz -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/uuid -I/usr/include/libpng16 -DGTK_INTERFACE -DGTK2 -Wno-deprecated-declarations -DSEQUENTIAL_SUPPORT -DHAL_SUPPORT -DDYNAMIC_PLCSIZE -DRT_SUPPORT -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER \
        -MP -MD -MF "objects/hal/classicladder/serial_linux.d" -MT "objects/hal/classicladder/serial_linux.o" \
        hal/classicladder/serial_linux.c -o objects/hal/classicladder/serial_linux.o
Compiling hal/classicladder/socket_modbus_master.c
gcc -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9 -Os -fwrapv  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2  -DULAPI -std=gnu11 -Werror=implicit-function-declaration -g -O2  -pthread -I/usr/local/include/freetype2 -I/usr/local/include -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/harfbuzz -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/uuid -I/usr/include/libpng16 -DGTK_INTERFACE -DGTK2 -Wno-deprecated-declarations -DSEQUENTIAL_SUPPORT -DHAL_SUPPORT -DDYNAMIC_PLCSIZE -DRT_SUPPORT -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER \
        -MP -MD -MF "objects/hal/classicladder/socket_modbus_master.d" -MT "objects/hal/classicladder/socket_modbus_master.o" \
        hal/classicladder/socket_modbus_master.c -o objects/hal/classicladder/socket_modbus_master.o
Compiling hal/classicladder/socket_server.c
gcc -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9 -Os -fwrapv  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2  -DULAPI -std=gnu11 -Werror=implicit-function-declaration -g -O2  -pthread -I/usr/local/include/freetype2 -I/usr/local/include -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/harfbuzz -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/uuid -I/usr/include/libpng16 -DGTK_INTERFACE -DGTK2 -Wno-deprecated-declarations -DSEQUENTIAL_SUPPORT -DHAL_SUPPORT -DDYNAMIC_PLCSIZE -DRT_SUPPORT -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER \
        -MP -MD -MF "objects/hal/classicladder/socket_server.d" -MT "objects/hal/classicladder/socket_server.o" \
        hal/classicladder/socket_server.c -o objects/hal/classicladder/socket_server.o
Compiling hal/classicladder/spy_vars_gtk.c
gcc -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9 -Os -fwrapv  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2  -DULAPI -std=gnu11 -Werror=implicit-function-declaration -g -O2  -pthread -I/usr/local/include/freetype2 -I/usr/local/include -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/harfbuzz -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/uuid -I/usr/include/libpng16 -DGTK_INTERFACE -DGTK2 -Wno-deprecated-declarations -DSEQUENTIAL_SUPPORT -DHAL_SUPPORT -DDYNAMIC_PLCSIZE -DRT_SUPPORT -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER \
        -MP -MD -MF "objects/hal/classicladder/spy_vars_gtk.d" -MT "objects/hal/classicladder/spy_vars_gtk.o" \
        hal/classicladder/spy_vars_gtk.c -o objects/hal/classicladder/spy_vars_gtk.o
Compiling hal/classicladder/symbols.c
gcc -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9 -Os -fwrapv  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2  -DULAPI -std=gnu11 -Werror=implicit-function-declaration -g -O2  -pthread -I/usr/local/include/freetype2 -I/usr/local/include -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/harfbuzz -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/uuid -I/usr/include/libpng16 -DGTK_INTERFACE -DGTK2 -Wno-deprecated-declarations -DSEQUENTIAL_SUPPORT -DHAL_SUPPORT -DDYNAMIC_PLCSIZE -DRT_SUPPORT -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER \
        -MP -MD -MF "objects/hal/classicladder/symbols.d" -MT "objects/hal/classicladder/symbols.o" \
        hal/classicladder/symbols.c -o objects/hal/classicladder/symbols.o
Compiling hal/classicladder/symbols_gtk.c
gcc -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9 -Os -fwrapv  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2  -DULAPI -std=gnu11 -Werror=implicit-function-declaration -g -O2  -pthread -I/usr/local/include/freetype2 -I/usr/local/include -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/harfbuzz -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/uuid -I/usr/include/libpng16 -DGTK_INTERFACE -DGTK2 -Wno-deprecated-declarations -DSEQUENTIAL_SUPPORT -DHAL_SUPPORT -DDYNAMIC_PLCSIZE -DRT_SUPPORT -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER \
        -MP -MD -MF "objects/hal/classicladder/symbols_gtk.d" -MT "objects/hal/classicladder/symbols_gtk.o" \
        hal/classicladder/symbols_gtk.c -o objects/hal/classicladder/symbols_gtk.o
Compiling hal/classicladder/vars_names.c
gcc -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9 -Os -fwrapv  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2  -DULAPI -std=gnu11 -Werror=implicit-function-declaration -g -O2  -pthread -I/usr/local/include/freetype2 -I/usr/local/include -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/harfbuzz -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/uuid -I/usr/include/libpng16 -DGTK_INTERFACE -DGTK2 -Wno-deprecated-declarations -DSEQUENTIAL_SUPPORT -DHAL_SUPPORT -DDYNAMIC_PLCSIZE -DRT_SUPPORT -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER \
        -MP -MD -MF "objects/hal/classicladder/vars_names.d" -MT "objects/hal/classicladder/vars_names.o" \
        hal/classicladder/vars_names.c -o objects/hal/classicladder/vars_names.o
Compiling hal/classicladder/vars_access.c
gcc -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include -I/usr/include/python3.9 -Os -fwrapv  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2  -DULAPI -std=gnu11 -Werror=implicit-function-declaration -g -O2  -pthread -I/usr/local/include/freetype2 -I/usr/local/include -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0 -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/harfbuzz -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -I/usr/include/uuid -I/usr/include/libpng16 -DGTK_INTERFACE -DGTK2 -Wno-deprecated-declarations -DSEQUENTIAL_SUPPORT -DHAL_SUPPORT -DDYNAMIC_PLCSIZE -DRT_SUPPORT -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER \
        -MP -MD -MF "objects/hal/classicladder/vars_access.d" -MT "objects/hal/classicladder/vars_access.o" \
        hal/classicladder/vars_access.c -o objects/hal/classicladder/vars_access.o
Linking classicladder
]]
