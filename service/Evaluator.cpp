//
// Created by renan on 25/08/18.
//

#include <limits>
#include <algorithm>
#include <iostream>
#include "Evaluator.h"

Evaluator::Evaluator() {
    Evaluator::smaller = std::numeric_limits<double>::infinity();
    Evaluator::bigger = -1 * (std::numeric_limits<double>::infinity());
    Evaluator::mean = 0;
};

void Evaluator::evaluate(Auction *auction) {
    if (!auction->getBids().empty()) {
        Evaluator::biggest = auction->getBids();
        std::sort(Evaluator::biggest.begin(), Evaluator::biggest.end(), std::greater<Bid *>());
        if (Evaluator::biggest.size() > 3) {
            Evaluator::smaller = Evaluator::biggest[biggest.size() - 1]->getValue();
            Evaluator::bigger = Evaluator::biggest[0]->getValue();
            std::vector<Bid *>::const_iterator first = Evaluator::biggest.begin();
            std::vector<Bid *> newVec(first, first + 3);
            Evaluator::biggest = newVec;
        } else {
            Evaluator::smaller = Evaluator::biggest[biggest.size() - 1]->getValue();
            Evaluator::bigger = Evaluator::biggest[0]->getValue();
        }
    }

    //TODO Free the pointer;

}

double Evaluator::getBigger() const {
    return bigger;
}

double Evaluator::getSmaller() const {
    return smaller;
}

void Evaluator::calculate(Auction *auction) {
    for (Bid *bid: auction->getBids()) {
        mean += bid->getValue();
    }
    mean = mean / auction->getBids().size();
}

double Evaluator::getMean() const {
    return mean;
}

const std::vector<Bid *> &Evaluator::getBiggest() const {
    return biggest;
}

std::vector<Bid *> Evaluator::filter(Auction *auction) {
    std::vector<Bid *> bids;
    if (auction->getBids().empty()) {
        return bids;
    }

    for (Bid *bid : auction->getBids()) {
        if (bid->getValue() > 1000 && bid->getValue() < 3000) {
            bids.push_back(bid);
        } else if (bid->getValue() > 500 && bid->getValue() < 700) {
            bids.push_back(bid);
        } else if (bid->getValue() > 5000) {
            bids.push_back(bid);
        }
    }

    return bids;

}


