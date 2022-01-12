cmake_minimum_required(VERSION 3.20)
project(Assignment_4_w0270109)

set(CMAKE_CXX_STANDARD 17)

if (EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist, you have to run conan install.")
endif()

add_executable(Assignment_4_w0270109 main.cpp Organism.cpp Human.cpp City.cpp Space.cpp Space.h Position.cpp Position.h DirectionOffset.cpp DirectionOffset.h NoPositionAvailableException.cpp NoPositionAvailableException.h Zombie.cpp Zombie.h GameSpecification.cpp GameSpecification.h)