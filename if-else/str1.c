#include<stdio.h>
#include<string.h>

int count(char* s, char c){
    int i, len = strlen(s), count = 0;
    for(i = 0; i < len; i++){
        if(s[i] == c){
            count++;
        }
    }
    return count;
}

int main(){
    char str[100], ch;
    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = 0;
    printf("Enter a character to count its occurrences: ");
    scanf("%c", &ch);
    int result = count(str, ch);
    printf("The character '%c' occurs %d times in the string.\n", ch, result);
    return 0;
}

