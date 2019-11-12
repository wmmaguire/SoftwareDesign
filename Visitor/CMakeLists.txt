cmake_minimum_required(VERSION 3.8) # Or whatever version you use

# THIS HAS TO COME BEFORE THE PROJECT LINE
#set(CMAKE_C_COMPILER "gcc")
set(CMAKE_CXX_COMPILER "g++")
# THIS HAS TO COME BEFORE THE PROJECT LINE

project(Transporter)

# path of project headers
include_directories(include)

#add_library(Boat src/Package.cpp include/Package/Boat.h)
#add_library(Animal src/Vehicle.cpp include/Vehicle/Animal.h)

# adding the source files explicitly
set(SOURCES src/main.cpp)

# adding the source files (generically)
#file(GLOB SOURCES "src/*.cpp")

# set executable and link libs
add_executable(main.exe ${SOURCES})
#target_link_libraries(main.exe Animal Boat)
