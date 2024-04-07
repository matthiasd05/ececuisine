cmake_minimum_required(VERSION 3.26)
project(ececook C)

set(CMAKE_C_STANDARD 99)

add_executable(ececook main.c
        MENU.c
        MENU.h
        BUFFER.c
        BUFFER.h
        Level.c
        Level.h
        Joeurs.c
        Joeurs.h
)

target_link_libraries(ececook -lmingw32 -lalleg44)