# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appVaultTones01_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appVaultTones01_autogen.dir\\ParseCache.txt"
  "appVaultTones01_autogen"
  )
endif()
