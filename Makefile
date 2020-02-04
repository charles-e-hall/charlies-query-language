export PATH := $(HOME)/bin:$(PATH)

build:
	gcc cql.cpp -o cql -lstdc++
#	mkdir ~/bin
	mv ./cql ~/bin/cql
	chmod +x ~/bin/cql
