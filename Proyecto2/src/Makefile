# /**
#  * Copyright (C) 2019 
#  * Área Académica de Ingeniería en Computadoras, ITCR, Costa Rica
#  *
#  * Makefile
#  *
#  * @Author: Jeremy Rodriguez
#  * @Date  : 08.05.2019
#  */

APP=cpu
Ccpp=g++
LIBS=../lib
INCLUDE=../include
LINKERFLAGS=-lpipeline -lpthread -lcomp
OUT=../bin
OPTNS= -std=c++14

all: $(APP) setup

setup:	
	   mkdir -p $(OUT)

$(APP).o: $(APP).cpp
		  $(Ccpp) $(OPTNS) -c $(APP).cpp -o $(APP).o -I$(INCLUDE)

$(APP): $(APP).o setup
		$(Ccpp) -o $(OUT)/$(APP) $(APP).o -L$(LIBS) $(LINKERFLAGS)

clean:
		rm -f  $(OUT)/$(APP)*
		rm -f *.o 
		rm -f *.so
		rm -f *.a
		rm -f machCode.txt

.PHONY:clean