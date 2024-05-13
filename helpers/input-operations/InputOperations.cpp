#include "InputOperations.h"
number InputHelper::getValidatedInteger() {
    number num;
    while (true) {
        try {
            if (!(std::cin >> num)) {
                throw std::runtime_error("It's not correct number.");
            }
            break;
        } catch (const std::runtime_error& e) {
            std::cout << e.what() << "Please, try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return num;
}
