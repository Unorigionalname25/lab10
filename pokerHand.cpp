#include "pokerHand.h"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <map>
#include <algorithm>

std::vector<std::pair<int, char>> parseCards(std::string p1){

    std::vector<std::pair<int, char>> pokerHand;
    std::istringstream iss(p1);

    
    std::map<char, int> valueMapping = {
        {'2', 2}, {'3', 3}, {'4', 4}, {'5', 5},
        {'6', 6}, {'7', 7}, {'8', 8}, {'9', 9},
        {'T', 10}, {'J', 11}, {'Q', 12}, {'K', 13}, {'A', 14}
    };


    std::string token;

    while (std::getline(iss,token,' ')) {

        // Extract the card value and suit
        char value = token[0];
        char suit = token[1];

        // Convert the card value to an integer using the mapping
        int intValue = valueMapping[value];

        pokerHand.push_back(std::make_pair(intValue, suit));
    }

    for (const auto &card : pokerHand) {
        std::cout << "Value: " << card.first << ", Suit: " << card.second << std::endl;
    }


    std::cout<<p1<<std::endl;

    return pokerHand;
}

int isStraightFlush(std::vector<std::pair<int, char>> hand){
    bool isconsecutive = true;
    bool issuit = true;
    std::vector<int> sortedNumbers;
    for (auto &card : hand){
        sortedNumbers.push_back(card.first);
    }
    std::sort(sortedNumbers.begin(),sortedNumbers.end());
    for (size_t i = 1; i < sortedNumbers.size(); ++i) {
        if (sortedNumbers[i] != sortedNumbers[i - 1] + 1) {
            isconsecutive = false;
        }
    }
    char firstSuit = hand[0].second;
    for (auto &card: hand){
        if (card.second != firstSuit){
            issuit = false;
        }
    }
    if (isconsecutive&&issuit){
        return 1;
    }

    return 0;

}

int fourOfAkind(const std::vector<std::pair<int, char>>& hand) {
    std::map<int, int> valueCount;  

    for (const auto& card : hand) {
        valueCount[card.first]++;
    }

    // Check if there is any value with a count of 4
    for (const auto& pair : valueCount) {
        if (pair.second == 4) {
            return pair.first;  // Four of a kind found
        }
    }

    return 0;  // No four of a kind found
}

int isFullHouse(const std::vector<std::pair<int, char>>& hand){
    std::map<int, int> valueCount;  
    int valueOfPair=0;


 
    for (const auto& card : hand) {
        valueCount[card.first]++;
    }

    bool threeOfAKind = false;
    bool ispair = false;

    for (const auto& pair : valueCount) {
        if (pair.second == 3) {
            threeOfAKind = true;
            valueOfPair = pair.first;

        } else if (pair.second == 2) {
            ispair = true;
        }
    }
if(threeOfAKind&&ispair){
    return valueOfPair;

}
else{
    return 0;

    }
}

int isflush(const std::vector<std::pair<int, char>> hand) {
    char suit = hand[0].second;  // Assume the first card's suit as the reference
    int highestValue = 0;

    // Check if all cards have the same suit
    for (const auto& card : hand) {
        if (card.second != suit) {
            return 0;  // If any card has a different suit, it's not a flush
        }

        // Update the highest value if the current card's value is higher
        if (card.first > highestValue) {
            highestValue = card.first;
        }
    }

    return highestValue;  // All cards have the same suit, return the highest card value
}
int isStraight(const std::vector<std::pair<int, char>> hand){
    std::vector<int> sortedNumbers;
    bool isconsecutive = true;
    for (auto &card : hand){
        sortedNumbers.push_back(card.first);
    }
    std::sort(sortedNumbers.begin(),sortedNumbers.end());
    for (size_t i = 1; i < sortedNumbers.size(); ++i) {
        if (sortedNumbers[i] != sortedNumbers[i - 1] + 1) {
            isconsecutive = false;
        }
    }
    if (isconsecutive){
        return sortedNumbers[sortedNumbers.size()-1];
    }
    return 0;
}

int isThreeOfKind(const std::vector<std::pair<int, char>> hand){
    std::map<int, int> valueCount;  
    for (const auto& card : hand) {
        valueCount[card.first]++;
    }

    // Check if there is any value with a count of 3
    for (const auto& pair : valueCount) {
        if (pair.second == 3) {
            return pair.first;  // three of a kind found
        }
    }

    return 0;  // No three of a kind found
}

int isTwoPair(const std::vector<std::pair<int, char>>& hand) {
    std::map<int, int> valueCount;
    int higherValueOfPair = 0;

    for (const auto& card : hand) {
        valueCount[card.first]++;
    }

    bool isPair1 = false;
    bool isPair2 = false;

    for (const auto& pair : valueCount) {
        if (pair.second == 2) {
            if (!isPair1) {
                isPair1 = true;
                higherValueOfPair = pair.first;
            } else {
                isPair2 = true;
                higherValueOfPair = std::max(higherValueOfPair, pair.first);
            }
        }
    }

    if (isPair1 && isPair2) {
        return higherValueOfPair;
    } else {
        return 0;
    }
}

int isPair(const std::vector<std::pair<int, char>> hand){
    std::map<int, int> valueCount;  
    for (const auto& card : hand) {
        valueCount[card.first]++;
    }

    // Check if there is any value with a count of 2
    for (const auto& pair : valueCount) {
        if (pair.second == 2) {
            return pair.first;  // two of a kind found
        }
    }

    return 0;  // No pair found
}
int getHighCard(const std::vector<std::pair<int, char>> hand) {
    int highestValue = 0;

    for (const auto& card : hand) {
        highestValue = std::max(highestValue, card.first);
    }

    return highestValue;
}

std::string bestPokerHand(std::string p1, std::string p2) {
    std::string p1Won = "Player one wins";
    std::string p2Won = "Player two wins";
    const std::vector<std::pair<int, char>> hand1 = parseCards(p1);
    const std::vector<std::pair<int, char>> hand2 = parseCards(p2);

    // Compare Straight Flush
    if (isStraightFlush(hand1) > isStraightFlush(hand2)) {
        return p1Won;
    } else if (isStraightFlush(hand1) < isStraightFlush(hand2)) {
        return p2Won;
    }

    // Compare Four of a Kind
    if (fourOfAkind(hand1) > fourOfAkind(hand2)) {
        return p1Won;
    } else if (fourOfAkind(hand1) < fourOfAkind(hand2)) {
        return p2Won;
    }

    // Compare Full House
    if (isFullHouse(hand1) > isFullHouse(hand2)) {
        return p1Won;
    } else if (isFullHouse(hand1) < isFullHouse(hand2)) {
        return p2Won;
    }

    // Compare Flush
    if (isflush(hand1) > isflush(hand2)) {
        return p1Won;
    } else if (isflush(hand1) < isflush(hand2)) {
        return p2Won;
    }

    // Compare Straight
    if (isStraight(hand1) > isStraight(hand2)) {
        return p1Won;
    } else if (isStraight(hand1) < isStraight(hand2)) {
        return p2Won;
    }

    // Compare Three of a Kind
    if (isThreeOfKind(hand1) > isThreeOfKind(hand2)) {
        return p1Won;
    } else if (isThreeOfKind(hand1) < isThreeOfKind(hand2)) {
        return p2Won;
    }

    // Compare Two Pair
    if (isTwoPair(hand1) > isTwoPair(hand2)) {
        return p1Won;
    } else if (isTwoPair(hand1) < isTwoPair(hand2)) {
        return p2Won;
    } else if (isTwoPair(hand1) == isTwoPair(hand2)) {
        // If Two Pair is the same, compare high cards
        if (getHighCard(hand1) > getHighCard(hand2)) {
            return p1Won;
        } else if (getHighCard(hand1) < getHighCard(hand2)) {
            return p2Won;
        }
    }

    // Compare One Pair
    if (isPair(hand1) > isPair(hand2)) {
        return p1Won;
    } else if (isPair(hand1) < isPair(hand2)) {
        return p2Won;
    } else if (isPair(hand1) == isPair(hand2)) {
        // If One Pair is the same, compare high cards
        if (getHighCard(hand1) > getHighCard(hand2)) {
            return p1Won;
        } else if (getHighCard(hand1) < getHighCard(hand2)) {
            return p2Won;
        }
    }

    // Compare High Card
    if (getHighCard(hand1) > getHighCard(hand2)) {
        return p1Won;
    } else if (getHighCard(hand1) < getHighCard(hand2)) {
        return p2Won;
    }

    // If no winner is determined, it's a tie
    return "Tie";
}



