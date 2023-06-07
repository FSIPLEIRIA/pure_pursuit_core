//
// Created by carlostojal on 07-06-2023.
//

#ifndef PURE_PURSUIT_CORE_PATHTRACKER_H
#define PURE_PURSUIT_CORE_PATHTRACKER_H

#include <lart_common/Point.h>
#include <lart_common/Path.h>
#include <functional>

namespace path_tracker {

    /*! \brief Main path tracker class. Calls a callback function at a set rate. */
    class PathTracker {

        private:
            /*! \brief Point publishing rate in Hz. */
            int rate;

            /*! \brief Callback function called on each tick. */
            std::function<void(lart_common::Point)> pointPublishingCallback = nullptr;

            /*! \brief The path to track. */
            lart_common::Path path;

            bool pathSet = false;

        public:
            /*! \brief Set the publishing rate in Hz. */
            void setRate(int rate);

            /*! \brief Get the set publishing rate. */
            int getRate() const;

            /*! \brief Set the path to track. */
            void setPath(const lart_common::Path& p);

            /*! \brief Start the path tracking. */
            void start();
    };
} // path_tracker

#endif //PURE_PURSUIT_CORE_PATHTRACKER_H
