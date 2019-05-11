# /**
#  * Copyright (C) 2019 
#  * Área Académica de Ingeniería en Computadoras, ITCR, Costa Rica
#  *
#  * Makefile
#  *
#  * @Author: Jeremy Rodriguez
#  * @Date  : 08.05.2019
#  */

all: src

lib:
		$(MAKE) -C lib
		
src: lib
		$(MAKE) -C src

clean:
		$(MAKE) -C lib clean
		$(MAKE) -C src clean
		rm -f machCode.txt
		clear

.PHONY: all lib src clean