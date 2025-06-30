# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\cyberpunk-red-character-sheet-managger_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\cyberpunk-red-character-sheet-managger_autogen.dir\\ParseCache.txt"
  "cyberpunk-red-character-sheet-managger_autogen"
  )
endif()
