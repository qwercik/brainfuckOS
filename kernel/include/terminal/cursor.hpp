#pragma once

#include <stdint.h>

namespace bfos::terminal::cursor {
    void setPosition(uint16_t positionX, uint16_t positionY);
}