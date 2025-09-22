#pragma once

#include <string>

namespace rotational_cipher {

std::string rotate(std::string text, int k);

void shift (char& c, int k);

}  // namespace rotational_cipher
