# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Projet_Baba_Is_You_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Projet_Baba_Is_You_autogen.dir/ParseCache.txt"
  "Projet_Baba_Is_You_autogen"
  )
endif()
