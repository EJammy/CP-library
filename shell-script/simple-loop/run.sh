
for ((n = 4; n < 5; n++)); do
	for ((i = 100; i <500; i++)); do
		echo "$n $i" | ./a.out > out$i
		# echo $n $i
		./check $n $i < out$i || echo "Failed test: $n $i";
	done;
	echo "$n $i"
done;
echo "$n $i"


# n=100;
# i=100;
# echo "$n $i" | ./a.out > out$i
# time ./check $n $i < out$i || echo "Failed test: $n $i";
# 
# n=200;
# i=200;
# echo "$n $i" | ./a.out > out$i
# time ./check $n $i < out$i || echo "Failed test: $n $i";
# 
# n=300;
# i=300;
# echo "$n $i" | ./a.out > out$i
# time ./check $n $i < out$i || echo "Failed test: $n $i";
# 
# n=1000;
# i=1000;
# echo "$n $i" | ./a.out > out$i
# time ./check $n $i < out$i || echo "Failed test: $n $i";
# 
