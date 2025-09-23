#include "power_of_troy.h"

namespace troy {

void give_new_artifact(human& human, std::string artifact_name) {

    human.possession = std::make_unique<artifact>(artifact_name);

}

void exchange_artifacts(std::unique_ptr<artifact>& a1, std::unique_ptr<artifact>& a2) {
    a1.swap(a2);
}

void manifest_power (human& human, std::string power) {
    human.own_power = std::make_shared<troy::power>(power);
}

void use_power (human& caster, human& target) {
    target.influenced_by = caster.own_power;
}

int power_intensity(human& human) {
    return human.own_power.use_count();
}

}  // namespace troy
