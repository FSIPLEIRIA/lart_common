# Check if this file has already been included.
if(NOT TARGET lart_common)
    # Define the target.
    add_library(lart_common SHARED IMPORTED)
    set_target_properties(lart_common PROPERTIES IMPORTED_LOCATION /usr/lib/lart_common/liblart_common.so)

    # Set the dependencies.
    find_package(CGAL REQUIRED)

    target_include_directories(lart_common INTERFACE /usr/include/lart_common)
    target_link_libraries(lart_common INTERFACE ${CGAL_LIBRARIES})
endif()