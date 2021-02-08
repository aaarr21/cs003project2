#include "match.h"

std::map<uint32_t, uint32_t> Match::pairs(std::vector<Profile>& profiles) {
    std::map<uint32_t, uint32_t> results;

    std::vector<Profile> males;
    std::vector<Profile> females;

    for (auto profile : profiles) {
        if (profile.gender == MALE) {
            males.push_back(profile);
        } else {
            females.push_back(profile);
        }
    }

    for (auto male : males) {
        double max_score = 0.0;
        for (const Profile& female : females) {
            double score = get_total_score(male, female);

            if (score > max_score) {
                results[male.id] = female.id;
                max_score = score;
            }
        }
    }

    return results;
}

double get_total_score(const Profile& profile1, const Profile& profile2) {
    assert(profile1.gender != profile2.gender);

    return country_score(profile1, profile2)
        + diet_score(profile1, profile2)
        + drinking_score(profile1, profile2)
        + language_score(profile1, profile2)
        + religion_score(profile1, profile2)
        + smoking_score(profile1, profile2);
}

double country_score(const Profile& profile1, const Profile& profile2) {
    assert(profile1.gender != profile2.gender);

    if (std::get<0>(profile1.country) == std::get<0>(profile2.country)) {
        return std::get<1>(profile1.country) + std::get<1>(profile2.country);
    } else {
        return 0.0;
    }
}

double diet_score(const Profile& profile1, const Profile& profile2) {
    assert(profile1.gender != profile2.gender);

    if (std::get<0>(profile1.diet) == std::get<0>(profile2.diet)) {
        return std::get<1>(profile1.diet) + std::get<1>(profile2.diet);
    } else {
        return 0.0;
    }
}

double drinking_score(const Profile& profile1, const Profile& profile2) {
    assert(profile1.gender != profile2.gender);

    if (std::get<0>(profile1.drinking) == std::get<0>(profile2.drinking)) {
        return std::get<1>(profile1.drinking) + std::get<1>(profile2.drinking);
    } else {
        return 0.0;
    }
}

double language_score(const Profile& profile1, const Profile& profile2) {
    assert(profile1.gender != profile2.gender);

    if (std::get<0>(profile1.language) == std::get<0>(profile2.language)) {
        return std::get<1>(profile1.language) + std::get<1>(profile2.language);
    } else {
        return 0.0;
    }
}

double religion_score(const Profile& profile1, const Profile& profile2) {
    assert(profile1.gender != profile2.gender);

    if (std::get<0>(profile1.religion) == std::get<0>(profile2.religion)) {
        return std::get<1>(profile1.religion) + std::get<1>(profile2.religion);
    } else {
        return 0.0;
    }
}

double smoking_score(const Profile& profile1, const Profile& profile2) {
    assert(profile1.gender != profile2.gender);

    if (std::get<0>(profile1.smoking) == std::get<0>(profile2.smoking)) {
        return std::get<1>(profile1.smoking) + std::get<1>(profile2.smoking);
    } else {
        return 0.0;
    }
}
