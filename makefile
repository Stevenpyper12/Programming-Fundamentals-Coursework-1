wordcountcomp:
	cl wordcount.c

wordcount:
	wordcount

wordcountc:
	wordcount -c	

wordcountsentence:
	wordcount -i sentences_test.txt
	
wordcountsentencec:
	wordcount -i sentences_test.txt -c
		
wordcountoutput:
	wordcount -o output.txt	

wordcountoutputc:
	wordcount -o output.txt -c	
	
wordcountsentenceoutput:
	wordcount -i sentences_test.txt -o output.txt 
	
wordcountsentenceoutputc:
	wordcount -i sentences_test.txt -o output.txt -c	

wordcountsingle:
	wordcount -i single_words_test.txt
	
wordcountsinglec:
	wordcount -i single_words_test.txt	-c
	
wordcountsingleoutput:
	wordcount -i single_words_test.txt -o output.txt
		
wordcountsingleoutputc:
	wordcount -i single_words_test.txt -o output.txt -c
			
	
clean:
	del *.obj
	del *.exe
	del *.asm