cmake_minimum_required(VERSION 3.10)
project(KSPA_core)

# Add source files for kspa_core (replace with actual .cpp files)
add_library(KSPA_core
    logging.cpp
)

# Make the 'include' directory within kspa_core public
target_include_directories(KSPA_core
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include # Assuming you have include files in src/kspa_core/include
)
