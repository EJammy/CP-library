# cpp='g++ -std=c++17 -Wshadow -Wall -DLOCAL -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -g'
cpp='g++ -std=c++17 -Wshadow -Wall -DLOCAL -O3'

$cpp A.cpp
$cpp gen.cpp -o gen.out
$cpp brute.cpp -o brute.out

for ((i = 0; i < 1000; i++)); do
    echo $i
    ./gen.out $i > in
    diff <(./a.out <in) <(./brute.out <in) || break;
done;