cmake_minimum_required(VERSION 3.10)
project(policy_parser)

# Add source files for policy_parser (replace with actual .cpp files)
add_library(policy_parser
    policy.cpp
)

# Make the 'include' directory within policy_parser public
target_include_directories(policy_parser
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include/policy_parser  # Assuming you have include files in src/policy_parser/include
)
