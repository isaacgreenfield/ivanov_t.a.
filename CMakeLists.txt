cmake_minimum_required(VERSION 3.31)
project(githubkasilove)

set(CMAKE_CXX_STANDARD 20)

set(PROJECT_HEADERS
        IntArray.h
        IntMatrix.h
)
set(PROJECT_SOURCES
        main.cpp
        IntArray.cpp
        IntMatrix.cpp
)

add_executable(githubkasilove ${PROJECT_SOURCES} ${PROJECT_HEADERS})
