ALL:clean zwm

HEADERS = $(wildcard *.hpp)
SOURCES = $(wildcard *.cpp)
OBJECTS = $(patsubst %.cpp, %.o, $(SOURCES))


PKG_CONFIG = pkg-config

# includes and libs
INCS = -I`$(PKG_CONFIG) --cflags fontconfig` \
       `$(PKG_CONFIG) --cflags freetype2`
LIBS = -lm -lrt -lX11 -lutil -lXft \
       `$(PKG_CONFIG) --libs fontconfig` \
       `$(PKG_CONFIG) --libs freetype2`
# flags
CXXFLAGS = -Wall -g
CXXFLAGS += $(INCS)

LDFLAGS = $(LIBS)

zwm: $(OBJECTS)
	$(CXX) $^ -o $@ $(LDFLAGS)

#%.o:%.cpp
#	$(CXX) -c $< -o $@ -g  $(CXXFLAGS)

.PHONY: clean
clean:
	rm -rf $(OBJECTS) zwm *.o
