#include "speedywagon.h"

namespace speedywagon {

// Define a function that accepts a pointer to a pillar_men_sensor struct.
// The function should return true if the sensor pointer is not null, and false otherwise.
bool connection_check(pillar_men_sensor *pms) {
    if (pms != nullptr) return true;
    return false;
}

// Define a function that accepts a pointer to the first element of an array and the arrays capacity.
// Use pointer arithmetic to loop through the sensor array and accumulate the activity readings.
// Return the accumulated activity
int activity_counter (pillar_men_sensor *pms, int cap) {
    
    int accAct{}; // Accumulated activity

    for (int i{}; i < cap; ++i) 
        accAct += (pms + i)->activity;

    return accAct;
}

bool alarm_control (pillar_men_sensor *pms) {
    if(connection_check(pms)) {
        return (pms->activity > 0);
    }
    return false;
}

bool uv_alarm (pillar_men_sensor* pms) {
    if (!connection_check(pms)) return false;

    if (uv_light_heuristic(&(pms->data)) > pms->activity) 
        return true;
    return false;

}

// Please don't change the interface of the uv_light_heuristic function
int uv_light_heuristic(std::vector<int>* data_array) {
    double avg{};
    for (auto element : *data_array) {
        avg += element;
    }
    avg /= data_array->size();
    int uv_index{};
    for (auto element : *data_array) {
        if (element > avg) ++uv_index;
    }
    return uv_index;
}

}  // namespace speedywagon
