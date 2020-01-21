How to use this wordcount program.

First make sure to compile the program as this is required before any of the rest of the nmake commands will work, this is done by typing nmake wordcountcomp (for wordcount compile)
There are different options for running this programing depending on what you require.

Theses options are:
nmake wordcountcomp				- ALWAYS RUN THIS FIRST, this will compile the code, this is done seperatly from the rest of the commands to be more efficient as compiling every time the program is run is slow
nmake wordcount 				- this will run the program asking for you to input information in the command line and output to the command line
nmake wordcount -c				- this will run the program asking for you to input information in the command line and output to the command line but case will be ignored, e.g. “Language” and “language” are treated as the same.
nmake wordcountsentence			- this will run the program and input from sentences_test.txt and then output to the command line
nmake wordcountsentencec		- this will run the program and input from sentences_test.txt and then output to the command line but case will be ignored, e.g. “Language” and “language” are treated as the same.
nmake wordcountoutput			- this will run the program asking for you to input information in the command line and output to output.txt
nmake wordcountoutputc			- this will run the program asking for you to input information in the command line and output to output.txt but case will be ignored, e.g. “Language” and “language” are treated as the same.
nmake wordcountsentenceoutput	- this will run the program and input from sentences_test.txt and output to output.txt
nmake wordcountsentenceoutputc	- this will run the program and input from sentences_test.txt and output to output.txt but case will be ignored, e.g. “Language” and “language” are treated as the same.
nmake wordcountsingle			- this will run the program and input from single_words_test.txt and then output to the command line
nmake wordcountsinglec			- this will run the program and input from single_words_test.txt and then output to the command line but case will be ignored, e.g. “Language” and “language” are treated as the same.
nmake wordcountsingleoutput		- this will run the program and input from single_words_test.txt and then output to output.txt
nmake wordcountsingleoutputc	- this will run the program and input from single_words_test.txt and then output to output.txt but case will be ignored, e.g. “Language” and “language” are treated as the same.
nmake clean						- this deletes all .obj,.exe and .asm files

This code will will take in a string or characters either from command line or from a file and will count the words and check how often each word appears, this will then be sorted from highest to lowest occournces and then output this information to either the command line or a selected file
If you want to manually use this program so that you can select input and output files or case sentitivity you will be able to use these options

wordcount on its own will run the program taking input and outuput to and from the command line, the following arguements can be added to change how the program opperates:
The -i fillename  arguement can be added which allows you to select the file you want to read from, a example would be "wordcount -i sentences_test.txt" this would read from the sentences_test.txt.
The -o filename  arguement can be added which allows you to select the file you want to output to, a example would be "wordcount -o output.txt" this would output all information into a text file in the same desination as the program.
The -c arguement can be added which allows the case of the words to be counted can be ignored for example “Language” and “language” are treated as the same(all words lowercased to represent this).
These arguments can be used in any order as long as the file comes after the arguement, and can be used in any combination.

This code was designed and compiled in the Microsoft Visual Studio 2017 Developer Command Prompt v15.5.6.








