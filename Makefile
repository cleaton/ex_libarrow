MIX = mix
CFLAGS = -g -O3 --std=c++11 -Wall

ROOT_DIR:=$(shell dirname $(realpath $(firstword $(MAKEFILE_LIST))))
INCLUDE_PATH:=$(ROOT_DIR)/c_deps/include
LIB_PATH:=$(ROOT_DIR)/c_deps/lib

ERLANG_PATH = $(shell erl -eval 'io:format("~s", [lists:concat([code:root_dir(), "/erts-", erlang:system_info(version), "/include"])])' -s init stop -noshell)
CFLAGS += -I$(ERLANG_PATH) -I$(INCLUDE_PATH)

ifneq ($(OS),Windows_NT)
	CFLAGS += -fPIC
	LDFLAGS += -Wl,--no-as-needed -L$(LIB_PATH) -larrow -lparquet

	ifeq ($(shell uname),Darwin)
		LDFLAGS += -dynamiclib -undefined dynamic_lookup
	else
		LDFLAGS += -shared
	endif
endif

.PHONY: all libarrow clean test

all: libarrow

libarrow:
	LD_LIBRARY_PATH=$(LIB_PATH) $(MIX) compile

test:
	LD_LIBRARY_PATH=$(LIB_PATH) $(MIX) test

ex_libarrow.so: src/*.cc src/*.h
	$(CXX) $(LDFLAGS) $(CFLAGS) -o $@ $^

clean:
	$(MIX) clean
	rm -f ex_libarrow.so