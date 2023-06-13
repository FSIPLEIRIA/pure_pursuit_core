//
// Created by carlostojal on 07-06-2023.
//

#ifndef PURE_PURSUIT_CORE_PATHTRACKER_H
#define PURE_PURSUIT_CORE_PATHTRACKER_H

#include <lart_common/Point.h>
#include <lart_common/Path.h>
#include <path_tracker/Math.h>
#include <functional>
#include <thread>

namespace path_tracker {

    /*! \brief Main path tracker class. Calls a callback function at a set rate. */
    class PathTracker {

        private:
            /*! \brief Point publishing rate in Hz. */
            int rate;

            /*! \brief Was the rate already set? */
            bool rateSet;

            /*! \brief Callback function called on each tick. */
            std::function<void(lart_common::Point)> pointPublishingCallback = nullptr;

            /*! \brief The path to track. */
            lart_common::Path path;

            /*! \brief Was the path already set? */
            bool pathSet = false;

            /*! \brief Speed at which to track the trajectory in m/s. */
            double speed;

            /*! \brief Was the speed already set? */
            bool speedSet = false;

        public:
            /*! \brief Set the publishing rate in Hz. */
            void setRate(int rate);

            /*! \brief Get the set publishing rate. */
            int getRate() const;

            /*! \brief Set the callback function to call whenever a point is published. */
            void setPointCallback(const std::function<void(lart_common::Point)>& cb);

            /*! \brief Set the path to track. */
            void setPath(const lart_common::Path& p);

            /*! \brief Get the path being tracked. */
            lart_common::Path getPath() const;

            /*! \brief Set the tracking speed. */
            void setSpeed(double s);

            /*! \brief Get the set tracking speed. */
            double getSpeed() const;

            /*! \brief Start the path tracking. */
            void start();
    };
} // path_tracker

#endif //PURE_PURSUIT_CORE_PATHTRACKER_H
