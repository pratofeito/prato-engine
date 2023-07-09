cmake_minimum_required(VERSION 3.21)
project(prato-engine LANGUAGES CXX)

option(BUILD_SHARED_LIBS "Build shared libraries (.dll/.so) instead of static ones (.lib/.a)" OFF)

include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

# Download SFML
FetchContent_Declare(
  SFML
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG 2.6.x
)
FetchContent_MakeAvailable(SFML)

# Add the source files
file(GLOB_RECURSE SRC_FILES_PROJECT "${PROJECT_SOURCE_DIR}/src/*.cpp")

# Add the include directories
include_directories("${PROJECT_SOURCE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("${PROJECT_SOURCE_DIR}/include/prato-engine")

# Add the executable (demo) target
add_executable(prato-demo ${SRC_FILES_ENGINE} ${SRC_FILES_PROJECT})

# Add the library target
add_library(prato-engine ${SRC_FILES_ENGINE} ${SRC_FILES_PROJECT})

# Link SFML to the targets
set(LIBS sfml-audio sfml-graphics sfml-window sfml-system)

target_link_libraries(prato-engine PRIVATE ${LIBS})
target_link_libraries(prato-demo PRIVATE ${LIBS})

target_compile_features(prato-engine PRIVATE cxx_std_17)

# Copy shared libraries on Windows
if (WIN32 AND BUILD_SHARED_LIBS)
    add_custom_command(TARGET prato-engine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_RUNTIME_DLLS:prato-engine> $<TARGET_FILE_DIR:prato-engine> COMMAND_EXPAND_LISTS)
endif()

# Install the target
install(TARGETS prato-engine)

