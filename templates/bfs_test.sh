python verify_bfs.py
clang++ bfs.cpp -std=c++14 -O2
./a.out < bfs_in > bfs_out
diff bfs_out bfs_ans