#pragma once

#include <cstdint>

class Generator {
public:
    virtual uint32_t nextValue() = 0;
};
