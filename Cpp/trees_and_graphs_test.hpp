#ifndef TEST_TREES_AND_GRAPHS_TEST_HPP
#define TEST_TREES_AND_GRAPHS_TEST_HPP

#include "trees_and_graphs.h"

using testing::IsEmpty;
using testing::StrEq;
using testing::Not;
using testing::Eq;
using testing::AnyOf;
using testing::UnorderedPointwise;

using Dependencies = std::vector<std::pair<std::string, std::string>>;

TEST(TreesAndGraphsTest, BuildOrderTest) {
    EXPECT_THAT(BuildOrder(std::vector<string>(), Dependencies()), IsEmpty());
    EXPECT_THAT(BuildOrder(std::vector<string>{"a", "b"}, Dependencies{{"b", "b"}}), IsEmpty());

    std::vector<string> projects{"a", "b", "c", "d", "e", "f"};
    Dependencies deps{{"a", "d"}, {"f", "b"}, {"b", "d"}, {"f", "a"}, {"d", "c"}};

    std::vector<string> result = BuildOrder(projects, deps);
    ASSERT_THAT(result, SizeIs(6));
    EXPECT_THAT(result.at(0), StrEq("f"));
    EXPECT_THAT(result.at(1), AnyOf(StrEq("a"), StrEq("b")));
    EXPECT_THAT(result.at(2), AnyOf(StrEq("a"), StrEq("b")));
    EXPECT_THAT(result.at(1), Not(Eq(result.at(2))));
    EXPECT_THAT(result.at(3), StrEq("d"));
    EXPECT_THAT(result.at(4), StrEq("c"));
}

#endif //TEST_TREES_AND_GRAPHS_TEST_HPP
