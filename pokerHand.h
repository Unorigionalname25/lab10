#ifndef pokerHand_h
#define pokerHand_h

#include <string>
#include <string>
#include <vector>
#include <map>

std::string bestPokerHand(std::string p1, std::string p2);
std::vector<std::pair<int, char>> parseCards(std::string p1);
int isStraightFlush(std::vector<std::pair<int, char>> hand);
int fourOfAkind(const std::vector<std::pair<int, char>>& hand);
int isFullHouse(const std::vector<std::pair<int, char>>& hand);
int isflush(const std::vector<std::pair<int, char>> hand);
int isStraight(const std::vector<std::pair<int, char>> hand);
int isThreeOfKind(const std::vector<std::pair<int, char>> hand);
int isTwoPair(const std::vector<std::pair<int, char>>& hand);
int isPair(const std::vector<std::pair<int, char>> hand);
int getHighCard(const std::vector<std::pair<int, char>> hand);


#endif