pushd build
cmake -G "Visual Studio 14 2015" ../src
cmake --build . --target %2
popd