# Compiler
CC = g++

# Flags 
CC_FLAGS = -std=c++11 -Wall -g -Iinclude -c

all: main

main: main.o review.o timer.o menu.o redblacktree.o btree.o btreenode.o menutrees.o
		$(CC) -o bin/main.exe obj/main.o obj/Review.o obj/Timer.o obj/Menu.o obj/RedBlackTree.o obj/BTree.o obj/BTreeNode.o obj/MenuTrees.o

main.o: main.cpp
		$(CC) $(CC_FLAGS) main.cpp -o obj/main.o

review.o: src/Review.cpp include/Review.h
		$(CC) $(CC_FLAGS) src/Review.cpp -o obj/Review.o

timer.o: src/Timer.cpp include/Timer.h
		$(CC) $(CC_FLAGS) ./src/Timer.cpp -o obj/Timer.o

menu.o: src/Menu.cpp include/Menu.h
		$(CC) $(CC_FLAGS) ./src/Menu.cpp -o obj/Menu.o

reedblacktree.o: src/RBTree.cpp include/RBTree.h
		$(CC) $(CC_FLAGS) ./src/RedBlackTree.cpp -o obj/RedBlackTree.o

btree.o: src/Btree.cpp include/BTree.h
		$(CC) $(CC_FLAGS) ./src/BTree.cpp -o obj/BTree.o

btreenode.o: src/BTreeNode.cpp include/BTreeNode.h
		$(CC) $(CC_FLAGS) ./src/BTreeNode.cpp -o obj/BTreeNode.o		

menutrees.o: src/MenuTrees.cpp include/MenuTrees.h
		$(CC) $(CC_FLAGS) ./src/MenuTrees.cpp -o obj/MenuTrees.o


execute: all
		./bin/main.exe