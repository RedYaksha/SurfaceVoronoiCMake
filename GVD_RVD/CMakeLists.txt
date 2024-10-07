cmake_minimum_required(VERSION 3.24)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(rvd Main.cpp)

find_package(CGAL REQUIRED)

target_include_directories(rvd PRIVATE 
                                ${PROJECT_SOURCE_DIR}/eigen
                                ${CGAL_DIR}/auxiliary/gmp/include
                                ${CGAL_DIR}/include
                                ${BOOST_DIR}
                        )

target_link_libraries(rvd PRIVATE
                Geodesic
                Model3D
                ${CGAL_DIR}/auxiliary/gmp/lib/libgmp-10.lib
                ${CGAL_DIR}/auxiliary/gmp/lib/libmpfr-4.lib
            )

add_dependencies(Model3D Geodesic)

# copy assets to where the final .exe will be
add_custom_command(TARGET rvd POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy ${CGAL_DIR}/auxiliary/gmp/lib/libmpfr-4.dll ${CMAKE_BINARY_DIR}/bin/$<CONFIG>/
        COMMAND ${CMAKE_COMMAND} -E copy ${PROJECT_SOURCE_DIR}/assets/bunny.obj ${CMAKE_BINARY_DIR}/bin/$<CONFIG>/
        )

#add_dependencies(rvd copy_assets_and_libs)

set_property(TARGET rvd PROPERTY VS_DEBUGGER_WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/bin/$<CONFIG>)