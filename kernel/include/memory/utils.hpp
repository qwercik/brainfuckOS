#include <stdint.h>

namespace bfos::memory::utils {
    template <typename T>
    void copy(T *source, T *destination, unsigned count) {
        for (unsigned i = 0; i < count; ++i) {
            destination[i] = source[i];
        }
    }

    template <typename T>
    void set(T *destination, T value, unsigned count) {
        for (unsigned i = 0; i < count; ++i) {
            destination[i] = value;
        }
    }
}