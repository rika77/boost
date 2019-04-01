# Usage

1. Compile with boost library, pouring output into out.txt
```
$ g++ -I $HOME/boost_1_66_0 -Wall main.cpp > out.txt
```


2. Plot a convex_hull
```
$ python plot.py < out.txt
```