hw3: output
output: main.o AVLTree.o AVLTreeNode.o analysis.o
	g++ main.o AVLTree.o AVLTreeNode.o analysis.o -o output

main.o: main.cpp
	g++ -c main.cpp

AVLTree.o: AVLTree.cpp
	g++ -c AVLTree.cpp

AVLTreeNode.o: AVLTreeNode.cpp
	g++ -c AVLTreeNode.cpp

analysis.o: analysis.cpp
	g++ -c analysis.cpp

clean: clean-custom
	rm* output			

