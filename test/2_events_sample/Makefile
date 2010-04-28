.DELETE_ON_ERROR:

SHELL         = /bin/bash

ROOTCONFIG   := root-config
ROOTCFLAGS   := $(shell $(ROOTCONFIG) --cflags)
ROOTLDFLAGS  := $(shell $(ROOTCONFIG) --ldflags)
ROOTLIBS     := $(shell $(ROOTCONFIG) --libs)
ROOTDICTTYPE := $(shell $(ROOTCONFIG) --dicttype)
ROOTCINT     := rootcint

CXX           = g++
CXXFLAGS      = -O2 -Wall -fPIC $(ROOTCFLAGS)
LD            = g++
LDFLAGS       = -O2 $(ROOTLDFLAGS)
SOFLAGS       = -shared
LIBS          = $(ROOTLIBS)

EVENT_OBJ     = Event.o EventDict.o
EVENT_SRC     = Event.cxx EventDict.cxx
EVENT_SO      = libEvent.so
EVENT         = Event

MAIN_OBJ = MainEvent.o
MAIN_SRC = MainEvent.cxx


.PHONY: all lib clean distclean

all: $(EVENT)

lib: $(EVENT_SO)

$(EVENT): $(EVENT_SO) $(MAIN_OBJ)
	$(LD) $(LDFLAGS) $(MAIN_OBJ) $(EVENT_OBJ) $(LIBS) -o $@
	@echo "$@ done"

$(EVENT_SO): $(EVENT_OBJ)
	$(LD) $(SOFLAGS) $(LDFLAGS) $^ -o $@ 


clean:
	@rm -f $(EVENT_OBJ) $(MAIN_OBJ) EventDict.*

distclean: clean
	@rm -f $(EVENT) $(EVENT_SO) Event.root tags


Event.o $(MAIN_OBJ): Event.h

EventDict.cxx: Event.h EventLinkDef.h
	@echo "Generating dictionary $@..."
	$(ROOTCINT) -f $@ -c $^

%.o: %.cxx
	$(CXX)  $(CXXFLAGS) -c $< -o $@


-include Makefile_me
