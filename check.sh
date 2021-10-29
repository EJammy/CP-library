alias cfast='g++ -std=c++17 -Wshadow -Wall -DLOCAL -O3'
csafe='g++ -std=c++17 -Wshadow -Wall -DLOCAL -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g'

$csafe segTree.cpp
$csafe gen.cpp

