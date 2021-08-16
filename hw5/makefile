# ------------------------------- #
MAIN = main
TARGET = TriangularMatrix
CC = g++
CFLAGS = -c
FILENAME = a.out
# ------------------------------- #


# ------------------------------------------------------- #
all: ${TARGET}.o ${MAIN}.o
	@${CC} ${TARGET}.o ${MAIN}.o -o ${FILENAME}

${MAIN}.o: ${MAIN}.cpp ${TARGET}.h
	@${CC} ${MAIN}.cpp ${CFLAGS}

${TARGET}.o: ${TARGET}.cpp ${TARGET}.h
	@${CC} ${TARGET}.cpp ${CFLAGS}

clean:
	rm -rf *.o
# ------------------------------------------------------- #
