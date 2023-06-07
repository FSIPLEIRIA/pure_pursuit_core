//
// Created by carlostojal on 07-06-2023.
//

#include <path_tracker/PathTracker.h>


namespace path_tracker {
    void path_tracker::PathTracker::setRate(int rate) {
        if(rate <= 0)
            throw std::runtime_error("An invalid rate was set!");

        this->rate = rate;
    }

    int PathTracker::getRate() const {
        return rate;
    }

    void PathTracker::setPath(const lart_common::Path &p) {
        if(p.getFullPath().size() <= 0)
            throw std::runtime_error("A path of invalid size was given!");

        this->path = p;
        this->pathSet = true;
    }

    void PathTracker::start() {
        if(!this->pathSet)
            throw std::runtime_error("The path was not set!");

        // TODO
    }


} // path_tracker