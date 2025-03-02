cmake_minimum_required(VERSION 3.10)

# Set the project name
project(InvSqrt)

# Set some compilation flags (warning levels, optimization ...)
if(MSVC)
    add_compile_options("/W4" "$<$<CONFIG:RELEASE>:/O2>")
else()
    add_compile_options("-Wall" "-Wextra" "-Werror" "$<$<CONFIG:RELEASE>:-O3>")
endif()

# Add the MathFunctions library
add_subdirectory(MathFunctions)

# Add the executable
add_executable(InvSqrt invsqrt.cpp)

# Link the MathFunctions library to the executable
target_link_libraries(InvSqrt PUBLIC MathFunctions)

# Make the exectuable the startup project (applies to Visual Studio)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${PROJECT_NAME})

# List included directories
target_include_directories(InvSqrt PUBLIC
                          "${PROJECT_SOURCE_DIR}/MathFunctions"
                          )