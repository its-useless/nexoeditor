cmake_minimum_required(VERSION 3.20)
project(nexoeditor)

include_directories("include")

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "src/*.c")

add_executable(nexo ${SOURCES})
target_link_libraries(nexo ncurses)