test : main.cpp 
	g++ main.cpp -o main
run: main
	./main
clean:
	rm -rf *o main