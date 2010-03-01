.DELETE_ON_ERROR:

SHELL         = /bin/bash

ROOTCONFIG   := root-config
ROOTCFLAGS   := $(shell $(ROOTCONFIG) --cflags)
ROOTLDFLAGS  := $(shell $(ROOTCONFIG) --ldflags)
ROOTGLIBS    := $(shell $(ROOTCONFIG) --libs)

CXX          := g++
CXXFLAGS     := -O2 -Wall -fPIC $(ROOTCFLAGS)
LD           := g++
LDFLAGS      := -O2 $(ROOTLDFLAGS)
LIBS         := $(ROOTGLIBS)

FILE	     :=	two_pion_C_data


.PHONY: all lib clean

all: $(FILE)

clean:
	rm -f $(FILE)

%: %.o
	$(LD) $(LDFLAGS) $^ $(LIBS) -o $@

%.o: %.cxx
	$(CXX)  $(CXXFLAGS) -c $< -o $@
