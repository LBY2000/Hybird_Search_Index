# Hybird_Search_Index
This is a temp repository for my thesis's design and I will keep updating <br>
And thanks for [armon's help](https://github.com/armon/libart)(In adaptive radix tree part) <br>
<br>
At the current stage:<br>
- Try CCEH on a single thread.
- Try ARTree on a single thread.
# Usage
- To run Extendible Hash you can:
```
$ cd CCEH_DRAM
$ g++ -fPIC -shared -o libexhash.so Extendible_Hash.cpp
$ sudo cp libexhash.so /usr/lib
$ g++ -o test test.cpp -lexhash
```
- To run ARTree you can:
```
$ cd ARTree
$ g++ -fPIC -shared -o libartree.so art.cpp
$ sudo cp libartree.so /usr/lib
$ g++ -o test2 test2.cpp -lartree
```
And if you find the test2 fail to run and you can try:
```
$ git clone https://github.com/armon/libart.git
$ cd deps/check-0.9.8/
$ ./configure
$ make
$ make install 
$ ldconfig (necessary on some Linux distros)
$ cd ../../
$ sudo apt install scons
$ scons
```
And retry.
armos's explanation: Building the test code will generate errors if libcheck is not available
