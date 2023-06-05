//
// Created by carlostojal on 27/04/2023.
//

#include <lart_common/State.h>

namespace lart_common {

    State::State() {
        this->position = lart_common::Point();
        this->neighbors = std::set<std::shared_ptr<lart_common::State>>();
    }

    State::State(const State &other) : State() {
        this->position = other.position;
    }

    State::State(const Point &point) : State() {
        this->position = point;
    }

    State::~State() {
        for(std::shared_ptr<State> n : neighbors)
            n.reset();
    }

    lart_common::Point State::getPosition() const {
        return this->position;
    }

    void State::setPosition(lart_common::Point position) {
        this->position = position;
    }

    bool State::hasNeighbor(std::shared_ptr<lart_common::State> neighbor) {
        return this->neighbors.count(neighbor) > 0;
    }

    void State::addNeighbor(std::shared_ptr<lart_common::State> neighbor) {
        if(neighbor == nullptr)
            throw std::runtime_error("Tried to add a null neighbor!");

        this->neighbors.insert(neighbor);
    }

    void State::removeNeighbor(std::shared_ptr<lart_common::State> neighbor) {
        if(!this->hasNeighbor(neighbor))
            throw std::runtime_error("Tried to remove a state which is not a neighbor!");

        this->neighbors.erase(neighbor);
    }

    std::set<std::shared_ptr<State>> State::getNeighbors() const {
        return this->neighbors;
    }

    std::shared_ptr<lart_common::State> State::createIntermediate(std::shared_ptr<lart_common::State> neighbor) {
        // verify the state is a neighbor
        if(!this->hasNeighbor(neighbor))
            throw std::runtime_error("State is not a neighbor!");

        // compute the new point
        lart_common::Point newPoint((this->position.getX() + neighbor->position.getX()) / 2,
                                     (this->position.getY() + neighbor->position.getY()) / 2);

        // create the new state
        std::shared_ptr<lart_common::State> newState = std::make_shared<lart_common::State>(newPoint);

        this->neighbors.insert(newState);

        return newState;
    }

    occupancy_type_t State::getOccupancy() const {
        return this->occupancy;
    }

    void State::setOccupancy(occupancy_type_t occupancy) {
        this->occupancy = occupancy;
    }

    bool State::operator==(const State& other) const {
        return this->position == other.position;
    }

    std::shared_ptr<lart_common::State> State::getClosestBlueCone() {

        return std::shared_ptr<lart_common::State>();
    }

    std::shared_ptr<lart_common::State> State::getClosestYellowCone() {
        return std::shared_ptr<lart_common::State>();
    }

    cone_color_t State::occupancyTypeToConeColor(occupancy_type_t o) {

        if(o == YELLOW_CONE_OCCUPANCY)
            return YELLOW;
        else if(o == BLUE_CONE_OCCUPANCY)
            return BLUE;
        else if(o == ORANGE_CONE_OCCUPANCY)
            return ORANGE;
        else
            return UNKNOWN;
    }

} // lart_common