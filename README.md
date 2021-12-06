### Building

To build this application use the following commands:
```
cmake -B build .
cmake --build build
```
The executable can then be found under `build/map_solver/map_solver`

The application can also be build with QT Creator but has to be imported as a cmake project.
It should also be possible to build the application with Microsoft Visual Studio but the `C++ CMake tools for Windows` will have to be installed.

To build the tests enable the `ENABLE_TESTING` option.

To build the documentation Doxygen has to be installed. The the following commands can be used:
```
cmake -B build -DENABLE_DOXYGEN=ON .
cmake --build build --target doxygen-docs
```

### Algorithem
To calculate the islands on a map the tiles of the map are tokenized. The tokens contain the position as well as the type of the terain on the tile. Water tiles are discarded as they do not provide information for the algorithem.

After tokenizing the tiles the algorithem loops over them. If there is no existing island a new one with the current tile is generated (There are no water tiles as they were discarded beforehand). If one or multiple islands already exist it is tested for each of them if adding the tile is successfull.
 1. If the tile cannot be added to an existing island a new island with the tile is generated.
 2. If the tile can be added to exactly one island the loop continues.
 3. If the island can be added to multiple islands all islands the tile could be added to are merged into one and the other islands are removed.

After looping over all tiles all of them are part of an island and the islands can no longer be merged so resulting in the number of islands on the map.
