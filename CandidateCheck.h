//
// Created by joosh on 2023-03-23.
//

#ifndef CANDIDATE_CHECK_H
#define CANDIDATE_CHECK_H

#define MAX_CANDIDATES 100

struct Candidate {
    char name[20];
    int votes;
};

int candidateCheck(char candidate_name[], int num_candidates, struct Candidate candidates[MAX_CANDIDATES]);

#endif /* CANDIDATE_CHECK_H */



