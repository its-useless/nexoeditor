cmake_minimum_required(VERSION 3.20)
project(nexoeditor)

set(CMAKE_C_STANDARD 90)
if(LINUX)
    add_link_options(-fsanitize=address)
    add_compile_options(-fsanitize=address)
endif()

include_directories("include")

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/core/*.c")

add_library(nexocore STATIC ${SOURCES})

add_executable(nexo "src/nexo/main.c")
target_link_libraries(nexo nexocore ncurses)

add_executable(nexotest "src/tests/tests.c")
target_link_libraries(nexotest nexocore ncurses)