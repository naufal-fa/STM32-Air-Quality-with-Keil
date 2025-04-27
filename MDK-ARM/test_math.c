#include "unity.h"
#include "math_ops.h"  // Header fungsi yang akan di-test

void setUp(void) {}    // Optional setup
void tearDown(void) {} // Optional teardown

// Test case 1: Penambahan
void test_addition(void) {
    TEST_ASSERT_EQUAL(4, add(2, 2));  // Asumsikan ada fungsi add() di math_ops.c
}

// Test case 2: Pengurangan
void test_subtraction(void) {
    TEST_ASSERT_EQUAL(1, subtract(3, 2));
}

int main() {
    UNITY_BEGIN();
    RUN_TEST(test_addition);
    RUN_TEST(test_subtraction);
    return UNITY_END();
}