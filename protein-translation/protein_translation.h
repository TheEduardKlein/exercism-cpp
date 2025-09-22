#pragma once
#include <string>
#include <vector>
#include <unordered_map>

namespace protein_translation {

extern const std::unordered_map<std::string, std::string> translate;

std::vector<std::string> proteins (std::string s);

std::vector<std::string> codons (std::string s);

}  // namespace protein_translation
