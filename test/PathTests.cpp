//
// Created by carlostojal on 27-05-2023.
//

#include <gtest/gtest.h>
#include <lart_common/Path.h>

class PathTests : public ::testing::Test {

protected:

    virtual void SetUp() {

    }

    virtual void TearDown() {

    }

};

TEST_F(PathTests, comparePaths) {

    lart_common::Path p1 = lart_common::Path();
    lart_common::Path p2 = lart_common::Path();

    std::shared_ptr<lart_common::State> s1 = std::make_shared<lart_common::State>(lart_common::Point(1.0f, 2.0f));
    std::shared_ptr<lart_common::State> s2 = std::make_shared<lart_common::State>(lart_common::Point(5.2f, 7.1f));
    std::shared_ptr<lart_common::State> s3 = std::make_shared<lart_common::State>(lart_common::Point(3.1f, 4.5f));

    s1->addNeighbor(s2);
    s2->addNeighbor(s3);

    p1.addState(s1);
    p2.addState(s1);

    p1.addState(s2);
    p2.addState(s2);

    p1.addState(s3);
    p2.addState(s3);

    std::cout << "Path 1: " << p1._str_() << std::endl;
    std::cout << "Path 2: " << p2._str_() << std::endl;

    ASSERT_EQ(p1, p2);

    s1.reset();
    s2.reset();
    s3.reset();
}