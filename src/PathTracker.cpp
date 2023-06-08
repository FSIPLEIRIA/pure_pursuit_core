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
        if(!this->rateSet)
            throw std::runtime_error("The rate was not set!");

        return rate;
    }

    void PathTracker::setPath(const lart_common::Path &p) {
        if(p.getFullPath().size() <= 0)
            throw std::runtime_error("A path of invalid size was given!");

        this->path = p;
        this->pathSet = true;
    }

    void PathTracker::setSpeed(double s) {
        this->speedSet = true;
        this->speed = s;
    }

    double PathTracker::getSpeed() const {
        if(!this->speedSet)
            throw std::runtime_error("The speed was not set!");

        return speed;
    }

    void PathTracker::start() {

        if(this->pointPublishingCallback == nullptr)
            throw std::runtime_error("The point publishing callback was not set!");

        // start with the first pair points to compute the midpoints
        std::pair<lart_common::Point,lart_common::Point> pointPair;

        auto pathList = this->getPath().getFullPath();
        // get a waypoint iterator
        auto pathIter = pathList.begin();

        lart_common::Point current = (*pathList.begin())->getPosition();

        bool shouldStop = false;

        do {

            // fill the pair
            pointPair.first = (*pathIter)->getPosition();
            pointPair.second = (*(++pathIter))->getPosition();

            if(pointPair.second == pathList.back()->getPosition())
                shouldStop = true;

            // compute the increment which should be applied on each tick on this pair
            std::pair<double,double> incrementVector = Math::calculateIncrementVector(pointPair, this->getSpeed(), this->getRate());

            unsigned int nTicks = (unsigned int) pointPair.first.distanceTo(pointPair.second) / this->getSpeed();

            for(unsigned int tick = 0; tick < nTicks; tick++) {

                current.setX(current.getX() + incrementVector.first);
                current.setY(current.getY() + incrementVector.second);

                // sleep for the period
                std::this_thread::sleep_for(std::chrono::milliseconds((int) ((double) 1 / this->getRate()) * 1000));

                this->pointPublishingCallback(current);
            }

            // TODO: this stop condition is broken, it will stop 1 iteration before
        } while(!shouldStop); // stop when the pair being computed ends on the path end

    }

    lart_common::Path PathTracker::getPath() const {

        if(!this->pathSet)
            throw std::runtime_error("The path was not set!");

        return path;
    }


} // path_tracker