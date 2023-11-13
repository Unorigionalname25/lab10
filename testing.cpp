#include <gtest/gtest.h>
#include "pokerHand.h"



TEST(TestingSuite, straightVSfourofakind) {
    EXPECT_EQ(bestPokerHand("2H 3H 4H 5H 6H", "2C 2H 2S 2D KD"), "Player two wins");
}

TEST(TestingSuite, StraightFlushVsFour) {
    EXPECT_EQ(bestPokerHand("10H JH QH KH AH", "2C 2H 2S 2D KD"), "Player one wins");
}

TEST(TestingSuite, FourOfAKindVsFullHouse) {
    EXPECT_EQ(bestPokerHand("2H 2D 2S 2C 3H", "3D 3S 4D 4S 4C"), "Player one wins");
}

TEST(TestingSuite, FlushVsStraight) {
    EXPECT_EQ(bestPokerHand("2H 4H 6H 8H 10H", "9D 10S JC QS KD"), "Player one wins");
}

TEST(TestingSuite, PairVsHighCard) {
    EXPECT_EQ(bestPokerHand("5H 5D 8S 10C KH", "2D 3H 4S 7D AD"), "Player one wins");
}

TEST(TestingSuite, StraightVsThreeOfAKind) {
    EXPECT_EQ(bestPokerHand("2H 3D 4S 5C 6H", "7D 7S 7C 8D 9D"), "Player two wins");
}

TEST(TestingSuite, TwoPairsVsFlush) {
    EXPECT_EQ(bestPokerHand("3H 3D 7S 7C 9H", "2D 4D 6D 8D KD"), "Player two wins");
}

TEST(TestingSuite, FullHouseVsStraightFlush) {
    EXPECT_EQ(bestPokerHand("8H 8D 8S 9C 9H", "10D JD QD KD AD"), "Player two wins");
}

TEST(TestingSuite, HighCardVsPair_2) {
    EXPECT_EQ(bestPokerHand("2H 6D 7S 9C KH", "7D 7H 10S JC QS"), "Player two wins");
}

TEST(TestingSuite, ThreeOfAKindVsHighCard) {
    EXPECT_EQ(bestPokerHand("4H 4D 4S 5C 8H", "2D 6H 10S JD QS"), "Player one wins");
}
