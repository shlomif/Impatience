#########################################################################
#Written by Ivan Rubinson (Soryy708) with the assistance of (dardevelin)#
#Big thanks to (dardevelin)!                                            #
#########################################################################
#Stuff that you need to change:



#Target (can be 'Release' or 'Debug')
TARGET=

#Path to SDL (optional on Linux)
SDLPATH=

#Path to the compiler (optional on Linux)
PATH=

#Desired name for the executable
EXECUTABLE=

#C++ compiler to use
CC=

##################################################
#Stuff that you shouldn't need to change:


########
#Check that the user specified the required fields
#
ifeq ($(strip $(TARGET)),) #TARGET is empty
  $(error Please specify a target (TARGET))
endif
ifeq ($(strip $(EXECUTABLE)),) #EXECUTABLE is empty
  $(error Please specify a target (EXECITABLE))
endif
ifeq ($(strip $(CC)),) #CC is empty
  $(error Please specify a compiler (CC))
endif
########

########
#Define variables for different targets
#
DBGFILES=
DBGC=
DBGLNK=-g

RELFILES=
RELC=
RELLNK=
########

########
#Choose the right variables for the current target
#
TARGETFILES: $(TARGET) $(DBGFILES) $(RELFILES)
ifeq ($(TARGET),Debug)
  TFILES=$(DBGFILES)
  TC=$(DBGC)
  TLNK=$(DBGLNK)
else
  ifeq ($(TARGET),Release)
    TFILES=$(RELFILES)
    TC=$(RELC)
    TLNK=$(RELLNK)
  endif
endif
########

########
#Some simple house-keeping
#
CFLAGS=-I/$(SDLPATH)/include/ $(TC) -w

LDFLAGS=-L/$(SDLPATH)/lib/ $(TLNK) -lSDLmain -lSDL

SOURCES=game_card.cpp game_manager.cpp game_move.cpp game_state.cpp gui_area.cpp gui_manager.cpp input_manager.cpp main.cpp $(TFILES)

OBJECTS=$(SOURCES:.cpp=.o)
########

########
#The actual compiling & linking
#
$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) -c $(SOURCES)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE)
########