//
// Created by carlostojal on 08-06-2023.
//

#include <path_tracker/Math.h>

namespace path_tracker {

    double Math::calculateIncrement(double distance, double speed, int rate) {

        return (distance / ((distance / speed) * rate));
    }

    std::pair<double,double> Math::calculateIncrementVector(std::pair<lart_common::Point, lart_common::Point> points,
                                                            double speed, int rate) {

        std::pair<double,double> increment;

        increment.first = calculateIncrement(points.second.getX() - points.first.getX(), speed, rate);
        increment.second = calculateIncrement(points.second.getY() - points.first.getY(), speed, rate);

        return increment;
    }

} // path_tracker