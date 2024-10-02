# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\c___autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\c___autogen.dir\\ParseCache.txt"
  "c___autogen"
  )
endif()
