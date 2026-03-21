/*
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STR 256

char * loadStory(){
    char buffer[ MAX_STR ];
    int strlength;
    FILE * fptr = NULL;
    char * story = NULL;

    fptr = fopen( "story.txt", "r" );
    if( fptr == NULL ){
        printf( "ERROR:\tUnable to read file '%s'\n", "story.txt" );
        exit( EXIT_FAILURE );
    }

    story = ( char * )malloc( sizeof( char ) );

    while( fgets( buffer, MAX_STR, fptr ) != NULL ){
        strlength += strlen( buffer );
        story = realloc( story, strlength );
        strcat( story, buffer );
    }

    fclose( fptr );
    return story;
}

void modifyStory( char * story, const char * target, const char * replacement ){
    FILE * fptr = NULL;
    char * token = NULL;

    fptr = fopen( "new_story.txt", "w" );
    if( fptr == NULL ){
        printf( "ERROR:\tUnable to open file '%s'\n", "new_story.txt" );
        exit( EXIT_FAILURE );
    }

    token = strtok( story, " .,!?" );
    while( token != NULL ){
        if( strcmp( token, target ) == 0 ){
            fprintf( fptr, "%s ", replacement );
        }
        else{
            fprintf( fptr, "%s ", token );
        }
        token = strtok(NULL, " .,!?" );
    }

    fclose( fptr );
}

int main(){
    char * story = loadStory();
    char target_word[ 32 ];
    char replacement_word[ 32 ];

    printf( "Original Story: \n%s\n", story );
    printf( "Enter target word: " );
    fgets( target_word, 32, stdin );
    printf( "Enter replacement word: " );
    fgets( replacement_word, 32, stdin );

    modifyStory( story, target_word, replacement_word );
    printf( "Successfully modified the story. Please check 'new_story.txt'.\n" );
    free( story );
    return 0;
}
*/

// CHATGPT

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_STR 256

/* Load entire story.txt into a dynamically allocated string */
char *loadStory(void) {
    FILE *fptr = fopen("story.txt", "r");
    if (!fptr) {
        perror("ERROR opening story.txt");
        exit(EXIT_FAILURE);
    }

    char buffer[MAX_STR];
    size_t length = 0;
    char *story = malloc(1);

    if (!story) {
        fclose(fptr);
        exit(EXIT_FAILURE);
    }

    story[0] = '\0';

    while (fgets(buffer, MAX_STR, fptr)) {
        size_t buf_len = strlen(buffer);
        char *temp = realloc(story, length + buf_len + 1);

        if (!temp) {
            free(story);
            fclose(fptr);
            exit(EXIT_FAILURE);
        }

        story = temp;
        memcpy(story + length, buffer, buf_len + 1);
        length += buf_len;
    }

    fclose(fptr);
    return story;
}

/* Replace target word with replacement word while preserving punctuation */
void modifyStory(const char *story,
                 const char *target,
                 const char *replacement) {

    FILE *fptr = fopen("new_story.txt", "w");
    if (!fptr) {
        perror("ERROR opening new_story.txt");
        exit(EXIT_FAILURE);
    }

    char word[128];
    int i = 0;

    while (*story) {
        if (isalnum((unsigned char)*story)) {
            i = 0;

            /* Extract word */
            while (*story && isalnum((unsigned char)*story)) {
                word[i++] = *story++;
            }
            word[i] = '\0';

            if (strcmp(word, target) == 0) {
                fputs(replacement, fptr);
            } else {
                fputs(word, fptr);
            }
        } else {
            /* Copy punctuation/whitespace */
            fputc(*story++, fptr);
        }
    }

    fclose(fptr);
}

int main(void) {
    char *story = loadStory();

    char target[64];
    char replacement[64];

    printf("Original Story:\n%s\n", story);

    printf("Enter target word: ");
    fgets(target, sizeof(target), stdin);
    target[strcspn(target, "\n")] = '\0';

    printf("Enter replacement word: ");
    fgets(replacement, sizeof(replacement), stdin);
    replacement[strcspn(replacement, "\n")] = '\0';

    modifyStory(story, target, replacement);

    printf("\nStory successfully modified.\n");
    printf("Check 'new_story.txt'.\n");

    free(story);
    return 0;
}
