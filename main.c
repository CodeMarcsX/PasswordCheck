/**
 * PassCheck - Password Strength Checker
 */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

// Constants
#define PASSWORD_MIN_LENGTH 8
#define SPECIAL_CHARS "!@#$%&*()-_=+[]{}\\|;:'\",.<>/?`~"
#define SPECIAL_CHARS_LEN (sizeof(SPECIAL_CHARS) - 1)

// Password strength levels
#define LEVEL_WEAK 1
#define LEVEL_MEDIUM 2
#define LEVEL_STRONG 3
#define LEVEL_VERY_STRONG 4
#define LEVEL_PERFECT 5

// Character checking macros with unsigned cast to avoid undefined behavior
#define IS_UPPER(c) (isupper((unsigned char)(c)))
#define IS_LOWER(c) (islower((unsigned char)(c)))
#define IS_DIGIT(c) (isdigit((unsigned char)(c)))
#define IS_SPECIAL(c) (strchr(SPECIAL_CHARS, (c)) != NULL)

// ANSI color codes
#define BOLD    "\033[1m"
#define RESET   "\033[0m"
#define CYAN    "\033[36m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"

// Function declarations
void printBanner();
void clearScreen();
int check_password(char *password);

/**
 * Program entry point
 */
int main(void) {
    clearScreen();
    printBanner();

    char password[100];

    printf("Enter your password: ");
    scanf("%s", password);
    printf("\n");

    int level = check_password(password);

    printf("Password level is ");
    if (level <= LEVEL_WEAK)
        printf(RED BOLD "WEAK\n" RESET);

    else if (level == LEVEL_MEDIUM)
        printf(YELLOW "MEDIUM\n" RESET);

    else if (level == LEVEL_STRONG)
        printf(CYAN "STRONG\n" RESET);

    else if (level == LEVEL_VERY_STRONG)
        printf(GREEN "VERY STRONG\n" RESET);
    
    else if (level == LEVEL_PERFECT)
        printf(GREEN BOLD "PERFECT\n" RESET);

    return 0;
}

/**
 * Checks password strength based on: length, uppercase, lowercase, digits, special chars
 */
int check_password(char *password) {
    int length = strlen(password);
    int level = 0;

    bool has_upper = false;
    bool has_lower = false;
    bool has_digit = false;
    bool has_special = false;

    // Award point if password meets minimum length requirement
    if (length >= PASSWORD_MIN_LENGTH)
        level++;
    
    // Iterate through password checking for various character types
    for (int i = 0; i < length; i++) {
        unsigned char ch = (unsigned char) password[i];  // Cast to unsigned to handle negative chars

        // Check for uppercase (only once to avoid repeated points)
        if (!has_upper && IS_UPPER(ch)) {
            has_upper = true;
            level++;
        }
        // Check for lowercase (only once to avoid repeated points)
        if (!has_lower && IS_LOWER(ch)) {
            has_lower = true;
            level++;
        }
        // Check for digit (only once to avoid repeated points)
        if (!has_digit && IS_DIGIT(ch)) {
            has_digit = true;
            level++;
        }
        // Check for special character (only once to avoid repeated points)
        if (!has_special && IS_SPECIAL(ch)) {
            has_special = true;
            level++;
        }
        // Early exit optimization: stop checking once all criteria met
        if (has_upper && has_lower && has_digit && has_special)
            break;
    }

    return level;
}

/**
 * Clears the terminal screen
 */
void clearScreen(){
    // Platform-specific screen clearing using preprocessor directives
    #if defined(_WIN32)
        system("cls");
    #elif defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__)
        system("clear");
    #endif
}

/**
 * Displays colored ASCII banner
 */
void printBanner(){
    printf(GREEN BOLD
        "========================================================= \n"
        "       ____                  ______/ /             __     \n"
        "      / __ `___   __________/ ____/ /_  ___  ____ / /__   \n"
        "     / /_/ / __ `/ ___/ ___/ /   / __ `/ _ `/ ___/ //_/   \n"
        "    / ____/ /_/ (__  |__  ) /___/ / / /  __/ /__/ ,<      \n"
        "   /_/    `__,_/____/____/`____/_/ /_/`___/ ___/_/|_|     \n"
        "========================================================= \n" 
        "                      PASSWORD CHECK                      \n"
        "========================================================= \n" RESET 
    );
}