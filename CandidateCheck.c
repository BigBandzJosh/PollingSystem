//
// Created by joosh on 2023-03-23.
//

#include "CandidateCheck.h"
#include "stdio.h"
#include "string.h"


int candidateCheck(char candidate_name[], int num_candidates, struct Candidate candidates[10]) {

    int candidate_index = -1;
    for (int i = 0; i < num_candidates; i++) {
        if (strcmp(candidates[i].name, candidate_name) == 0) {
            candidate_index = i;
            if (candidate_index != -1) {
                printf("Candidate already exists\n");
            }
        } else {
            strcpy(candidates[num_candidates].name, candidate_name);
            candidates[num_candidates].votes = 0;
            num_candidates++;
            printf("Candidate added successfully\n");
        }
    }
    return 0;
}
