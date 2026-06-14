#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "so101_hardware::so101_hardware" for configuration ""
set_property(TARGET so101_hardware::so101_hardware APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(so101_hardware::so101_hardware PROPERTIES
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/lib/libso101_hardware.so"
  IMPORTED_SONAME_NOCONFIG "libso101_hardware.so"
  )

list(APPEND _cmake_import_check_targets so101_hardware::so101_hardware )
list(APPEND _cmake_import_check_files_for_so101_hardware::so101_hardware "${_IMPORT_PREFIX}/lib/libso101_hardware.so" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
