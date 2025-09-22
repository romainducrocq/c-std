#define C_STD_INCLUDE_ALL
#define C_STD_THROW_MESSAGE
#include "c_std.h"

static void push_string(vector_t(string_t) * vec, string_t str) { vec_move_back(*vec, str); }

static error_t print_fibonacci(const vector_t(string_t) fibonaccis) {
    CATCH_ENTER;
    printf("The first %zu fibonacci numbers are:\n", vec_size(fibonaccis));
    for (size_t i = 0; i < vec_size(fibonaccis); ++i) {
        if (!str_size(fibonaccis[i])) {
            THROW_MESSAGE(1, "... oops i don't know the #%zuth number!", i + 1);
        }
        printf("  - #%zu: %s\n", i + 1, fibonaccis[i]);
    }
    FINALLY;
    CATCH_EXIT;
}

error_t main(int argc, char** argv) {
    if (argc > 1) {
        // showcasing panic
        if (!strcmp(argv[1], "--panic-abort")) {
            THROW_ABORT;
        }
        else if (!strcmp(argv[1], "--panic-alloc")) {
            THROW_ALLOC(char**);
        }
    }

    // start example
    vector_t(string_t) fibonaccis = vec_new();

    CATCH_ENTER;
    vec_reserve(fibonaccis, 20);

    push_string(&fibonaccis, str_new("One"));
    push_string(&fibonaccis, str_new("One"));
    push_string(&fibonaccis, str_new("Two"));
    push_string(&fibonaccis, str_new("Three"));
    push_string(&fibonaccis, str_new("Five"));
    push_string(&fibonaccis, str_new("Eight"));
    push_string(&fibonaccis, str_new("Thirteen"));
    push_string(&fibonaccis, str_new("Twenty-one"));
    push_string(&fibonaccis, str_new("Thirty-four"));
    push_string(&fibonaccis, str_new("Fifty-five"));
    push_string(&fibonaccis, str_new("Eighty-nine"));
    push_string(&fibonaccis, str_new("One hundred forty-four"));
    push_string(&fibonaccis, str_new("Two hundred thirty-three"));
    push_string(&fibonaccis, str_new("Three hundred seventy-seven"));
    push_string(&fibonaccis, str_new("Six hundred ten"));
    push_string(&fibonaccis, str_new("Nine hundred eighty-seven"));
    push_string(&fibonaccis, str_new("One thousand five hundred ninety-seven"));
    push_string(&fibonaccis, str_new("Two thousand five hundred eighty-four"));
    push_string(&fibonaccis, str_new("Four thousand one hundred eighty-one"));
    push_string(&fibonaccis, str_new(""));

    TRY(print_fibonacci(fibonaccis));

    FINALLY;
    for (size_t i = 0; i < vec_size(fibonaccis); ++i) {
        str_delete(fibonaccis[i]);
    }
    vec_delete(fibonaccis);
    CATCH_EXIT;
}
