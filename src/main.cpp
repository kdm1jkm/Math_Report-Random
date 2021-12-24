#include <iostream>
#include <memory>

#include "../header/LGC.h"
#include "../header/MSM.h"
#include "../header/XorShift.h"

int main(int, char **) {
    std::unique_ptr<Generator> generator;

    int selection;
    std::cout << "1: LGC, 2: MSM, 3: XorShift\n" << "Input>>";
    std::cin >> selection;

    uint32_t seed;
    std::cout << "Seed>>";
    std::cin >> seed;

    int loop;
    std::cout << "How many time>>";
    std::cin >> loop;

    switch (selection) {
        case 1:
            generator = std::make_unique<LGC>(LGC(seed));
            break;

        case 2:
            generator = std::make_unique<MSM>(MSM(seed));
            break;

        case 3:
            generator = std::make_unique<XorShift>(XorShift(seed));
            break;

        default:
            return EXIT_FAILURE;
    }

    for (int i = 0; i < loop; i++) {
        std::cout << generator->nextValue() << std::endl;
    }

    return EXIT_SUCCESS;
}
