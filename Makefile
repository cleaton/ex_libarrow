MIX = mix
CFLAGS = -g -O3 --std=c++11 -Wall

ERLANG_PATH = $(shell erl -eval 'io:format("~s", [lists:concat([code:root_dir(), "/erts-", erlang:system_info(version), "/include"])])' -s init stop -noshell)
CFLAGS += -I$(ERLANG_PATH) -Ic_deps/include

ifneq ($(OS),Windows_NT)
	CFLAGS += -fPIC
	LDFLAGS += -Lc_deps/lib -larrow -lparquet

	ifeq ($(shell uname),Darwin)
		LDFLAGS += -dynamiclib -undefined dynamic_lookup
	else
		LDFLAGS += -shared
	endif
endif

.PHONY: all libarrow clean

all: libarrow

libarrow:
	$(MIX) compile

ex_libarrow.so: src/*.cc
	$(CXX) $(CFLAGS) -shared $(LDFLAGS) -o $@ $^

clean:
	$(MIX) clean
	rm -f ex_libarrow.so