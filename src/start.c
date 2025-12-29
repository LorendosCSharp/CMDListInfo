#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc>2||argc<2){
        printf("You have started the programm with insufficient count of arguments (2)!");
        return EXIT_FAILURE;
    }

    FILE *text;
    int c,prevC, countChars=0,countLines=1,countWhitespaces=0,countWords=0;
    text = fopen(argv[1],"r");

    while((c=fgetc(text))!=EOF){

        if(c!='\n'){
            countChars++;
        }

        if(c=='\n'){
            countLines++;
            countChars--;
            countWords++;
        }
        
        if(c=='\t'||c=='\v'||c=='\f'||c==' '){
            countWhitespaces++;
        }

        if(c==' '&&prevC!=' '){

            countWords++;
        }
        prevC=c;
    }
    
    if(countChars>0){
        countWords++;
    }
    fclose(text);

    printf("Characters Count: %d\n",countChars);
    printf("Lines Count: %d\n",countLines);
    printf("Whitespaces Count: %d\n",countWhitespaces);
    printf("Words Count: %d\n",countWords);

    return EXIT_SUCCESS;
}

