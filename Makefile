TARGET   := program

ifeq ($(OS),Windows_NT)
	SYSTEM 	= win
	SUFFIX	= .exe
	RUN	= libs/sfml-win/bin/${TARGET}${SUFFIX}
	OUT_DIR	= libs/sfml-win/bin/
	MKDIR	= (@mkdir $(subst /,\,$(dir $@)))&
else
	SYSTEM 	= linux
	SUFFIX	=
	RUN	= export LD_LIBRARY_PATH=libs/sfml-linux/lib && ./${TARGET}${SUFFIX}
	OUT_DIR	= 
	MKDIR	= @mkdir -p $(@D)
endif

CC       := g++
CXXFLAGS := -std=c++11 -g -Wall
LDFLAGS  := -Llibs/sfml-${SYSTEM}/lib -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system
BUILD    := ./build
INCLUDE  := -I include -I engine/include -I libs/sfml-${SYSTEM}/include

SRC      := $(wildcard src/**/**/**/*.cpp) $(wildcard src/**/**/*.cpp) $(wildcard src/**/*.cpp) $(wildcard src/*.cpp) $(wildcard engine/**/**/**/*.cpp) $(wildcard engine/**/**/*.cpp) $(wildcard engine/**/*.cpp) $(wildcard engine/*.cpp)
OBJECTS  := $(SRC:%.cpp=$(BUILD)/%.o)


all: $(TARGET)


$(BUILD)/%.o: %.cpp
	${MKDIR}
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

$(TARGET): $(OBJECTS)
	${MKDIR}
	$(CXX) $(CXXFLAGS) -o ${OUT_DIR}$(TARGET)${SUFFIX} $^ $(LDFLAGS)

.PHONY: run

run:
	${RUN}	
