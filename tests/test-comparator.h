#include "../include/comparator.h"
#include <assert.h>
#include <string.h>
#include <stdio.h>

void test_compare()
{
    printf("Testing compare()...\n");

    // initialize some integers
    int integer_alpha = 10, integer_bravo = 10; // comparing two equal values
    int integer_delta = 10, integer_hotel = 20; // comparing a value less    than another
    int integer_oscar = 20, integer_romeo = 10; // comparing a value greater than another

    // initialize void pointers for the integers
    void *p_integer_alpha = &integer_alpha, *p_integer_bravo = &integer_bravo; 
    void *p_integer_delta = &integer_delta, *p_integer_hotel = &integer_hotel;
    void *p_integer_oscar = &integer_oscar, *p_integer_romeo = &integer_romeo;

    // initialize some doubles
    double double_alpha = 10.0, double_bravo = 10.0;
    double double_delta = 10.0, double_hotel = 20.0;
    double double_oscar = 20.0, double_romeo = 10.0;

    // initialize void pointers for the doubles
    void *p_double_alpha = &double_alpha, *p_double_bravo = &double_bravo; 
    void *p_double_delta = &double_delta, *p_double_hotel = &double_hotel;
    void *p_double_oscar = &double_oscar, *p_double_romeo = &double_romeo;

    // initialize some floats
    float float_alpha = 10.0, float_bravo = 10.0;
    float float_delta = 10.0, float_hotel = 20.0;
    float float_oscar = 20.0, float_romeo = 10.0;

    // initialize void pointers for the floats
    void *p_float_alpha = &float_alpha, *p_float_bravo = &float_bravo; 
    void *p_float_delta = &float_delta, *p_float_hotel = &float_hotel;
    void *p_float_oscar = &float_oscar, *p_float_romeo = &float_romeo;


    // initialize some chars
    char char_alpha = 'a', char_bravo = 'a';
    char char_delta = 'a', char_hotel = 'b';
    char char_oscar = 'b', char_romeo = 'a';

    // initialize void pointers for the chars
    void *p_char_alpha = &float_alpha, *p_char_bravo = &float_bravo; 
    void *p_char_delta = &float_delta, *p_char_hotel = &float_hotel;
    void *p_char_oscar = &float_oscar, *p_char_romeo = &float_romeo;

    // initialize some strings
    char *string_alpha = "Sunflower"; char *string_bravo = "Sunflower";
    char *string_delta = "Sunflower"; char *string_hotel = "White Orchid";
    char *string_oscar = "Sunflower"; char *string_romeo = "Lily";

    // initialize void pointers for the strings
    void *p_string_alpha = &string_alpha, *p_string_bravo = &string_bravo; 
    void *p_string_delta = &string_delta, *p_string_hotel = &string_hotel;
    void *p_string_oscar = &string_oscar, *p_string_romeo = &string_romeo;

    // unhappy paths
    assert(compare(p_integer_alpha, p_integer_bravo, NULL) == -100); // null comparator
    assert(compare(NULL, p_integer_alpha, compare_int) == -100);     // null value
    assert(compare(p_integer_alpha, NULL, compare_int) == -100);     // null value

    // happy paths
    assert(compare(p_integer_alpha, p_integer_bravo, compare_int) == 0);
    assert(compare(p_integer_oscar, p_integer_romeo, compare_int) == 1);
    assert(compare(p_integer_delta, p_integer_hotel, compare_int) == -1);

    assert(compare(p_double_alpha, p_double_bravo, compare_double) == 0);
    assert(compare(p_double_oscar, p_double_romeo, compare_double) == 1);
    assert(compare(p_double_delta, p_double_hotel, compare_double) == -1);

    assert(compare(p_float_alpha, p_float_bravo, compare_float) == 0);
    assert(compare(p_float_oscar, p_float_romeo, compare_float) == 1);
    assert(compare(p_float_delta, p_float_hotel, compare_float) == -1);

    assert(compare(p_char_alpha, p_char_bravo, compare_float) == 0);
    assert(compare(p_char_oscar, p_char_romeo, compare_float) == 1);
    assert(compare(p_char_delta, p_char_hotel, compare_float) == -1);

    assert(compare(p_string_alpha, p_string_bravo, compare_string) == 0);
    assert(compare(p_string_oscar, p_string_romeo, compare_string) == 1);
    assert(compare(p_string_delta, p_string_hotel, compare_string) == -1);


    printf("Testing successful...");
}



void test_comparator()
{
    test_compare();
}