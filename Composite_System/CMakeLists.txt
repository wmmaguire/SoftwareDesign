cmake_minimum_required(VERSION 3.8)
# project name
project(Core_System)

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU" OR
		"${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	set(warnings "-Wall -Wextra -Werror")
endif()
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)
# find additional packages
#find_package(Libssh2 REQUIRED CONFIG)
# path to project header
include_directories(include /usr/local/include)

add_library(System SHARED src/System.cpp include/System.h)
add_library(Device SHARED src/Device.cpp include/Device.h)
#add_library(System SHARED include/Component.h)

# define source files
# explicit
set(SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/src/test.cpp
)
# implicit - global
#file(GLOB SOURCES "src/*.cpp")



add_executable(test_mod ${SOURCES})

target_link_libraries( test_mod System Device)
