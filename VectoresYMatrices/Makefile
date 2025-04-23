CPPC=g++
SRC=main.cpp Vector3.cpp Vector4.cpp Matrix3.cpp Matrix4.cpp
TARGET=vector
LIBS= -lsfml-graphics -lsfml-window -lsfml-system

#DEFAULT
all: $(TARGET)

#COMPILE
$(TARGET): $(SRC)
	$(CPPC) -o $(TARGET) $(SRC) $(LIBS)

clean: 
	rm -rf $(TARGET)
