/**
 * Generate report for an integration test.
 *
 * Copyright (c) 2019, Sekhar Ravinutala.
 */

#include <algorithm>
#include <vector>
#include <cstdio>
#include "data/data.h"
#include "match/match.h"

#define GENDER(g) (g ? "Male" : "Female")

int main() {
    std::vector<Profile> up = profiles(100);

    std::map<uint32_t, Profile> profile_map;

    for (auto p : up) {
        profile_map[p.id] = p;
    }

    auto results = Match::pairs(up);

    for (auto result : results) {
        uint32_t id1 = result.first;
        uint32_t id2 = result.second;
        double score = get_total_score(profile_map[id1], profile_map[id2]);

        printf("%-8d %-8d %lf\n", id1, id2, score);
    }
}
