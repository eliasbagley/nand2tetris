assembler: assembler.cc parser.cc code.cc
	g++ -std=c++11 -Wall -o assembler assembler.cc parser.cc code.cc

parser_test: parser.cc parser_test.cc
	g++ -std=c++11 -Wall -o parser_test parser.cc parser_test.cc

code_test: code.cc code_test.cc
	g++ -std=c++11 -Wall -o code_test code.cc code_test.cc

clean:
	rm assembler
