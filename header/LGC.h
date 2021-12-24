#pragma once

#include "Generator.h"

class LGC : public Generator {
private:
    const static uint32_t A = 1103515245;
    const static uint32_t C = (12345);
    const static uint32_t M = 0x80000000;

    uint32_t value;

public:
    explicit LGC(uint32_t seed) : value(seed) {}

    uint32_t nextValue() override {
        value = (value * A + C) % M;
        return value;
    }
};
