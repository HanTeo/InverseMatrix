#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "library.cpp"
#include <future>

using namespace Eigen;

TEST_CASE("7 choose 4 and 4 choose 3 is 140") {
    REQUIRE(choice(7, 4) * choice(4, 3) == 140);
}

SCENARIO("7 choose 4 produces 35 combinations") {

    GIVEN("I have seven unique numbers") {
        vector<int> numbers = {1, 2, 3, 4, 5, 6, 7};

        WHEN("I choose 4 from the numbers") {
            auto combination = combinations(numbers, 4);

            THEN("I get 35 combinations") {
                REQUIRE(combination.size() == 35);
            }
        }
    }
}

SCENARIO("4 choose 3 produces 4 combinations") {

    GIVEN("I have seven unique numbers") {
        vector<int> numbers = {1, 2, 3, 4};

        WHEN("I choose 4 from the numbers") {
            auto combination = combinations(numbers, 3);

            THEN("I get 35 combinations") {
                REQUIRE(combination.size() == 4);
            }
        }
    }
}

SCENARIO("7 choose 4 then 4 choose 3") {

    GIVEN("I have seven unique numbers") {
        vector<int> numbers = {1, 2, 3, 4, 5, 6, 7};

        WHEN("I choose 4 from 7 then 3 from 4 numbers") {
            auto combination = kcombinations(combinations(numbers, 4), 3);

            THEN("I have 140 combinations") {
                REQUIRE(combination.size() == 140);
            }
        }
    }
}

TEST_CASE("Build Square Matrix") {
    vector<float> numbers = {1, 2, 3, 4, 5, 6, 7};
    auto matrix = buildMatrix(numbers);

    cout << matrix;
}

TEST_CASE("To Eigen") {
    vector<float> numbers = {1, 2, 1, 2, 1, 0, -1, 1, 2};
    auto eigen = toEigen(numbers, 3);
    cout << eigen << endl << endl;
    cout << eigen.inverse() << endl;
}


SCENARIO("7 choose 4 then 4 choose 3 the permute") {

    GIVEN("I have seven numbers") {
        vector<float> numbers = {1, 2, 1, 3, 1, 0, -1};

        WHEN("I choose 4 from 7 then 3 from 4 numbers") {
            auto combination = kcombinations(combinations(numbers, 4), 3);

            THEN("I have 140 combinations") {

                REQUIRE(combination.size() == 140);

                auto fn = [](vector<float> c) {
                    auto mat = buildMatrix(c);

                    if (mat.determinant() == 0)
                        return;

                    cout << "Combinations:" << endl;
                    for (auto e : c)
                        cout << e << " ";
                    cout << endl << endl;

                    cout << "Matrix:" << endl;
                    cout << mat << endl << endl;

                    cout << "Inverse:" << endl;
                    cout << mat.inverse() << endl << endl;
                };

                vector<future<void>> futures(140);

                for (auto c : combination) {
                    futures.push_back(async(launch::async, fn, c));
                }
            }
        }
    }
}

