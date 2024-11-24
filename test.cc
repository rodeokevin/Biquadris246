#include "level.h"
#include "level0.h"
#include "probsLevel.h"
#include <vector>
#include <cstdlib>
#include <memory>
#include <string>
#include <iostream>

int main(int argc, char* argv[]) {
    std::srand(std::stoi(argv[1]));
    const int NUM_BLOCKS = 7;
    std::string s1 = "test1.txt";
    std::string s2 = "test2.txt";
    int outputProbs = std::stoi(argv[2]), outputBlocks = std::stoi(argv[3]);

    std::vector<float> LEVEL1{0, 0, 0, 0, 1 / 12.0, 1 / 12.0, 0};
    std::vector<float> LEVEL2(NUM_BLOCKS, 0.0);
    std::vector<float> LEVEL3_4{0, 0, 0, 0, 2 / 9.0, 2 / 9.0, 0};
    
    std::unique_ptr<Level> l0 = std::make_unique<Level0>(0, s1, s2);
    std::unique_ptr<Level> l1 = std::make_unique<ProbsLevel>(1, LEVEL1);
    std::unique_ptr<Level> l2 = std::make_unique<ProbsLevel>(2, LEVEL2);
    std::unique_ptr<Level> l3 = std::make_unique<ProbsLevel>(3, LEVEL3_4);
    std::unique_ptr<Level> l4 = std::make_unique<ProbsLevel>(4, LEVEL3_4);

    std::vector<std::unique_ptr<Level>> levels;
    levels.push_back(std::move(l0));
    levels.push_back(std::move(l1));
    levels.push_back(std::move(l2));
    levels.push_back(std::move(l3));
    levels.push_back(std::move(l4));

    if (outputProbs) l3->outputProbs();

    if (outputBlocks) {
        for (int i = 0; i < 20; ++i) {
            std::cout << "Level " << l2->getLevel() << " produces block: " << l2->produceBlock(i % 2) << std::endl;
        }
    }
}
