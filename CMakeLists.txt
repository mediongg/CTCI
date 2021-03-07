cmake_minimum_required(VERSION 3.10)

# set the project name
project(CTCI)


set(CMAKE_CXX_COMPILER "g++-10")
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH
	${CMAKE_MODULE_PATH}
	${PROJECT_SOURCE_DIR}/ch1
)

set(CH1 /ch1)
include(CH1)
