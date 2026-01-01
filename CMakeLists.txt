cmake_minimum_required(VERSION 3.15)

project(sdrac_shared_types)

add_library(sdrac_shared_types INTERFACE
  src/sdrac_shared_types.cpp
  )

include_directories(sdrac_shared_types
  src
)

target_include_directories(sdrac_shared_types INTERFACE
  src
  )