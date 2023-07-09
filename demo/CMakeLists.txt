# Add the source files
file(GLOB_RECURSE SRC_FILES_PROJECT "./src/*.cpp")

# Add the include directories
include_directories("${PROJECT_SOURCE_DIR}/include")
include_directories("./include/")

# Add the executable (demo) target
add_executable(prato-demo ${SRC_FILES_PROJECT})

# Link SFML to the targets
set(LIBS sfml-audio sfml-graphics sfml-window sfml-system prato-engine)

target_link_libraries(prato-demo PRIVATE ${LIBS})

target_compile_features(prato-engine PRIVATE cxx_std_17)
