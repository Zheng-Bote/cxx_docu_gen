# CMakeLists.txt
cmake_minimum_required(VERSION 3.28)
project(cxx_docu_gen
    VERSION 1.1.0
    DESCRIPTION "C++23 Documentation Generator"
    HOMEPAGE_URL "https://github.com/Zheng-Bote/cxx_docu_gen"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Source and Header files
set(SOURCES
    src/main.cpp
    src/parser_util.cpp
    src/markdown_generator_util.cpp
)

set(HEADERS
    include/doc_model_type.hpp
    include/parser_util.hpp
    include/markdown_generator_util.hpp
)

add_executable(cxx_docu_gen ${SOURCES} ${HEADERS})

target_include_directories(cxx_docu_gen PRIVATE include)

# --- Static Linking Configuration ---
if(MSVC)
    # Static runtime linking (/MT) for MSVC
    set_property(TARGET cxx_docu_gen PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
    target_compile_options(cxx_docu_gen PRIVATE /std:c++latest /W4)
else()
    # Static linking of standard libraries for GCC/Clang
    target_link_options(cxx_docu_gen PRIVATE -static-libstdc++ -static-libgcc)
    target_compile_options(cxx_docu_gen PRIVATE -std=c++23 -Wall -Wextra -Wpedantic -Wshadow -Wconversion)
endif()

# --- Install Option ---
include(GNUInstallDirs)
install(TARGETS cxx_docu_gen
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

file(GENERATE OUTPUT "${CMAKE_BINARY_DIR}/libs.txt" 
     CONTENT "$<TARGET_PROPERTY:${PROJECT_NAME},LINK_LIBRARIES>")
