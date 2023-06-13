//
// Created by carlostojal on 08-06-2023.
//

#include <gtest/gtest.h>
#include <lart_common/Path.h>
#include <path_tracker/PathTracker.h>

class PathTrackingTests : public ::testing::Test {

};

TEST_F(PathTrackingTests, trackSimplePath) {

    lart_common::Path path;

    std::shared_ptr<lart_common::State> s1 = std::make_shared<lart_common::State>(lart_common::Point(0, 0));
    std::shared_ptr<lart_common::State> s2 = std::make_shared<lart_common::State>(lart_common::Point(-1, 2));
    std::shared_ptr<lart_common::State> s3 = std::make_shared<lart_common::State>(lart_common::Point(1, 4));

    path.addState(s1);
    s1->addNeighbor(s2);
    path.addState(s2);
    s2->addNeighbor(s3);
    path.addState(s3);

    path_tracker::PathTracker pathTracker = path_tracker::PathTracker();
    pathTracker.setSpeed(1.5);
    pathTracker.setRate(4);
    pathTracker.setPath(path);

    lart_common::Point lastPoint;
    auto pointCallback = [&lastPoint](lart_common::Point p) {
        lastPoint = p;
        std::cout << p._str_() << std::endl;
    };

    pathTracker.setPointCallback(pointCallback);

    pathTracker.start();

    ASSERT_TRUE(std::abs(lastPoint.getX() - 1) <= 1e-3 && std::abs(lastPoint.getY() - 4) <= 1e-3);

    s1.reset();
    s2.reset();
    s3.reset();
}