//
// Created by carlostojal on 08-06-2023.
//

#ifndef PURE_PURSUIT_CORE_MATH_H
#define PURE_PURSUIT_CORE_MATH_H

#include <lart_common/Point.h>
#include <utility>

namespace path_tracker {

    class Math {

        public:
            /*! \brief Calculate the increment to apply on each tick based on the points distance, speed and rate. */
            static double calculateIncrement(double distance, double speed, int rate);

            /*! \brief Calculate the increment vector to apply on each tick. */
            static std::pair<double,double> calculateIncrementVector(std::pair<lart_common::Point,lart_common::Point> points,
                                                                     double speed, int rate);
    };

} // path_tracker

#endif //PURE_PURSUIT_CORE_MATH_H
