cmake_minimum_required(VERSION 3.10)
project(src_module) # Or 'project(src)'

# Add subdirectories for libraries
add_subdirectory(KSPA_core) # Note: Corrected directory name to KSPA_core
add_subdirectory(policy_evaluator)
add_subdirectory(policy_parser)
inlude('D:/yaml-cpp/include')
# Create the main executable
add_executable(kspa-app main.cpp)
link_directories('D:/yaml-cpp/build/Debug')

# Link the executable with the libraries
target_link_libraries(kspa-app
    KSPA_core # Note: Target name should match project() in src/KSPA_core/CMakeLists.txt
    policy_evaluator # Target name should match project() in src/policy_evaluator/CMakeLists.txt
    policy_parser # Target name should match project() in src/policy_parser/CMakeLists.txt
    yaml-cppd
)

# Include directories for the executable - primarily the project-level include dir
target_include_directories(kspa-app
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/../include # Project-level include directory
)
