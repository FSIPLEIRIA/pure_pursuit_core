# Check if this file has already been included.
if(NOT TARGET pure_pursuit_core)
    # Define the target.
    add_library(pure_pursuit_core SHARED IMPORTED)
    set_target_properties(pure_pursuit_core PROPERTIES IMPORTED_LOCATION /usr/lib/path_tracker/libpure_pursuit_core.so)

    find_package(lart_common REQUIRED)

    target_include_directories(pure_pursuit_core INTERFACE /usr/include/path_tracker)
    target_link_libraries(pure_pursuit_core INTERFACE lart_common)
endif()