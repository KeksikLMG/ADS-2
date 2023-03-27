// Copyright 2022 NNTU-CS
#include "alg.h"
#include <cstdint>
double pown(double value, uint16_t n) {
    double answer = 1;
    if (value == -1) {
        if (n % 2 == 0)
            return 1;
        else
            return -1;
    }
    for (uint16_t i = 1; i <= n; ++i)
        answer *= value;
    return answer;
}
uint64_t fact(uint16_t n) {
    uint64_t answer = 1;
    for (uint16_t i = 2; i <= n; ++i)
        answer *= i;
    return answer;
}
double calcItem(double x, uint16_t n) {
    return pown(x, n) / fact(n);
}
double expn(double x, uint16_t count) {
    double answer = 0;
    for (uint16_t n = 0; n <= count; ++n)
        answer += calcItem(x, n);
    return answer;
}
double sinn(double x, uint16_t count) {
    double answer = 0;
    for (uint16_t n = 1; n <= count; ++n)
        answer += calcItem(x, 2 * n - 1) * pown(-1, n - 1);
    return answer;
}
double cosn(double x, uint16_t count) {
    double answer = 1.0;
    for (uint16_t n = 2; n <= count; ++n)
        answer += calcItem(x, 2 * n - 2) * pown(-1, n - 1);
    return answer;
}
