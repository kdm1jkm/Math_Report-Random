#pragma once

#include "Generator.h"

class MSM : public Generator {
private:
    uint32_t value;
    const int originalLength;

    static int calcNumLength(uint32_t num) {
        int count = 0;
        while (num != 0) {
            num /= 10;
            count += 1;
        }
        return count;
    }

    static uint32_t pow(uint32_t base, uint32_t exponent) {
        uint32_t result = 1;
        for (uint32_t i = 0; i < exponent; i++) {
            result *= base;
        }

        return result;
    }

public:
    explicit MSM(uint32_t seed) : value(seed), originalLength(calcNumLength(seed)) {}

    uint32_t nextValue() override {
        value *= value;
        int remainLength = calcNumLength(value) - originalLength;
        if (remainLength < 0) return value;

        value /= pow(10, remainLength / 2);
        value %= pow(10, originalLength);

        return value;
    }
};
