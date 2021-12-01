#
# **************************************************************
# *                Simple C++ Makefile Template                *
# *                                                            *
# * Author: Arash Partow (2003)                                *
# * URL: http://www.partow.net/programming/makefile/index.html *
# *                                                            *
# * Copyright notice:                                          *
# * Free use of this C++ Makefile template is permitted under  *
# * the guidelines and in accordance with the the MIT License  *
# * http://www.opensource.org/licenses/MIT                     *
# *                                                            *
# **************************************************************
#

CXX      ?= g++
CXXFLAGS += -std=c++2a -pedantic-errors -Wall -Wextra #-Werror
LDFLAGS  += -L/usr/lib -lstdc++ -lm
BUILD    ?= ./build
OBJ_DIR  := $(BUILD)/objects
APP_DIR  := $(BUILD)
TARGET   ?= tirecenter
INCLUDE  ?= -Iinclude/
SRC      ?=                      \
   $(wildcard src/*.cpp)         \
   #$(wildcard src/module1/*.cpp) \
   #$(wildcard src/module2/*.cpp) \

OBJECTS := $(SRC:%.cpp=$(OBJ_DIR)/%.o)
DEPENDENCIES := \
	$(OBJECTS:.o=.d)

all: build $(APP_DIR)/$(TARGET)

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -MMD -o $@

$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -o $(APP_DIR)/$(TARGET) $^ $(LDFLAGS)

-include $(DEPENDENCIES)

.PHONY: all static clean debug release static docker info run gdb

build:
	@mkdir -p $(APP_DIR)
	@mkdir -p $(OBJ_DIR)


debug: CXXFLAGS += -DDEBUG -g3
debug: all

release: CXXFLAGS += -O2
release: all

static: LDFLAGS += -static
static: release

docker: build
	docker build -t tirecenter .
	@$(eval LAYER = $(shell docker save tirecenter  | tar xf - repositories  --to-stdout | sed -r --expression='s/.*\{.*\"tirecenter\":\{.*\"latest\":\"(.*)\".*}.*}.*/\1/'))
	@docker save tirecenter  | tar xf - $(LAYER)/layer.tar --to-stdout | tar -C $(APP_DIR) -xf - tirecenter

run: all
	$(APP_DIR)/$(TARGET)

gdb: debug
	@gdb $(APP_DIR)/$(TARGET)

clean:
	-@rm -rvf $(OBJ_DIR)/*
	-@rm -rvf $(APP_DIR)/*

info:
	@echo "[*] Linker flags:    ${LDFLAGS}     "
	@echo "[*] Application dir: ${APP_DIR}     "
	@echo "[*] Object dir:      ${OBJ_DIR}     "
	@echo "[*] Sources:         ${SRC}         "
	@echo "[*] Objects:         ${OBJECTS}     "
	@echo "[*] Dependencies:    ${DEPENDENCIES}"
	@echo "[*] Compiler flags:  ${CXXFLAGS}    "
	@echo "[*] Compiler:        ${CXX}         "
	@echo "[*] Combiler version:               "
	@${CXX} --version
