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

# 2. Configurar GTK+ 3.0 (Necesario para los diálogos nativos en Linux)
find_package(PkgConfig REQUIRED)
# --- Configuración de Native File Dialog Extended (NFDe) ---
include(FetchContent)
FetchContent_Declare(
  nfd
  GIT_REPOSITORY https://github.com/btzy/nativefiledialog-extended.git
  GIT_TAG        master # O una versión específica como v1.2.1
)
FetchContent_MakeAvailable(nfd)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

# 3. Definir las rutas de las carpetas de ImGui
# Ajusta estos nombres si tus carpetas se llaman distinto (ej: "lib/imgui")
set(IMGUI_DIR "${CMAKE_CURRENT_SOURCE_DIR}/imgui")
set(IMGUI_SFML_DIR "${CMAKE_CURRENT_SOURCE_DIR}/imgui-sfml")

# 4. Incluir los directorios de cabeceras
include_directories(
    ${SFML_INCLUDE_DIR}
    ${IMGUI_DIR}
    ${IMGUI_SFML_DIR}
    ${GTK3_INCLUDE_DIRS}
    "src/" # Para que encuentre tus .cpp más fácil
)

# 5. Lista de archivos de ImGui que se deben compilar
set(IMGUI_SOURCES
    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/imgui_demo.cpp       # Opcional pero útil para aprender
    ${IMGUI_SFML_DIR}/imgui-SFML.cpp
)

# 6. Crear el ejecutable incluyendo los archivos de ImGui
add_executable(2DSMDM 
    main.cpp 
    src/layer/layer.cpp
    src/topMenu/topMenu.cpp
    src/button/button.cpp
    ${IMGUI_SOURCES}
)

# 7. Enlazar todas las librerías
target_link_libraries(2DSMDM
    sfml-graphics 
    sfml-window 
    sfml-system 
    GL 
    nfd
    wayland-client # Opcional, pero bueno tenerlo si escalas la app
)