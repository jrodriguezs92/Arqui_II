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
Ccpp=g++
INCLUDE=../include
AR=ar
OPTNS= -std=c++14

all: lib$(APP).a

$(APP).o: $(APP).cpp
		  $(Ccpp) $(OPTNS) -c $(APP).cpp -o $(APP).o -I$(INCLUDE)

lib$(APP).a: $(APP).o
			 $(AR) rcs lib$(APP).a $(APP).o

clean:
		rm -f *.o
		rm -f *.a
		
.PHONY:clean