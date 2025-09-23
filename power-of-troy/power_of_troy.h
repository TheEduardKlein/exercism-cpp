#pragma once

#include <string>
#include <memory>

namespace troy {

struct artifact {
    // constructors needed (until C++20)
    artifact(std::string name) : name(name) {}
    std::string name;
};

struct power {
    // constructors needed (until C++20)
    power(std::string effect) : effect(effect) {}
    std::string effect;
};

struct human {

    // human(std::unique_ptr<artifact> pos, std::shared_ptr<power> own, std::shared_ptr<power> infl)
    // : possession(std::move(pos)), own_power(std::move(own)), influenced_by(std::move(infl)) {}

    std::unique_ptr<artifact>   possession = nullptr;
    std::shared_ptr<power>      own_power = nullptr;
    std::shared_ptr<power>      influenced_by = nullptr;   
    
};

void give_new_artifact(human& human, std::string artifact_name);

void exchange_artifacts(std::unique_ptr<artifact>& a1, std::unique_ptr<artifact>& a2);

void manifest_power (human& human, std::string power);

void use_power (human& caster, human& target);

int power_intensity(human& human);

}  // namespace troy
