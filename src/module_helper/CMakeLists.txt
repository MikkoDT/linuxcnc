# **************************************************************************
cmake_minimum_required(VERSION 3.0)
# Component name.
set(PROJECT "module_helper") # The name of the file excluding .c or .h
project(${PROJECT} CXX C)

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")
set(EMC_DIR "${SRC_DIR}/../emc")
set(BIN_DIR "${SRC_DIR}/../../bin")
set(HAL_DIR "${SRC_DIR}/../hal")
set(NML_DIR "${SRC_DIR}/../nml")
set(CONFIG_DIR "${SRC_DIR}/../")

include_directories(${SRC_DIR})
include_directories(${EMC_DIR})
include_directories(${BIN_DIR})
include_directories(${HAL_DIR})
include_directories(${NML_DIR})
include_directories(${CONFIG_DIR})

# add_definitions()
set(SOURCES
    ${SRC_DIR}/module_helper.c
    )
add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} PRIVATE -Wall -Werror)

# make install
install(TARGETS ${PROJECT} DESTINATION ${BIN_DIR})
