cmake_minimum_required(VERSION 3.2)

set(OUTPUT_ELF "app")
set(EX_LIB "exlib")

add_library(${EX_LIB} ex1.c)
add_executable(${OUTPUT_ELF} app.c)

add_compile_options(-g -Wall)

include_directories(${CMAKE_SOURCE_DIR})

link_directories(${CMAKE_SOURCE_DIR}/build/lib)
target_link_libraries(${OUTPUT_ELF} PUBLIC ${EX_LIB})
