#----------------------------------------------------------------
# Generated CMake target import file.
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "VLCQt::Widgets" for configuration ""
set_property(TARGET VLCQt::Widgets APPEND PROPERTY IMPORTED_CONFIGURATIONS NOCONFIG)
set_target_properties(VLCQt::Widgets PROPERTIES
  IMPORTED_IMPLIB_NOCONFIG "${_IMPORT_PREFIX}/lib/libVLCQtWidgets.dll.a"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_NOCONFIG "VLCQt::Core;Qt5::Widgets"
  IMPORTED_LOCATION_NOCONFIG "${_IMPORT_PREFIX}/bin/libVLCQtWidgets.dll"
  )

list(APPEND _cmake_import_check_targets VLCQt::Widgets )
list(APPEND _cmake_import_check_files_for_VLCQt::Widgets "${_IMPORT_PREFIX}/lib/libVLCQtWidgets.dll.a" "${_IMPORT_PREFIX}/bin/libVLCQtWidgets.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
