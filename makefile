all: CatalogDisplay.exe

CatalogDisplay.exe: CatalogDisplay.o
	g++ -o CatalogDisplay.exe CatalogDisplay.o -ltinyxml2

CatalogDisplay.o: CatalogDisplay.cpp
	g++ -c CatalogDisplay.cpp

clean:
	rm -f CatalogDisplay.o CatalogDisplay.exe
