#include "muehle/muehle.h"

#include "gtest/gtest.h"

#include <vector>
#include <algorithm>

namespace
{

int test_winning_score = 2'000'000'000;

struct successor_info
{
    muehle::Muehle_Key start;
    int start_score;
    std::size_t number_of_successors;
    muehle::Muehle_Key one_successor;
    int one_successor_score;
};

std::vector<successor_info> successor_info_data {
     {
        muehle::Muehle_Key("1000000000000000000000000000000000000000000000000000000"),
        0,
        24,
        muehle::Muehle_Key("1000000000000000000000000000000000000000000000000000001"),
        10
    },
    {
        muehle::Muehle_Key("1000000000000000110001000001000100010000000010000010000"),
        20,
        16,
        muehle::Muehle_Key("1000000000000000110001000001000100010000001010000010000"),
        35
    },
    {
        muehle::Muehle_Key("1000000010100000110001100001011101010000001010010110100"),
        30,
        6,
        muehle::Muehle_Key("1000000010100000110001100001011101010000001100010110100"),
        25
    },
    {
        muehle::Muehle_Key("0000000010101000110001000001011101010101000110000110000"),
        -15,
        11,
        muehle::Muehle_Key("0000001010101000010001000001111101000101000110000110000"),
        100
    }
};

}

TEST(Muehle, test_initial_successor_constellations)
{
    for (auto sid : successor_info_data) {
        auto successors = muehle::Engine_Helper::successor_constellations(sid.start);
        EXPECT_EQ(sid.number_of_successors, successors.size());
        EXPECT_TRUE(std::find(successors.begin(), successors.end(), sid.one_successor) != successors.end()) << successors.front();
        EXPECT_EQ(sid.start_score, muehle::Engine_Helper::evaluate(sid.start, test_winning_score));
        EXPECT_EQ(sid.one_successor_score, muehle::Engine_Helper::evaluate(sid.one_successor, test_winning_score));
    }
}
