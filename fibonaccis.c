#include "c_std.h"
#include <stdio.h>

static void push_string(vector_t(string_t) * vec, string_t str) { vec_move_back(*vec, str); }

int main(void) {
    vector_t(string_t) fibonaccis = vec_new();
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
    push_string(&fibonaccis, str_new("Six thousand seven hundred sixty-five"));

    printf("The first 20 fibonacci numbers are:\n");
    for (size_t i = 0; i < vec_size(fibonaccis); ++i) {
        printf("  - #%zu: %s\n", i + 1, fibonaccis[i]);
        str_delete(fibonaccis[i]);
    }
    vec_delete(fibonaccis);
}
