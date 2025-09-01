cmake_minimum_required(VERSION 3.16)

# Projekt
project(todo
    VERSION 1.0.0
    DESCRIPTION "Calculator with operation memory"
    LANGUAGES CXX
)

# C++ Standards
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Build type jeśli nie podano
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

# Flagi kompilacji dla GCC/Clang (typowe na Arch)
set(CMAKE_CXX_FLAGS_DEBUG "-g -Wall -Wextra -Wpedantic -fsanitize=address")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

# Include directories
include_directories(include)

# Źródła
set(SOURCES
    src/main.cpp
    src/task.cpp
    src/taskmanager.cpp
)

# Executable
add_executable(${PROJECT_NAME} ${SOURCES})

# Właściwości target
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# Compile features
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_17)

# Opcjonalne: linkowanie z pthread jeśli będziesz używać threading
# target_link_libraries(${PROJECT_NAME} PRIVATE pthread)

# Install rules
install(TARGETS ${PROJECT_NAME}
    RUNTIME DESTINATION bin
)

# Skopiuj folder data do build directory
file(COPY data DESTINATION ${CMAKE_BINARY_DIR})

# Debug info
message(STATUS "Build type: ${CMAKE_BUILD_TYPE}")
message(STATUS "Compiler: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
