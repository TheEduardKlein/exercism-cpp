#include <string>
#pragma once

namespace star_map {

    enum System {
        BetaHydri,
        EpsilonEridani,
        DeltaEridani,
        AlphaCentauri,
        Sol,
        Omicron2Eridani
    };

}

namespace heaven {

    class Vessel {

        public:
            star_map::System current_system{};
            int generation{};
            int busters{};
            std::string name{};

            Vessel(std::string s, int i);
            Vessel(std::string s, int i, star_map::System);
            
            heaven::Vessel replicate(std::string s);

            void make_buster();
            bool shoot_buster();

            
    };

    std::string get_older_bob(heaven::Vessel x, heaven::Vessel y);

    bool in_the_same_system(heaven::Vessel x, heaven::Vessel y);
}


