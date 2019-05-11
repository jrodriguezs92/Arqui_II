# /**
#  * Copyright (C) 2019 
#  * Área Académica de Ingeniería en Computadoras, ITCR, Costa Rica
#  *
#  * Makefile
#  *
#  * @Author: Jeremy Rodriguez
#  * @Date  : 08.05.2019
#  */

APP=pipeline
COMPILER=comp
Ccpp=g++
INCLUDE=../include
AR=ar
OPTNS= -std=c++14

all: lib$(APP).a lib$(COMPILER).a

$(APP).o: $(APP).cpp
		  $(Ccpp) $(OPTNS) -c $(APP).cpp -o $(APP).o -I$(INCLUDE)

# Make pipeline.cpp
lib$(APP).a: $(APP).o
			 $(AR) rcs lib$(APP).a $(APP).o

$(COMPILER).o: $(COMPILER).cpp
		  $(Ccpp) $(OPTNS) -c $(COMPILER).cpp -o $(COMPILER).o -I$(INCLUDE)

# Make comp.cpp
lib$(COMPILER).a: $(COMPILER).o
			 $(AR) rcs lib$(COMPILER).a $(COMPILER).o

clean:
		rm -f *.o
		rm -f *.a
		rm -f machCode.txt
		
.PHONY:clean