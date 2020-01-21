/*
Code written by Steven Pyper 
matriculation number 40319882 
last modification 17/02/2018
The purpose of this code is to either read from the command line or a file and do a wordcount and also check how many time each word appears, this will then either be output to a file or to command line.
*/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
//both defines are used to setup the max size of there related titles, they are declared here like this so that they can be changed either up or down in future for larger or smaller text files depending on what is required
#define MAXSTRINGSIZE 100000
#define MAXFILENAMESIZE 400
#define MAXNUMBEROFSTRUCTS 5000
#define MAXWORDSIZE 100

//this structure is used as a way of keeping each individual word and the amount of times it shows up linked together and allows for easy sorting and checking for duplicates, the temporary alias is used as a temporary structure during the sorting process so that the program can bubble sort it.
struct wordStructure
{
	//stores the individual word that has been inputted
	char words [60];
	//stores how often the word appears
	int frequency;
}temporary ;

//functions predeclared
char* checkForInputFile(int argc,char **argv, char *inputFile);
char* checkForOutputFile(int argc,char **argv,char *outputFile);

//main function used as a way of organization the flow of control of the program and calls functions which include checks and 
int main(int argc,char **argv )
{
	char fullString[MAXSTRINGSIZE]; //this is the character array which will hold the entire of the input
	char buf[MAXSTRINGSIZE];// this is used to take in the input from fgets and hold that current string up to the newline, it will then be concatenated to fullstring
	int caseSensitive=0;
	//both these are used to store the input and output files location if they are needed
	char *inputFile=malloc(MAXFILENAMESIZE);
	char *outputFile=malloc(MAXFILENAMESIZE);

	inputFile=checkForInputFile(argc,argv,inputFile); //sets the inputFile variable to whatever is returned from the checkForInputFile function, passes along argv and argc and inputfile variables
	outputFile=checkForOutputFile(argc,argv,outputFile); //sets the outputFile variable to whatever is returned from the checkForOutputFile function, passes along argv and argc and outputfile variables
	caseSensitive=checkForCaseSensitive(argc,argv,caseSensitive); //sets the caseSensitive variable to whatever is returned from the checkForCaseSensitive function, passes along argv and argc and caseSensitive variables
	inputText(inputFile,buf,fullString); // this function either reads text from a file or reads from standered input (command line)
	void free(inputFile);// frees the memory used by inputfile
	inputFile=NULL;//sets inputfile to null becuase its easier to check for nulls if there are any issues
	sortText(fullString,caseSensitive);//takes out all puntucation and  deals with the case sensitivity by setting everything to lower case if required
	wordsAppearFile(fullString,outputFile);//deals with counting how often each word shows up and sorting it into order from highest to lowest and outputting it either to a file or to commandline
	void free(outputFile);// frees the memory used by outputFile
	outputFile=NULL;//sets outputFile to null becuase its easier to check for nulls if there are any issues

}
//used to check if there has beena  inputfile defined in the commandline when it has been called. Calls in the variables argc which contains how many arguments there are required to be used to loop all possible arguements  , argv is required as it contains all individual arguements which are needed to check for a input arguement, and the file itself is passed in as it is setup outside the function as its used in multiple places
char* checkForInputFile(int argc,char **argv, char *inputFile)
{
	for(int i = 0;i < argc ; i++)//loops for all arguements
	{
		if(strcmp(argv[i], "-i") == 0 || strcmp(argv[i], "-I") == 0 )// checks if the argument has either -i or -I, if true it returns 0, if false returns -1
		{	
			inputFile=argv[i+1];//sets the inputfile to the following arguement after -i or -I has been found
			return inputFile;
		}
		else
		{
			inputFile= NULL;//if no file -i or -I is found inputfile is set to null
		}
	}
	return inputFile;
}
//used to check if there has been a  outputfile defined in the commandline when it has been called.Calls in the variables argc which contains how many arguments there are required to be used to loop all possible arguements  , argv is required as it contains all individual arguements which are needed to check for a output arguement, and the file itself is passed in as it is setup outside the function as its used in multiple places

char* checkForOutputFile(int argc,char **argv, char *outputFile)
{
	for(int i = 0; i < argc ; i++)//loops for all arguements
	{
		if(strcmp(argv[i], "-o") == 0 || strcmp(argv[i], "-O") == 0)//checks if the argument has either -o or -O, if true it returns 0, if false returns -1
		{	
			outputFile=argv[i+1];//sets the outputFile to the following arguement after -o or -O has been found
			return outputFile;
		}
		else
		{
			outputFile=NULL;//if no file -o or -O is found inputfile is set to null
		}
	}
	return outputFile;
}
//used to check if the program is required to be case sensitive or not. Calls in the variables argc which contains how many arguments there are required to be used to loop all possible arguements  , argv is required as it contains all individual arguements which are needed to check for a case arguement, the casesentivity is also passed into the function as it is used outside of the function meanig it doesnt hafvent to be declared inside the function
int checkForCaseSensitive(int argc,char **argv,int caseSensitive)
{
	for(int i = 0; i < argc ; i++)//loops for all arguements
	{
		if(strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "-C") == 0)//checks if the argument has either -c or -C, if true it returns 0, if false returns -1
		{	
			caseSensitive = 0;//sets caseSensitive to 0 meaning that the program will not be case sensitive
			return caseSensitive;
		}
		else
		{
			caseSensitive = 1;//sets caseSensitive to 1 meaning that the program will  be case sensitive
		}
	}
	return caseSensitive;
}

//reads text either from the command line or from a file and saves it inside fullstring. inputfile is passed in to allow it to be checked and opened, buf is passed in as a variable that will temporarly hold data its reading from, fullString will hold the entire string that is imputtped.
int inputText(char *inputFile,char buf[MAXSTRINGSIZE] , char fullString[MAXSTRINGSIZE])
{
	if(inputFile != NULL)//checks if the inputfile was previously set to null or not, if it doesnt equal null that means a file was declared, if it does equal null it goes to the else
	{
		FILE *file = fopen(inputFile, "r");//opens a file that was declared previously allowing it to be read 
		if(!file)//checks if file doesnt exist or there was a problem opening it
		{
			fprintf(stderr, "file input was not found or could not be opened, program closed");//prints that there was a issue
			exit(0);//closes the program
		}
		while (fgets(buf, MAXSTRINGSIZE, file) !=NULL)//reads from the opened file up until the newline and then enters the loop, this will continue until the end of the file which will return a NULL
		{
			strcat(fullString, buf);//each time a newline is found it will enter this code and will copy what has been saved into buf and add it to the end of fullstring
		}
		fclose(file);//closes the file
	
	}else//if no file was defined it will be null and run this code instead
	{
		printf("Please enter your text: ");
		fgets(fullString, MAXSTRINGSIZE, stdin);//copys what the user enters on command line into fullstring
	}
	
	return 0;
}
// used if the program is not case sensitive to change everything to lowercase. fullString is passed in as it is required fopr the function to make any changes that are required by the program. Case sensitivity is passed in to allow the program know if it has to deal with it.
int sortText(char fullString[MAXSTRINGSIZE], int caseSensitive)
{
	//no longer used code but kept for testing purpose, was used for the original word count but the new system doesnt require the dashes
	/*for(int i = 0; fullString[i]; i++)//loops for the total size of the string
	{
		if(!isalpha(fullString[i]))//checks if the character in position i is a letter of the alphabet or not
		{
			fullString[i] = '-';// repalce it with  a dash
		}
	}
	*/
	
	if(caseSensitive == 0)//checks if the program is case sensitive or not
	{
		for(int i = 0; fullString[i]; i++)//loops for the total size of the string
		{
			fullString[i]=tolower(fullString[i]);// changes each character to lowercase		
		}
	}
	return 0;
}

//this function is used to sort through each word and count how often each appears,  adding it to the structure and sorting it in order highest occurrence to lowest  before displaying it. fullString is passed in as it has to be read for the program to split the words up, outputFile is passed in to allow the program to know if the program is to be outputed toa  file or to command line
int wordsAppearFile(char fullString[MAXSTRINGSIZE],char *outputFile)
{
	struct wordStructure wordStruct[MAXNUMBEROFSTRUCTS];//declares a structure that will have a maximum size defined at the start of the program,
	char buffer[MAXWORDSIZE];//used to hold each individual word
	int sizeOfWord =0;//stores the size of each word
	int numberOfUniqueWords = 0;//stores how many unique words are found 
	int actualWordCount = 0;//stores the wordcount
	
	for(int i = 0; fullString[i]; i++)//loops for all the characters
	{	
		while(fullString[i] != ' ' && isalpha(fullString[i]) || fullString[i] == '\'')
		{
		buffer[sizeOfWord]=fullString[i];//will add each character into buffer from where it currently is in i
		sizeOfWord++;
		i++;
		}
		if(sizeOfWord > 0)//once it finds a space and has found that the the size of word is longer than one, 
		{
			buffer[sizeOfWord]='\0';//adds a null termantor so that the next function knows where the end of  the word is
			numberOfUniqueWords = addingToStructure(wordStruct,buffer,numberOfUniqueWords);//changes the unqie words depending on what is returned from addingToStructure, addingToStructure will take the word that has been entered and add it into a structure
			sizeOfWord=0;//resets the size of the word
			actualWordCount++;//adds one to the word count
		}	
	}
	if(numberOfUniqueWords > 0)
	{
	sortStructure(wordStruct,numberOfUniqueWords);//calls sortstructurte which will sort the structure highest occurrence to lowest
	}
	
	if(numberOfUniqueWords > 0)
	{
		if(outputFile!=NULL)//checks if there is a output file
		{
			FILE *fileoutput = fopen (outputFile, "w");//opens the file for writing
			for (int i = 0; i < numberOfUniqueWords; i++)//prints out each word
			{
				fprintf(fileoutput, "%s:   %d\n", wordStruct[i].words, wordStruct[i].frequency);//prints the unqique word and the frequency it appears on the same line to the file
			}
			fprintf(fileoutput, "the number of words in this string is %d \n", actualWordCount);// prints the wordcount to the file
			fclose(fileoutput);//closes file
		}else
		{
			for (int i = 0; i < numberOfUniqueWords; i++)//loops for all the unique words
			{
				printf("%s:   %d\n", wordStruct[i].words, wordStruct[i].frequency);//prints the unqique word and the frequency it appears on the same line to the command line
			}
			printf("the number of words in this string is %d\n", actualWordCount);//prints the wordcount to the commandline
		}
	}else
	{
		printf("no words were found");
	}
	
	return 0;	
}

//either adds the word into the structure or increases the frequency. the wordstructure array is passed in as it is required to hold all of the information about each word weather new or already entered, buffer holds the currect word that is being tested, numberofunqiuewords is used to track how many unqiue words there and must be passed through to increase it.
int addingToStructure(struct wordStructure wordStruct[], const char buffer[], int numberOfUniqueWords)
{
	for (int i = 0; i < numberOfUniqueWords; i++)//loops for the number of unique words
	{
		if(strcmp(wordStruct[i].words, buffer) == 0)//checks if the word saved in buffer has been placed in the structure array before
		{
			wordStruct[i].frequency++;//increases the fequency if the word is already in the structure
			return numberOfUniqueWords;//returns it with no change as it is not another unique word as it has already been saved
		}
	}
	//only gets here if the word has not been placed in hte structure before
	strcpy(wordStruct[numberOfUniqueWords].words, buffer);//copys the word held in buffer into the structure
    wordStruct[numberOfUniqueWords].frequency++;//increases the frequency
	return (numberOfUniqueWords+1);//increases the numberOfUniqueWords as it is a new unqioue word
}

//uses a bubble sort to sort the wordstructure from highest to lowest frequency for every word.  wordStructure array is used to hold information and use it to check sorting. numberOfUniqueWords  is used as a way of making sure that hte program is looping effectively
int sortStructure(struct wordStructure wordStruct[], int numberOfUniqueWords)
{
	for(int i=0; i < numberOfUniqueWords+1;i++)//loops for the number of Unique Words
	{
		for(int j=0; j < numberOfUniqueWords+1;j++)//loops for the number Of Unique Words
		{
			if(wordStruct[j].frequency < wordStruct[j+1].frequency)//checks if the current structures frequency is smaller than the next structures frequency
			{
				temporary = wordStruct[j];//stores the current structure in a temporary structure
				wordStruct[j]=wordStruct[j+1];// places the current structure next structure into the current structures slot
				wordStruct[j+1] = temporary;//places the temprorary structure in the next wordstructure
			}
		}			
	}
	return 0;
}