**************************************************
* Credits for make: https://github.com/kth-competitive-programming/kactl                            
**************************************************

**************************************************
* System requirements                            
**************************************************
The build process uses the following tools:
	LaTeX (pdflatex together with some common packages such as 'listings')
	Python
	make

It has been tested with the following versions:
	pdfTeX 3.141592-1.40.3-2.2 (Web2C 7.5.6), part of TeXLive-2007
	pdfeTeX 3.141592-1.21a-2.2 (Web2C 7.5.4)
	Python 2.5.1
	Python 2.4.4
	GNU Make 3.81
	GNU Make version 3.79.1
but should (could?) work with other versions too.

**************************************************
* Building the KACTL                             
**************************************************
To build the KACTL should be a simple step. Just navigate to the root folder for this project and type 'make pdf' (and do your normal Voodoo dance that you do to get an accepted submission).


**************************************************
* Adding new chapters                            
**************************************************
Create a folder for the chapter inside the 'content' folder. Then create (or copy) a chapter.tex file inside this new folder, which will be the main file for the chapter. You can then place source files in this folder and include them by modifying the chapter.tex file.
Finally, you'll need to modify the file content/main.tex to add the new chapter folder. Notice that if you've followed the instructions above, all you need is to specify the name of the new chapter folder with the 'kactlchapter' command.
Ex. \kactlchapter{geometry} will include the file content/geometry/chapter.tex


**************************************************
* Adding new source files                        
**************************************************
First, locate the folder for the chapter where you want to add the new source file, or follow the instructions for creating a new chapter above. The chapter folder should be directly below the 'content' folder.
The source files should be placed inside this chapter folder, and the file has to included by the 'chapter.tex' file in the same folder.
Ex. \kactlimport{example.h} will include the file example.h from the same folder.

Remember to annotate the file correctly before including it!
Also, don't forget to write tests for the code before including it!
