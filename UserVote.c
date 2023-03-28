//
// Created by joosh on 2023-03-27.
//
#include "Candidate.h"
#include "stdio.h"
#include "string.h"

int userVote(char *candidate_name) {
    int candidate_index = -1;
    for (int i = 0; i < num_candidates; i++) {
        if (strcmp(candidates[i].name, candidate_name) == 0) {
            candidate_index = i;
            break;
        }
    }
    if (candidate_index == -1) {
        printf("Candidate not found\n");
    } else {
        candidates[candidate_index].votes++;
        printf("Vote cast successfully\n");
    }
}