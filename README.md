**************************************************
* Credits for make: https://github.com/kth-competitive-programming/kactl                            
**************************************************

**************************************************
* Wymagania                            
**************************************************
Narzędzia potrzebne do kompilacji:
	LaTeX (pdflatex)
	Python
	make

**************************************************
* Kompilacja 
**************************************************
Kompilacja komendą 'make pdf' w folderze głównym.


**************************************************
* Dodawanie nowych rozdziałów 
**************************************************
Trzeba stworzyć folder w folderze 'content'. W nim stworzyć plik chapter.tex, który będzie plikiem tego rozdziału. W nim umieszczamy pliki z kodami.
Trzeba potem zmodyfikować plik content/main.tex, przez dodanie nowego rozdziału. Rozdział dodajem komendą '\kactlchapter', podając nazwe folderu.
Np. \kactlchapter{geometry} dodaje plik content/geometry/chapter.tex


**************************************************
* Dodawanie nowych plików z kodami 
**************************************************
Tworzymy plik w folderze odpowiedniego rozdziału, a potem w odpowiednim pliku 'chapter.tex' dodajemy ten plik.
Np. \kactlimport{example.cpp} dodaje plik example.cpp.

Należy pamiętać o odpowiednim opisaniu pliku przed dołączeniem go!
