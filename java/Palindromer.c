#include <stdio.h>
#include <assert.h>

char *find_first_palindrom(char *input) {
    char *start, *end, *last;
    int found = 0;
    if (input == NULL || *input == '\0') return NULL;
    while (!isalpha(*input) && *input != '\0') input++;
    start = input;
    last = start;
    while (isalpha(*last)) last++;
    end = last - 1;

    while (start <= end) {
        found = 1;
        if (*start != *end) {
            found = 0;
            break;
        }
        start++;
        end--;
    }
    return found ? input : find_first_palindrom(last);
}

int main() {
    char *test_str1 = "Hello mom and dad, how is it going?";
    char *test_str2 = "  This is  $ my TEST$$ case.  bob!";
    char *test_str3 = "##dd# test bb, hello world! Nice to meet you!";
    int i;
    char *result;

    char* test_cases[][2] = {
        {"ab", NULL},
        {test_str1, test_str1 + 6},
        {test_str1 + 3, test_str1 + 6},
        {test_str1 + 5, test_str1 + 6},
        {test_str1 + 6, test_str1 + 6},
        {test_str1 + 7, test_str1 + 14},
        {test_str1 + 14, test_str1 + 14},
        {test_str1 + 15, NULL},
        {test_str1 + 20, NULL},
        {test_str2, test_str2 + 30},
        {test_str2 + 3, test_str2 + 30},
        {test_str2 + 7, test_str2 + 30},
        {test_str2 + 21, test_str2 + 30},
        {test_str2 + 31, NULL},
        {test_str3, test_str3 + 2},
        {test_str3 + 4, test_str3 + 11},
        {test_str3 + 10, test_str3 + 11},
        {test_str3 + 14, NULL},
        {test_str3 + 20, NULL},
        {test_str3 + 29, NULL},
        {test_str3 + 40, NULL},
        {NULL, NULL},
    };

    for (i = 0; test_cases[i][0] != NULL; i++) {
        result = find_first_palindrom(test_cases[i][0]);
        printf("asdf: %s -> %s\n", test_cases[i][1], result);
        assert (result == test_cases[i][1]);
    }

    return 0;
}
