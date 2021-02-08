/**
 * Match declarations.
 *
 * Copyright (c) 2019, Sekhar Ravinutala.
 */

#ifndef MATCH_MATCH_H_
#define MATCH_MATCH_H_

#include <cstdint>
#include <map>
#include <vector>
#include "data/data.h"

class Match {
public:
    static std::map<uint32_t, uint32_t> pairs(std::vector<Profile> & profiles);
};


double get_total_score(const Profile& profile1, const Profile& profile2);

double country_score(const Profile& profile1, const Profile& profile2);
double diet_score(const Profile& profile1, const Profile& profile2);
double drinking_score(const Profile& profile1, const Profile& profile2);
double language_score(const Profile& profile1, const Profile& profile2);
double religion_score(const Profile& profile1, const Profile& profile2);
double smoking_score(const Profile& profile1, const Profile& profile2);

#endif  // MATCH_MATCH_H_
