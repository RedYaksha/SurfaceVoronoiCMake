cmake_minimum_required(VERSION 3.24)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin/libs)

set( SOURCE_FILES 
        Chen_Han.cpp
        Dijkstra.cpp
        DistanceApproach.cpp
        ExactDGPMethod.cpp
        FMM.cpp
        ICH_WindowFiltering.cpp
        IntrinsicSDF.cpp
        Xin_Wang.cpp
    )

set( TARGET_NAME Geodesic)

add_library(${TARGET_NAME} ${SOURCE_FILES})

find_package(CGAL REQUIRED)

target_include_directories(${TARGET_NAME} PRIVATE 
                                ${PROJECT_SOURCE_DIR}/eigen
                                ${CGAL_DIR}/auxiliary/gmp/include
                                ${CGAL_DIR}/include
                                ${BOOST_DIR}
                        )

target_link_libraries(${TARGET_NAME} PRIVATE 
                ${CGAL_DIR}/auxiliary/gmp/lib/libgmp-10.lib
                ${CGAL_DIR}/auxiliary/gmp/lib/libmpfr-4.lib
            )