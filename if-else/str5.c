/* Write a function which finds the longest possible subsequence of one string into another and returns the length + pointer to the subsequence. */

#include <stdio.h>
#include <string.h>

int findLongestSubsequence(const char *s1, const char *s2, char **ptr) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int maxLen = 0;
    const char *maxPtr = NULL;
    for (int i = 0; i < len1; i++) {
        int k = 0;
        const char *startPtr = NULL;
        for (int j = 0; j < len2; j++) {
            if (s1[i + k] == s2[j]) {
                if (k == 0) {
                    startPtr = &s1[i];
                }
                k++;
                if (k > maxLen) {
                    maxLen = k;
                    maxPtr = startPtr;
                }
            } else {
                k = 0;  
            }
        }
    }
    *ptr = (char *)maxPtr;  
    return maxLen;
}

int main() {
    const char *s1 = "abcdemnopxyz";
    const char *s2 = "mnotq";
    char *ptr;
    int length = findLongestSubsequence(s1, s2, &ptr);
    if (ptr != NULL) {
        printf("Longest subsequence length: %d\n", length);
        printf("Subsequence: %.*s\n", length, ptr);
    } else {
        printf("No subsequence found.\n");
    }
    return 0;
}

