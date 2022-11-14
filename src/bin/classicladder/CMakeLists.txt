# **************************************************************************
cmake_minimum_required(VERSION 3.0)
# Component name. ~/linuxcnc/src/emc/task/
set(PROJECT "classicladder") # The name of the file excluding .c or .h
project(${PROJECT} LANGUAGES C CXX)

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(EMC_DIR "${SRC_DIR}/../../emc")
set(BIN_DIR "${SRC_DIR}/../../bin")
set(HAL_DIR "${SRC_DIR}/../../hal")
set(RTAPI_DIR "${SRC_DIR}/../../rtapi")
set(LIB_NML_DIR "${SRC_DIR}/../../libnml")
set(CONFIG_DIR "${SRC_DIR}/../../")
set(PYTHON_DIR "/usr/include/python3.9")

include_directories(${SRC_DIR})
include_directories(${EMC_DIR})
include_directories(${BIN_DIR})
include_directories(${HAL_DIR})
include_directories(${RTAPI_DIR})
include_directories(${LIB_NML_DIR})
include_directories(${CONFIG_DIR})
include_directories(${PYTHON_DIR})
include_directories(${EMC_DIR}/rs274ngc)
include_directories(${EMC_DIR}/nml_intf)
include_directories(${EMC_DIR}/motion)
include_directories(${EMC_DIR}/tooldata)
include_directories(${EMC_DIR}/task)
include_directories(${EMC_DIR}/pythonplugin)
include_directories(${EMC_DIR}/kinematics)
include_directories(${EMC_DIR}/tp)
include_directories(${EMC_DIR}/ini)
include_directories(${LIB_NML_DIR}/posemath)
include_directories(${LIB_NML_DIR}/nml)
include_directories(${LIB_NML_DIR}/rcs)
include_directories(${LIB_NML_DIR}/cms)
include_directories(${LIB_NML_DIR}/inifile)
include_directories(${LIB_NML_DIR}/os_intf)
include_directories(${LIB_NML_DIR}/../../enc/rs274ngc)

# Gtk include dirs.
include_directories(/usr/local/include/freetype2)
include_directories(/usr/local/include)
include_directories(/usr/include/at-spi2-atk/2.0)
include_directories(/usr/include/at-spi-2.0)
include_directories(/usr/include/dbus-1.0)
include_directories(/usr/lib/x86_64-linux-gnu/dbus-1.0/include)
include_directories(/usr/include/gtk-3.0)
include_directories(/usr/include/gtk-2.0)
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

# test.
include_directories("/usr/include/gtk-2.0")
include_directories("/usr/include/cairo")
include_directories("/usr/include/pango-1.0")
include_directories("/usr/include/gio-unix-2.0")
include_directories("/usr/local/include/freetype2")
include_directories("/usr/local/include")
include_directories("/usr/include/gtk-3.0")
include_directories("/usr/include/at-spi2-atk/2.0")
include_directories("/usr/include/at-spi-2.0")
include_directories("/usr/include/dbus-1.0")
include_directories("/usr/lib/x86_64-linux-gnu/dbus-1.0/include")
include_directories("/usr/include/gio-unix-2.0")
include_directories("/usr/include/fribidi")
include_directories("/usr/include/harfbuzz")
include_directories("/usr/include/atk-1.0")
include_directories("/usr/include/pixman-1")
include_directories("/usr/include/uuid")
include_directories("/usr/include/libpng16")
include_directories("/usr/include/gdk-pixbuf-2.0")
include_directories("/usr/include/libmount")
include_directories("/usr/include/blkid")
include_directories("/usr/include/glib-2.0")
include_directories("/usr/lib/x86_64-linux-gnu/glib-2.0/include")
include_directories("/usr/lib/x86_64-linux-gnu/gtk-2.0/include")

add_definitions(-DULAPI -DSEQUENTIAL_SUPPORT -DHAL_SUPPORT -DDYNAMIC_PLCSIZE -DRT_SUPPORT
    -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER  -DGTK_INTERFACE -DGTK2
)

set(SOURCES
    ${SRC_DIR}/../../hal/classicladder/arithm_eval.c
    ${SRC_DIR}/../../hal/classicladder/arrays.c
    ${SRC_DIR}/../../hal/classicladder/calc.c
    ${SRC_DIR}/../../hal/classicladder/calc_sequential.c
    ${SRC_DIR}/../../hal/classicladder/classicladder.c
    ${SRC_DIR}/../../hal/classicladder/classicladder_gtk.c
    ${SRC_DIR}/../../hal/classicladder/config.c
    ${SRC_DIR}/../../hal/classicladder/config_gtk.c
    ${SRC_DIR}/../../hal/classicladder/drawing.c
    ${SRC_DIR}/../../hal/classicladder/drawing_sequential.c
    ${SRC_DIR}/../../hal/classicladder/edit.c
    ${SRC_DIR}/../../hal/classicladder/edit_gtk.c
    ${SRC_DIR}/../../hal/classicladder/edit_sequential.c
    ${SRC_DIR}/../../hal/classicladder/editproperties_gtk.c
    ${SRC_DIR}/../../hal/classicladder/emc_mods.c
    ${SRC_DIR}/../../hal/classicladder/files.c
    ${SRC_DIR}/../../hal/classicladder/files_project.c
    ${SRC_DIR}/../../hal/classicladder/files_sequential.c
    ${SRC_DIR}/../../hal/classicladder/manager.c
    ${SRC_DIR}/../../hal/classicladder/manager_gtk.c
    ${SRC_DIR}/../../hal/classicladder/protocol_modbus_master.c
    ${SRC_DIR}/../../hal/classicladder/protocol_modbus_slave.c
    ${SRC_DIR}/../../hal/classicladder/serial_linux.c
    ${SRC_DIR}/../../hal/classicladder/socket_modbus_master.c
    ${SRC_DIR}/../../hal/classicladder/socket_server.c
    ${SRC_DIR}/../../hal/classicladder/spy_vars_gtk.c
    ${SRC_DIR}/../../hal/classicladder/symbols.c
    ${SRC_DIR}/../../hal/classicladder/symbols_gtk.c
    ${SRC_DIR}/../../hal/classicladder/vars_names.c
    ${SRC_DIR}/../../hal/classicladder/vars_access.c
    # ${SRC_DIR}/../../hal/classicladder/print_gnome.c
    )

add_executable(${PROJECT_NAME} ${SOURCES})

# liblinuxcnchal.so
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR}/src/hal/linuxcnchal)
target_include_directories(${PROJECT_NAME} PRIVATE usr/)

# Link.
target_link_libraries(${PROJECT_NAME} PRIVATE linuxcnchal -pthread -lgtk-3 -lgdk-3 -lpangocairo-1.0 -lpango-1.0 -lharfbuzz
    -latk-1.0 -lcairo-gobject -lcairo -lgdk_pixbuf-2.0 -lgio-2.0 -lgobject-2.0 -lglib-2.0
    )

# make install
install(TARGETS ${PROJECT} DESTINATION ${BIN_DIR})

# Notes: 

# gcc -c -I. -Ilibnml/linklist -Iemc -Ilibnml/cms -Ilibnml/rcs -Ilibnml/inifile
# -Ilibnml/os_intf -Ilibnml/nml -Ilibnml/buffer -Ilibnml/posemath -Irtapi -Ihal -Iemc
# -Iemc/nml_intf -Iemc/kinematics -Iemc/tp -Iemc/motion -Iemc/ini -Iemc -Iemc/rs274ngc
# -Iemc/sai -Iemc/pythonplugin -Iemc/tooldata -Iemc -I/home/user/linuxcnc/src/include
#-I/usr/include/python3.9 -Os -fwrapv  -g -Wall -Wno-stringop-truncation -D_FORTIFY_SOURCE=2
# -DULAPI -std=gnu11 -Werror=implicit-function-declaration -g -O2  -pthread -I/usr/local/include/freetype2
# -I/usr/local/include -I/usr/include/gtk-2.0 -I/usr/lib/x86_64-linux-gnu/gtk-2.0/include
# -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/pango-1.0
# -I/usr/include/libmount -I/usr/include/blkid -I/usr/include/fribidi -I/usr/include/cairo
# -I/usr/include/pixman-1 -I/usr/include/harfbuzz -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include
# -I/usr/include/uuid -I/usr/include/libpng16 -DGTK_INTERFACE -DGTK2 -Wno-deprecated-declarations
# -DSEQUENTIAL_SUPPORT -DHAL_SUPPORT -DDYNAMIC_PLCSIZE -DRT_SUPPORT -DOLD_TIMERS_MONOS_SUPPORT -DMODBUS_IO_MASTER \
# -MP -MD -MF 




