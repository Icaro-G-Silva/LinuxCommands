/* bGREP
    - The Linux's grep but its the basics only

    Returns the first occurrence of a text in a file and its equivalent line. 

    Execution instructions:
        ./grep [TEXT] [FILE]

    Output:
        if founded -> [ROW] - [TEXT]

    Example (Using Windows):
        ./grep only ../archive.log
        output: 3 - only bar
*/

#include "../headers/linuxcmd.h"

int main(int argc, char **argv){
    if(argc == 3) {
        GrepResult result = grep(argv[2], argv[1]);
        printf("%d - %s\n", result.related_Line + 1, result.token);
    }
    else printf("Parameters required: [TEXT] [FILE]\n");
    return 0;
}

GrepResult grep(char fileName[], char text[]) {
    FILE *file;
    char *occurrence;
    char buffer[LINES][MAX_BUFF_SET];
    unsigned int index = 0;
    bool founded = false;

    if((file = fopen(fileName, "r+")) != NULL) {
        while(fgets(buffer[index], MAX_BUFF_SET, file) != NULL) {
            occurrence = strstr(buffer[index], text);
            if(occurrence != NULL) {
                founded = true;
                break;
            }
            index++;
        }
        fclose(file);
    } else {
        printf("File [%s] not founded\n", fileName);
        exit(0);
    }

    GrepResult result;
    if(founded) {
        result.token = buffer[index];
        result.related_Line = index;
    } else {
        result.token = "TEXT NOT FOUNDED";
        result.related_Line = -1;
    }
    return result;
}
