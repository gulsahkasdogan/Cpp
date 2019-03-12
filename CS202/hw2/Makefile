hw2: output
output: main.o PbBST.o PbBSTNode.o analysis.o
	g++ main.o PbBST.o PbBSTNode.o analysis.o -o output

main.o: main.cpp
	g++ -c main.cpp

PbBST.o: PbBST.cpp
	g++ -c PbBST.cpp

PbBSTNode.o: PbBSTNode.cpp
	g++ -c PbBSTNode.cpp

analysis.o: analysis.cpp
	g++ -c analysis.cpp

clean: clean-custom
	rm* output			

