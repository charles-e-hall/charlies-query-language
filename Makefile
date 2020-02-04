export PATH := $(HOME)/bin:$(PATH)

build:
	gcc cql.cpp -o cql -lstdc++
#	mkdir /Users/Charlie/bin
	mv ./cql /Users/Charlie/bin/cql
	chmod +x /Users/Charlie/bin/cql
