#include "protein_translation.h"
#include <unordered_map>

using namespace std;

namespace protein_translation {

const unordered_map<string, string> translate = {

    {"AUG", "Methionine"},
    {"UUU", "Phenylalanine"}, {"UUC", "Phenylalanine"},
    {"UUA", "Leucine"}, {"UUG", "Leucine"},
    {"UCU", "Serine"}, {"UCC", "Serine"}, {"UCA", "Serine"}, {"UCG", "Serine"},
    {"UAU", "Tyrosine"}, {"UAC", "Tyrosine"},
    {"UGU", "Cysteine"}, {"UGC", "Cysteine"},
    {"UGG", "Tryptophan"},
    {"UAA", "STOP"}, {"UAG", "STOP"}, {"UGA", "STOP"}

};

vector<string> proteins (string s) {

    vector<string> proteins{};

    for (string c : protein_translation::codons(s)) {
        string next_protein = translate.at(c);
        if (next_protein == "STOP") break;
        proteins.emplace_back(next_protein);
    }

    return proteins;

}

// takes RNA string and cuts into codons (3 char strings)
vector<string> codons (string s) {

    vector<string> codons{};

    for (size_t i{0}; i < s.length(); i += 3) 
        codons.emplace_back(s.substr(i, 3));
    
    return codons;

}



}  // namespace protein_translation
