#pragma once

#include "Generator.h"

class XorShift : public Generator {
private:
    uint32_t value;

public:
    explicit XorShift(uint32_t seed) : value(seed) {}

    uint32_t nextValue() override {
        value ^= value << 13;
        value ^= value >> 17;
        value ^= value << 5;

        return value;
    }
};