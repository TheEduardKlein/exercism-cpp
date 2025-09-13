namespace targets {
// TODO: Insert the code for the alien class here
class Alien {

    public: 
    int x_coordinate{};
    int y_coordinate{};
    int health{3};

    Alien (int x, int y) {
        x_coordinate = x;
        y_coordinate = y;
    }

    int get_health() {
        return health;
    }

    bool hit() {
        if (health > 0) --health;
        return true;
    }

    bool is_alive() {
        if (health > 0) return true;
        return false;
    }

    bool teleport(int x_new, int y_new) {
        x_coordinate = x_new;
        y_coordinate = y_new;
        return true;
    }

    bool collision_detection(Alien other) {
        
        if (x_coordinate == other.x_coordinate && y_coordinate == other.y_coordinate)
            return true;
        return false;

    }
};
}  // namespace targets
