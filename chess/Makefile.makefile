chess+: chess+.o chessman.o chesslib.o
	g++ -o chess+ chess+.o chessman.o chesslib.o

chess+.o: chess+.cc chesslib.h chessman.h
	g++ -c -o chess+.o chess+.cc
chessman.o: chessman.cc chessman.h
	g++ -c -o chessman.o chessman.cc
chesslib.o: chesslib.cc chesslib.h chessman.h
	g++ -c -o chesslib.o chesslib.cc
clean:
	rm -rf *.o chess+
