##
## EPITECH PROJECT, 2025
## Arcade
## File description:
## Makefile
##

DIR = $(shell pwd)
SRC_DIR = $(DIR)/src
LIB_DIR = $(DIR)/lib
INCLUDE_DIR = $(DIR)/include
MAKE = make

all: make_arcade_core

clean: clean_arcade_core

fclean: fclean_arcade_core

re: re_arcade_core

make_arcade_core: 
	$(MAKE) -s -C $(SRC_DIR)/Arcade all DIR=$(DIR) INCLUDE_DIR=$(INCLUDE_DIR)

clean_arcade_core: 
	$(MAKE) -s -C $(SRC_DIR)/Arcade clean DIR=$(DIR) INCLUDE_DIR=$(INCLUDE_DIR)

fclean_arcade_core:
	$(MAKE) -s -C $(SRC_DIR)/Arcade fclean DIR=$(DIR) INCLUDE_DIR=$(INCLUDE_DIR)

re_arcade_core:
	$(MAKE) -s -C $(SRC_DIR)/Arcade re DIR=$(DIR) INCLUDE_DIR=$(INCLUDE_DIR)