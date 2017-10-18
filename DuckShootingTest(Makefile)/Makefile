#
# Filename:    Makefile-DuckShootingTest
# Author:      Önder Görmez
# Dated:       Oct 15, 2017
# Decription:  Makefile for the DuckShootingTest
#

ROOT  = ../

# Directories
MAIN_DIR        := $(ROOT)
INCLUDES_DIR    := $(ROOT)
UTILITY_INC_DIR := $(ROOT)Utility/inc/
UTILITY_SRC_DIR := $(ROOT)Utility/src/
# LIBS_DIR       :=
BIN_DIR         := Binaries

CPP      := g++
CC       := gcc
AR       := ar
RM       := rm -f

CPPFLAGS := -std=c++11 -I$(INCLUDES_DIR) -I$(UTILITY_INC_DIR) -w
    
SRCS_CPP =  $(ROOT)main.cc \
        $(UTILITY_SRC_DIR)Utility.cc \
        $(UTILITY_SRC_DIR)prng_uniform.cc \
        $(ROOT)DuckShootingTest.cc

main:
	$(CPP) $(SRCS_CPP) -o main.elf $(CPPFLAGS)