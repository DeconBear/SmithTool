# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\SmithTool_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\SmithTool_autogen.dir\\ParseCache.txt"
  "SmithTool_autogen"
  )
endif()
