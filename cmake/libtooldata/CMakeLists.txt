cmake_minimum_required(VERSION 3.0)
set(PROJECT "libtooldata") 
project(${PROJECT} VERSION 0 LANGUAGES CXX)

# Set variables.
set(SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")

# Set includepaths.
include_directories(${SRC_DIR})
include_directories(${SRC_DIR}/../rtapi_src)
include_directories(${SRC_DIR}/../emc_src)
include_directories(${SRC_DIR}/../libnml_src)
include_directories(${SRC_DIR}/../libtooldata_src)

# Set prefix.
set(CMAKE_SHARED_LIBRARY_PREFIX "")

ADD_LIBRARY(${PROJECT} SHARED 
    ${SRC_DIR}/../libtooldata_src/tooldata_mmap.cc
    ${SRC_DIR}/../libtooldata_src/tooldata_common.cc
    ${SRC_DIR}/../libtooldata_src/tooldata_db.cc
)

add_definitions(-DULAPI)

# Add verion nr. .so.0.0.0
set_target_properties(${PROJECT_NAME} PROPERTIES VERSION ${PROJECT_VERSION})

# Set include paths for libraries to link.
target_include_directories(${PROJECT_NAME} PRIVATE ${BUILD_DIR})

# Link to libraries.
target_link_libraries(${PROJECT_NAME} PRIVATE)

# Set custom output name :
# set_property(TARGET  ${PROJECT} PROPERTY OUTPUT_NAME thename)

# Make install
install(TARGETS ${PROJECT} DESTINATION ${BUILD_DIR}/../../../lib)
