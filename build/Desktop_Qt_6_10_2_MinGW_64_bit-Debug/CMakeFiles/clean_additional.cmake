# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\appcalendar_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\appcalendar_autogen.dir\\ParseCache.txt"
  "appcalendar_autogen"
  )
endif()
