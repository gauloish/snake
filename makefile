# Compiler
COMPILER = g++

# Compiler Flags
FLAGS = -Wall -Werror -g

# Main Code
TARGET = main

$(TARGET):
	$(COMPILER) $(FLAGS) source/$(TARGET).cpp -o program/snake
