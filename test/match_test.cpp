#include "data/data.h"
#include "match/match.h"
#include "gtest/gtest.h"

const double delta = 0.0001;

const Profile test_profile_male_1 = {
    1,
    MALE,
    {USA, 0.2},
    {NONVEGETARIAN, 0.4},
    {true, 0.5},
    {ENGLISH, 0.6},
    {CHRISTIAN, 0.5},
};

const Profile test_profile_male_2 = {
    2,
    MALE,
    {CANADA, 0.5},
    {VEGETARIAN, 0.9},
    {true, 0.3},
    {FRENCH, 0.6},
    {BUDDHIST, 0.3},
};

const Profile test_profile_male_3 = {
    3,
    MALE,
    {MEXICO, 0.5},
    {VEGAN, 0.7},
    {false, 0.2},
    {SPANISH, 0.6},
    {JEWISH, 0.8},
};

const Profile test_profile_female_4 = {
    4,
    FEMALE,
    {USA, 0.3},
    {VEGAN, 0.7},
    {false, 0.9},
    {ENGLISH, 0.5},
    {CHRISTIAN, 0.4},
};

const Profile test_profile_female_5 = {
    5,
    FEMALE,
    {CANADA, 0.4},
    {EGGETARIAN, 0.7},
    {true, 0.2},
    {FRENCH, 0.8},
    {JEWISH, 0.4},
};

const Profile test_profile_female_6 = {
    6,
    FEMALE,
    {MEXICO, 0.3},
    {VEGETARIAN, 0.7},
    {false, 0.1},
    {SPANISH, 0.5},
    {BUDDHIST, 0.4},
};

TEST(Profile, score_test) {
    EXPECT_NEAR(country_score(test_profile_male_1, test_profile_female_4),
                0.5, delta);
    EXPECT_NEAR(country_score(test_profile_male_1, test_profile_female_5),
                0.0, delta);

    EXPECT_NEAR(diet_score(test_profile_male_1, test_profile_female_4),
                0.0, delta);
    EXPECT_NEAR(diet_score(test_profile_male_2, test_profile_female_6),
                1.6, delta);

    EXPECT_NEAR(drinking_score(test_profile_male_3, test_profile_female_5),
                0.0, delta);
    EXPECT_NEAR(drinking_score(test_profile_male_2, test_profile_female_5),
                0.5, delta);
    EXPECT_NEAR(drinking_score(test_profile_male_3, test_profile_female_6),
                0.3, delta);

    EXPECT_NEAR(language_score(test_profile_male_1, test_profile_female_4),
                1.1, delta);
    EXPECT_NEAR(language_score(test_profile_male_2, test_profile_female_5),
                1.4, delta);
    EXPECT_NEAR(language_score(test_profile_male_3, test_profile_female_4),
                0.0, delta);

    EXPECT_NEAR(get_total_score(test_profile_male_1, test_profile_female_4),
                2.5, delta);
    EXPECT_NEAR(get_total_score(test_profile_male_1, test_profile_female_5),
                0.7, delta);
    EXPECT_NEAR(get_total_score(test_profile_male_1, test_profile_female_6),
                0.0, delta);
    EXPECT_NEAR(get_total_score(test_profile_male_2, test_profile_female_4),
                0.0, delta);
    EXPECT_NEAR(get_total_score(test_profile_male_2, test_profile_female_5),
                2.8, delta);
    EXPECT_NEAR(get_total_score(test_profile_male_2, test_profile_female_6),
                2.3, delta);
    EXPECT_NEAR(get_total_score(test_profile_male_3, test_profile_female_4),
                2.5, delta);
    EXPECT_NEAR(get_total_score(test_profile_male_3, test_profile_female_5),
                1.2, delta);
    EXPECT_NEAR(get_total_score(test_profile_male_3, test_profile_female_6),
                2.2, delta);
}

TEST(Match, match_test) {
    std::vector<Profile> profiles = {
        test_profile_male_1,
        test_profile_male_2,
        test_profile_female_4,
        test_profile_male_3,
        test_profile_female_5,
        test_profile_female_6,
    };

    EXPECT_EQ(Match::pairs(profiles),
              (std::map<uint32_t, uint32_t>({
                      {1, 4},
                      {2, 5},
                      {3, 4},
                  })));
}
