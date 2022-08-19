#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "VLCQt::Core" for configuration ""
set_property(TARGET VLCQt::Core APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(VLCQt::Core PROPERTIES
  IMPORTED_IMPLIB_NOCONFIG "${_IMPORT_PREFIX}/lib/libVLCQtCore.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_NOCONFIG "Qt5::Core"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/bin/libVLCQtCore.dll"
  )

list(APPEND _cmake_import_check_targets VLCQt::Core )
list(APPEND _cmake_import_check_files_for_VLCQt::Core "${_IMPORT_PREFIX}/lib/libVLCQtCore.dll.a" "${_IMPORT_PREFIX}/bin/libVLCQtCore.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
