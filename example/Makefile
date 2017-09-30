OBJS = test_tensor1.o test_tensor2.o test_tensor3.o test_tensor4.o
CC = mpic++
DEBUG = -g -DDEBUG
CFLAGS = -Wall -std=c++11 $(DEBUG)
LFLAGS = -Wall -std=c++11 $(DEBUG)

SRC = \
../src/Domain.cpp \
../src/ActorSubdomain.cpp \
../src/MPI_Channel.cpp \
../src/MPI_Machine.cpp \
../src/ObjectBroker.cpp \
../src/PartitionedDomain.cpp \
../src/ShadowSubdomain.cpp \

INCLUDE_HEADER_LOCATION=\
-I../src/
LINK_LIB_LOCATION=\
# -L../../
LINK_LIB_NAME=\
-lmpi \
# -lblas \
# -llapack \
# -ldl

compile:
	${CC} -o test.out ${CFLAGS} main.cpp ${SRC} ${INCLUDE_HEADER_LOCATION} ${LINK_LIB_LOCATION}

clean:
	rm -f test.out
