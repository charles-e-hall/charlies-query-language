 * This program is a command line sql-like utility
 * The purpose of this is to be an exercise for learning
 * binary search trees and file io.
 * The name "CQL" comes from Charlie's (Structured) Query Language
 * Changing "SQL" to "CQL"
 * 
 * My goal with CQL is not to exactly mimic SQL.  I have a somewhat limited understanding
 * of how true SQL engines actually work under the hood, and there is frustratingly limited
 * information that can be found on this.  Furthermore, SQL is so mature that full blown SQL engines are far
 * too highly engineered to use as starting points for understanding rudiments.  It would be like
 * trying to understand the most basic elements of an OS by starting with Windows 10.
 * Therefore, I am using what I know about SQL as an end-user paired with what I am learning
 * about Trees and sorting algorithms to implement how I imagine a basic SQL could work (but probably doesn't)
 * I have believed for some time that I can't truly understand something until I can build it
 * from scratch, so that is what I am doing here.
 * This is purely a fun learning exercise for me to learn CS fundamentals (trees, traversal, etc) and C/C++.
 * 
 * Eventually I want to turn this into a full command line utility
 * Right now, if using the Makefile, the "make build" command will compile
 * the program, move the binary to the ~/bin folder, chmod it, and add the binary to the PATH
 * so you can use it at the command line.
 * What I need to add is string parsing inside my "while (true)" loop so that I can 
 * input commands to be executed.
