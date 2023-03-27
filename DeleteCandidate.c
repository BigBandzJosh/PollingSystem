//
// Created by joosh on 2023-03-27.
//
#include "Candidate.h"
#include "DeleteCandidate.h"
#include "stdio.h"
#include "string.h"

int deleteCandidate(char candidate_name[]) {
    printf("Enter candidate name: ");
    scanf("%s", candidate_name);

// Find candidate index
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
        for (int i = candidate_index; i < num_candidates - 1; i++) {
            candidates[i] = candidates[i + 1];
        }
        num_candidates--;
        printf("Candidate deleted successfully\n");
    }
}