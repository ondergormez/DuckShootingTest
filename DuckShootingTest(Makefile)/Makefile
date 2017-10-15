#
# Filename:    Makefile-DuckShootingTest
# Author:      Önder Görmez
# Dated:       Oct 15, 2017
# Decription:  Makefile for the DuckShootingTest
#

ROOT  := ~\

# Directories
MAIN_DIR       	:= $(ROOT)
INCLUDES_DIR   	:= $(ROOT)
UTILITY_INC_DIR	:= $(ROOT)/Utility/inc
UTILITY_SRC_DIR	:= $(ROOT)/Utility/src
# LIBS_DIR       :=
BIN_DIR        	:= Binaries

CPP      := g++
CC       := gcc
AR       := ar
RM       := rm -f

# CFLAGS   := -Wno-deprecated -Wno-write-strings -Ofast -ansi -I$(INCLUDES_DIR) -I$(UTILITY_INC_DIR)
CPPFLAGS := -g -D __RELEASE__ -Wno-deprecated -Wno-write-strings -Ofast -ansi -fpermissive -I$(INCLUDES_DIR) -I$(UTILITY_INC_DIR)

#LIBS     := -L$(LIBS_DIR) -L$(LIBS_DIR)\acml -L$(LIBS_DIR)\fftw -L$(LIBS_DIR)\itpp -L$(LIBS_DIR)\ngspice -L$(LIBS_DIR)\opencv

echo_cmd = @printf   "   %-15s %s\n" "$(1)" "$(2)"

usage:
	@echo ""
	@echo "Makefile for the tool DuckShootingTest."
	@echo ""
	@echo "Usage:"
	@echo "	make all        # Compile everything"
	@echo "	make clean      # Remove all object files"
	@echo "	make clean_all  # Remove all object files and binary"
	@echo ""

#SRCS_C =	$(ROOT)\main.cc \
			
SRCS_CPP =	$(ROOT)\main.cc \
			$(ROOT)\DuckShootingTest.cc \
			$(UTILITY_SRC_DIR)\Utility.cc \
			$(UTILITY_SRC_DIR)\prng_uniform.cc

# all: $(SRCS_C) $(SRCS_CPP) DuckShootingTest.elf
# all: $(SRCS_CPP) DuckShootingTest.elf

all: main.cc DuckShootingTest.elf

# OBJS     := $(SRCS_C:.c=.o) $(SRCS_CPP:.cpp=.o)
OBJS     := $(SRCS_C:.c=.o) $(SRCS_CPP:.cpp=.o)

DuckShootingTest.elf: $(OBJS)
	@printf   "   LD              $(BIN_DIR)/$@\n"
	$(LD) $(LDFLAGS) $(OBJS) $(LIBS) -o $(BIN_DIR)/$@

.cpp.o:
	$(call echo_cmd,CPP    ,$@)
	$(CPP) $(CPPFLAGS) -c $< -o $@

.c.o:
	$(call echo_cmd,CC    ,$@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@printf   "   RM \n $(OBJS)\n"
	$(RM) $(OBJS)

clean_all:
	@printf   "   RM \n $(OBJS) $(BIN_DIR)/DuckShootingTest.elf\n"
	$(RM) $(OBJS) $(BIN_DIR)/DuckShootingTest.elf
