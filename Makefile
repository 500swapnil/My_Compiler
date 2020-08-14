TARGET=mycomp
all=$(TARGET)
CC = g++
CFLAGS = -lfl `llvm-config-6.0 --cxxflags --cppflags mcjit native --ldflags --libs core` -ltinfo -lpthread -ldl 
FLAGS=-w -Wno-deprecated -g -std=c++11
all: $(TARGET)
$(TARGET): lex.yy.c parser.tab.c ast.cpp ast.h codegen.cpp
	$(CC) $(FLAGS) lex.yy.c parser.tab.c ast.cpp visitor.cpp codegen.cpp $(CFLAGS)
lex.yy.c: scanner.l
	flex scanner.l
parser.tab.c: parser.y
	bison -vd parser.y
clean:
	rm -f *.c parser.tab.h *.output llout a.out
veryclean:
	rm -f *.c parser.tab.h a.out XML_* *.output
