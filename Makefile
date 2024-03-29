# This make file is based on the example found at:
# https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html
#
# 'make'        build executable file 'pid'
# 'make clean'  removes all .o and executable files


# define the C compiler to use
CC = gcc

# define any compile-time flags
CFLAGS = -Wall -g

# define any directories containing header files other than /usr/include
INCLUDES = -I.

# define any libraries to link into executable:
LIBS = -lm

# define the C source files
SRCS = $(wildcard *.c)

# define the C object files 
#
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
# For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
#
OBJS = $(SRCS:.c=.o)

# define the executable file 
MAIN = pid

# The following part of the makefile is generic; it can be used to 
# build any executable just by changing the definitions above

.PHONY: all clean

all: $(MAIN)
	@echo Compilation finished

$(MAIN): $(OBJS) 
	$(CC) $(CFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS) $(LIBS)

# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file) 
# (see the gnu make manual section about automatic variables)
.c.o:
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) *.o *~ $(MAIN)
