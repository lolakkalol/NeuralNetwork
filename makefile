INC=./inc
CC=g++
OBJ=obj

nn: $(OBJ)/main.o $(OBJ)/Neuron.o $(OBJ)/Layer.o $(OBJ)/Network.o
	$(CC) -o nn $(OBJ)/main.o $(OBJ)/Neuron.o $(OBJ)/Layer.o $(OBJ)/Network.o

$(OBJ)/main.o: src/main.cpp inc/Layer.h inc/Network.h inc/Neuron.h
	$(CC) src/main.cpp -I $(INC) -c -o $(OBJ)/main.o

$(OBJ)/Neuron.o: src/Neuron.cpp inc/Neuron.h
	$(CC) src/Neuron.cpp -I $(INC) -c -o $(OBJ)/Neuron.o

$(OBJ)/Layer.o: src/Layer.cpp inc/Layer.h
	$(CC) src/Layer.cpp -I $(INC) -c -o $(OBJ)/Layer.o

$(OBJ)/Network.o: src/Network.cpp inc/Network.h
	$(CC) src/Network.cpp -I $(INC) -c -o $(OBJ)/Network.o

clean:
	rm nn
	rm -fR obj
	mkdir obj
