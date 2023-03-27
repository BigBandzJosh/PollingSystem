//
// Created by joosh on 2023-03-27.
//

#ifndef POLLINGSYSTEM_CANDIDATE_H
#define POLLINGSYSTEM_CANDIDATE_H

#define MAX_CANDIDATES 100

struct Candidate {
    char name[20];
    int votes;
};

extern struct Candidate candidates[MAX_CANDIDATES];
extern int num_candidates;

#endif //POLLINGSYSTEM_CANDIDATE_H
