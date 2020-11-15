all:solve transform generate
	g++ -O3 transform.cpp -o  transform
	g++ -O3  generate.cpp -o  generate
	g++ -O3  solve.cpp -o  solve
