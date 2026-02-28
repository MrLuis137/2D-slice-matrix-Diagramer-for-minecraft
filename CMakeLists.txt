cmake_minimum_required(VERSION 3.10)
project(2DSMDM)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Buscar el módulo de PkgConfig
find_package(PkgConfig REQUIRED)

# Buscar los módulos específicos de CSFML
# Esto define variables como CSFML_INCLUDE_DIRS y CSFML_LIBRARIES
pkg_check_modules(CSFML REQUIRED csfml-graphics csfml-window csfml-system)

# Indicar a CMake dónde están los encabezados (.h)
include_directories(usr/include/)


add_executable(2DSMDM main.cpp)

target_link_libraries(2DSMDM Pcsfml-graphics 
    csfml-window 
    csfml-system 
    csfml-audio)