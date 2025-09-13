#include <string>

namespace log_line {
std::string message(std::string line) {
    // return the message (skip first 11 characters)
    return line.substr(static_cast<int>(line.find(":") + 2));
}

std::string log_level(std::string line) {
    // return the log level
    int i2 {static_cast<int>(line.find("]") - 1)};
    return line.substr(1, i2);
}

std::string reformat(std::string line) {
    // return the reformatted message
    return message(line) + " (" + log_level(line) + ")";
}
}  // namespace log_line
