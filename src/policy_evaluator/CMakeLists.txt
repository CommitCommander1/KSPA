cmake_minimum_required(VERSION 3.10)
project(policy_evaluator)

# Add source files for policy_evaluator (replace with actual .cpp files)
add_library(policy_evaluator
    policy_evaluator.cpp
)

# Make the 'include' directory within policy_evaluator public
target_include_directories(policy_evaluator
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/../../include  # Assuming you have include files in src/policy_evaluator/include
)
