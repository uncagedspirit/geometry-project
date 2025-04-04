# Directories
INCLUDE_DIR = geometry/include
SRC_DIR = geometry/src
BIN_DIR = geometry/bin
LIB_DIR = geometry/lib
APP_SRC = application/src
APP_BIN = application/bin
APP_LIB = application/lib

APP_INCLUDE_DIR = application/include

# Compiler and flags
CXX = g++
CXXFLAGS = -c -fPIC -I$(INCLUDE_DIR) -I$(APP_INCLUDE_DIR)
LDFLAGS = -shared -o $(LIB_DIR)/libgeometry.so
LIBRARY_PATH = -L$(LIB_DIR) -lgeometry

# Object files
OBJECTS = $(BIN_DIR)/point2d.o $(BIN_DIR)/point3d.o $(BIN_DIR)/line2d.o $(BIN_DIR)/line3d.o $(BIN_DIR)/circle.o \
		  $(BIN_DIR)/rectangle.o $(BIN_DIR)/square.o $(BIN_DIR)/cuboid.o $(BIN_DIR)/cube.o $(BIN_DIR)/cylinder.o $(BIN_DIR)/sphere.o
APP_OBJECTS = $(APP_BIN)/main.o $(APP_BIN)/inputHandler.o 

# Ensure directories exist
.PHONY: init
init:
	mkdir -p $(BIN_DIR) $(LIB_DIR) $(APP_BIN)

# Compile object files
$(BIN_DIR)/point2d.o: $(SRC_DIR)/entities/2d/point2d.cc
	$(CXX) $(CXXFLAGS) $< -o $@

$(BIN_DIR)/point3d.o: $(SRC_DIR)/entities/3d/point3d.cc
	$(CXX) $(CXXFLAGS) $< -o $@

$(BIN_DIR)/line2d.o: $(SRC_DIR)/entities/2d/line2d.cc
	$(CXX) $(CXXFLAGS) $< -o $@

$(BIN_DIR)/line3d.o: $(SRC_DIR)/entities/3d/line3d.cc
	$(CXX) $(CXXFLAGS) $< -o $@

$(BIN_DIR)/circle.o: $(SRC_DIR)/shapes/curves/2d/circle.cc
	$(CXX) $(CXXFLAGS) $< -o $@

$(BIN_DIR)/rectangle.o: $(SRC_DIR)/shapes/polygons/2d/rectangle.cc
	$(CXX) $(CXXFLAGS) $< -o $@

$(BIN_DIR)/square.o: $(SRC_DIR)/shapes/polygons/2d/square.cc
	$(CXX) $(CXXFLAGS) $< -o $@

$(BIN_DIR)/cuboid.o: $(SRC_DIR)/shapes/polygons/3d/cuboid.cc
	$(CXX) $(CXXFLAGS) $< -o $@

$(BIN_DIR)/cube.o: $(SRC_DIR)/shapes/polygons/3d/cube.cc
	$(CXX) $(CXXFLAGS) $< -o $@

$(BIN_DIR)/cylinder.o: $(SRC_DIR)/shapes/curves/3d/cylinder.cc
	$(CXX) $(CXXFLAGS) $< -o $@

$(BIN_DIR)/sphere.o: $(SRC_DIR)/shapes/curves/3d/sphere.cc
	$(CXX) $(CXXFLAGS) $< -o $@

$(APP_BIN)/inputHandler.o: $(APP_SRC)/utils/inputHandler/inputHandler.cc
	$(CXX) $(CXXFLAGS) $< -o $@

$(APP_BIN)/main.o: $(APP_SRC)/main.cc
	$(CXX) $(CXXFLAGS) $< -o $@

# Link object files into shared library
$(LIB_DIR)/libgeometry.so: $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS)

# Compile the main application
$(APP_BIN)/app: $(APP_OBJECTS) $(LIB_DIR)/libgeometry.so
	$(CXX) -I$(INCLUDE_DIR) -I$(APP_INCLUDE_DIR) $(APP_OBJECTS) -L$(LIB_DIR) -lgeometry -o $@

# Run the application
.PHONY: run
run: $(APP_BIN)/app
	export LD_LIBRARY_PATH=$(LIB_DIR):$$LD_LIBRARY_PATH && ./$(APP_BIN)/app

# Clean up object files, shared library, and binaries
.PHONY: clean
clean:
	rm -rf $(BIN_DIR) $(LIB_DIR) $(APP_BIN) $(APP_LIB)
	mkdir -p $(BIN_DIR) $(LIB_DIR) $(APP_BIN) $(APP_LIB)

