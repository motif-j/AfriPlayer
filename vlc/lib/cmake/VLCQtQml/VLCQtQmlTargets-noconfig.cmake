#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "VLCQt::Qml" for configuration ""
set_property(TARGET VLCQt::Qml APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(VLCQt::Qml PROPERTIES
  IMPORTED_IMPLIB_NOCONFIG "${_IMPORT_PREFIX}/lib/libVLCQtQml.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_NOCONFIG "Qt5::Quick;VLCQt::Core"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/bin/libVLCQtQml.dll"
  )

list(APPEND _cmake_import_check_targets VLCQt::Qml )
list(APPEND _cmake_import_check_files_for_VLCQt::Qml "${_IMPORT_PREFIX}/lib/libVLCQtQml.dll.a" "${_IMPORT_PREFIX}/bin/libVLCQtQml.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
