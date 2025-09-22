#include "doctor_data.h"
#include <string>


namespace heaven {


Vessel::Vessel(std::string n, int i) {
    this->name = n;
    this->generation = i;
    this->current_system = star_map::System::Sol;
}

Vessel::Vessel(std::string n, int i, star_map::System s) {
    name = n;
    generation = i;
    current_system = s;
}

Vessel Vessel::replicate(std::string s) {
    return(Vessel(s, this->generation + 1, this->current_system));
}

void Vessel::make_buster() {
    ++busters;
}

bool Vessel::shoot_buster() {
    if (busters > 0) {
        --busters;
        return true;
    }
    return false;
}

std::string get_older_bob(heaven::Vessel x, heaven::Vessel y) {
    if (x.generation < y.generation) return x.name;
    return y.name;
}

bool in_the_same_system(heaven::Vessel x, heaven::Vessel y) {
    if (x.current_system == y.current_system) return true;
    return false;
}

}


