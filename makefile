EXPRESSION_TREE_EXE = bin/ExpressionTreeTest
CC = g++
OPTIONS = -std=c++11
DEBUG = -g
MEMCHECK = valgrind --tool=memcheck --leak-check=yes --show-reachable=yes

all:$(EXPRESSION_TREE_EXE)
.PHONY: all run test_expression_tree memcheck_expression_tree directories clean

run:$(EXPRESSION_TREE_EXE)
	@echo "Press enter to run ExpressionTreeTest"
	@read DUMMY
	$(EXPRESSION_TREE_EXE)
	@echo "Press enter to memcheck ExpressionTreeTest"
	@read DUMMY
	$(MEMCHECK) $(EXPRESSION_TREE_EXE)

test_expression_tree: $(EXPRESSION_TREE_EXE)
	$(EXPRESSION_TREE_EXE)

memcheck_expression_tree: $(EXPRESSION_TREE_EXE)
	$(MEMCHECK) $(EXPRESSION_TREE_EXE)

directories:
	mkdir -p obj
	mkdir -p bin

clean: directories
	rm bin/*
	rm obj/*

$(EXPRESSION_TREE_EXE):obj/ExpressionTreeTest.o obj/ExpressionTree.o
	$(CC) $(OPTIONS) $(DEBUG) -o $(EXPRESSION_TREE_EXE) obj/ExpressionTreeTest.o obj/ExpressionTree.o
	
obj/ExpressionTreeTest.o:directories src/ExpressionTreeTest.cpp inc/ExpressionTree.h
	$(CC) $(OPTIONS) $(DEBUG) -o obj/ExpressionTreeTest.o -c  -I inc/ src/ExpressionTreeTest.cpp

obj/ExpressionTree.o:directories src/ExpressionTree.cpp inc/ExpressionTree.h
	$(CC) $(OPTIONS) $(DEBUG) -o obj/ExpressionTree.o -c  -I inc/ src/ExpressionTree.cpp
