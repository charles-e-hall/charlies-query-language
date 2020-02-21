export PATH := $(HOME)/bin:$(PATH)

build:
	g++ -std=c++11 -Wall -Werror cql.cpp -o cql
#	mkdir ~/bin
	mv ./cql ~/bin/cql
	chmod +x ~/bin/cql
