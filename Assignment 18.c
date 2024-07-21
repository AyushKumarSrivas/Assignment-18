String and Functions in C Language

1. Write a function to calculate length of the string
2. Write a function to reverse a string.
3. Write a function to compare two strings.
4. Write a function to transform string into uppercase
5. Write a function to transform a string into lowercase
6. Write a function to check whether a given string is an alphanumeric string or not.
(Alphanumeric string must contain at least one alphabet and one digit)
7. Write a function to check whether a given string is palindrome or not.
8. Write a function to count words in a given string
9. Write a function to reverse a string word wise. (For example if the given string is
“Mysirg Education Services” then the resulting string should be “Services Education
Mysirg” )
10. Write a function to find the repeated character in a given string.

Solution:-

1. #include <stdio.h>

int stringLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    gets(str);
    
    printf("The length of the string is: %d\n", stringLength(str));
    
    return 0;
}

2. #include <stdio.h>

void reverseString(char str[]) {
    int length = stringLength(str);
    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}

int stringLength(char str[]) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    gets(str);
    
    reverseString(str);
    
    printf("The reversed string is: %s\n", str);
    
    return 0;
}

3. #include <stdio.h>

int compareStrings(char str1[], char str2[]) {
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return str1[i] - str2[i];
        }
        i++;
    }
    return str1[i] - str2[i];
}

int main() {
    char str1[100], str2[100];
    
    printf("Enter first string: ");
    gets(str1);
    
    printf("Enter second string: ");
    gets(str2);
    
    int result = compareStrings(str1, str2);
    
    if (result == 0) {
        printf("The strings are equal.\n");
    } else if (result > 0) {
        printf("The first string is greater.\n");
    } else {
        printf("The second string is greater.\n");
    }
    
    return 0;
}

4. #include <stdio.h>

void toUpperCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    gets(str);
    
    toUpperCase(str);
    
    printf("The string in uppercase is: %s\n", str);
    
    return 0;
}

5. #include <stdio.h>

void toLowerCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32;
        }
    }
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    gets(str);
    
    toLowerCase(str);
    
    printf("The string in lowercase is: %s\n", str);
    
    return 0;
}

6. #include <stdio.h>

int isAlphanumeric(char str[]) {
    int hasAlpha = 0, hasDigit = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            hasAlpha = 1;
        } else if (str[i] >= '0' && str[i] <= '9') {
            hasDigit = 1;
        }
        if (hasAlpha && hasDigit) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    gets(str);
    
    if (isAlphanumeric(str)) {
        printf("The string is alphanumeric.\n");
    } else {
        printf("The string is not alphanumeric.\n");
    }
    
    return 0;
}

7. #include <stdio.h>
#include <string.h>

int isPalindrome(char str[]) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    gets(str);
    
    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
    
    return 0;
}

8. #include <stdio.h>
#include <ctype.h>

int countWords(char str[]) {
    int count = 0, inWord = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isspace(str[i])) {
            inWord = 0;
        } else if (!inWord) {
            inWord = 1;
            count++;
        }
    }
    return count;
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    gets(str);
    
    printf("The number of words in the string is: %d\n", countWords(str));
    
    return 0;
}

9. #include <stdio.h>
#include <string.h>

void reverseWords(char str[]) {
    int length = strlen(str);
    int start = 0, end = 0;

    while (end < length) {
        while (end < length && str[end] != ' ') {
            end++;
        }
        int wordEnd = end - 1;
        while (start < wordEnd) {
            char temp = str[start];
            str[start] = str[wordEnd];
            str[wordEnd] = temp;
            start++;
            wordEnd--;
        }
        end++;
        start = end;
    }

    for (int i = 0; i < length / 2; i++) {
        char temp = str[i];
        str[i] = str[length - 1 - i];
        str[length - 1 - i] = temp;
    }
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    gets(str);
    
    reverseWords(str);
    
    printf("The string with words reversed is: %s\n", str);
    
    return 0;
}

10. #include <stdio.h>
#include <string.h>

void findRepeatedCharacters(char str[]) {
    int freq[256] = {0};
    int length = strlen(str);

    for (int i = 0; i < length; i++) {
        freq[(unsigned char)str[i]]++;
    }

    printf("Repeated characters are:\n");
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 1) {
            printf("%c: %d times\n", i, freq[i]);
        }
    }
}

int main() {
    char str[100];
    
    printf("Enter a string: ");
    gets(str);
    
    findRepeatedCharacters(str);
    
    return 0;
}
