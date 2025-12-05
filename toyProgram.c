#include <stdio.h>
#include <string.h>

int verify_key(const char *key) {
    const char *correct_key = "CYRNE-CSTRC-EVER9-HYCNE";

    // Simple, obvious comparison. No tricks.
    if (strcmp(key, correct_key) == 0) {
        return 1; // correct
    } else {
        return 0; // incorrect
    }
}

int main(void) {
    char input[128];
    int attempts = 3;

    puts("===================================");
    puts("        Simple Crackme v0.1        ");
    puts("   (no anti-RE, baseline build)    ");
    puts("===================================\n");

    while (attempts > 0) {
        printf("Enter license key: ");

        if (!fgets(input, sizeof(input), stdin)) {
            // Input error
            return 1;
        }

        // Strip trailing newline, if present
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        if (verify_key(input)) {
            puts("\n[+] Access granted.");
            return 0;
        } else {
            attempts--;
            printf("[-] Wrong key. Attempts left: %d\n\n", attempts);
        }
    }

    puts("[-] Too many failures. Exiting.");
    return 1;
}
