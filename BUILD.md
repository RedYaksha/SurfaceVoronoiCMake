# Building SurfaceVoronoi (Windows)

### Update submodules
Eigen, one of the needed dependencies, is added as a submodule. Run the following the retrieve it:
```
git submodule update --init
```

### Download Dependencies
Download CGAL Library and GMP/MPFR libraries from their release page (https://github.com/CGAL/cgal/releases/tag/v6.0)

Download Boost 1.72 (or any compatible Boost w/ the downloaded CGAL)
https://sourceforge.net/projects/boost/files/boost-binaries/1.72.0/

Set the following environment variables (CGAL must be able to find Boost):
```
BOOST_INCLUDEDIR=<path_to_boost>
BOOST_LIBRARYDIR=<path_to_boost\lib64-msvc-14.2>
```

Keep note of the directories to where CGAL and Boost were installed to.

### Run CMake
Run the following from the SurfaceVoronoi source directory:

```
mkdir build
cd build
cmake .. -DBOOST_DIR=<Path to Boost> -DCGAL_DIR=<Path to CGAL>
cmake --build .
```

Optionally you may build the Release configuration by 
```
cmake --build . --config Release
```

You may now run the generated rvd.exe in build/bin/$\<CONFIG\>. (When running, the current working directory must be where the .exe is located)

### Build Notes
- Building GMP and MPFR from source is apparently possible for Windows but I could not get it to work. (Need Cygwin)