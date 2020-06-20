cmake_minimum_required(VERSION 3.0.0)

aux_source_directory(. DIR_SRC)


add_executable(main ${DIR_SRC})
add_library(src STATIC ${DIR_SRC})
