cmake_minimum_required(VERSION 3.20)
project(nexoeditor)

set(CMAKE_C_STANDARD 99)
if(LINUX OR ANDROID)
    add_link_options(-fsanitize=address)
		add_compile_options(-fsanitize=address -Wall -Wpedantic -Wcast-align -Wcast-qual -Wdisabled-optimization -Wformat=2 -Winit-self -Wmissing-declarations -Wmissing-include-dirs -Wredundant-decls -Wshadow -Wsign-conversion -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror)
endif()

include_directories("include")

file(GLOB_RECURSE CORE_SOURCES CONFIGURE_DEPENDS "src/core/*.c")
add_library(nexocore STATIC ${CORE_SOURCES})

add_executable(nexo "src/nexo/main.c")
target_link_libraries(nexo nexocore ncursesw)

file(GLOB_RECURSE TESTS_SOURCES CONFIGURE_DEPENDS "src/tests/*.c")
add_executable(nexotest ${TESTS_SOURCES})
target_link_libraries(nexotest nexocore ncursesw)
