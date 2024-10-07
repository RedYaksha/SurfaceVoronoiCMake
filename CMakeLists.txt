cmake_minimum_required(VERSION 3.24)

project(SurfaceVoronoi)

set (CMAKE_CXX_STANDARD 20)

if(NOT DEFINED CGAL_DIR)
    message(FATAL_ERROR "You must specify the CGAL_DIR variable")
endif()

if(NOT DEFINED BOOST_DIR)
    message(FATAL_ERROR "You must specify the BOOST_DIR variable")
endif()

# needed?
# set (BOOST_INCLUDEDIR ${BOOST_DIR})
# set (BOOST_LIBRARYDIR ${BOOST_DIR}/lib64-msvc-14.2)

add_subdirectory(${PROJECT_SOURCE_DIR}/Model3D)
add_subdirectory(${PROJECT_SOURCE_DIR}/Geodesic)
add_subdirectory(${PROJECT_SOURCE_DIR}/GVD_RVD)

