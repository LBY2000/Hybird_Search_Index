# Hybird_Search_Index
This is a temp repository for my thesis's design and I will keep updating <br>
And thanks for help.
<br>
At the current stage:<br>
- Try CCEH on a single thread.
- Try ARTree on a single thread.
# Usage
- To run Extendible Hash you can:
```
$ cd My_CCEH_DRAM
$ g++ -fPIC -shared -o libexhash.so Extendible_Hash.cpp
$ sudo cp libexhash.so /usr/lib
$ g++ -o test test.cpp -lexhash
```
- To run ARTree you can:
```
$ cd ARTree
$ g++ -fPIC -shared -o libartree.so art.cpp
$ sudo cp libartree.so /usr/lib
$  g++ -o input input.cpp
$ ./input 1000000
$ g++ -o test2 test2.cpp -lartree
$ ./test2 ./data 20
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
<br><br>
- Now I fixed several problems in CCEH-PMDK(https://github.com/DICL/CCEH),here I upload CCEH-DRAM
```
cd CCEH_DRAM
mkdir bin
make
cd bin
./single_threaded_cceh 200000
./multi_threaded_cceh 200000 10
```
- Then I upload CCEH-PMDK(fixed), the original version(https://github.com/DICL/CCEH),but now it's write latency is very high and I still can't figure out why it suffers such high write latency
```
cd CCEH_PMDK
mkdir bin
make
cd bin
./single_threaded_cceh /mnt/pmem0/c1 200000
./multi_threaded_cceh /mnt/pmem0/c2 200000 10
```
