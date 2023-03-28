//
// Created by joosh on 2023-03-23.
//
#include "Candidate.h"
#include "CandidateAdd.h"
#include "stdio.h"
#include "string.h"

int num_candidates = 0;
struct Candidate candidates[MAX_CANDIDATES];


int candidateAdd(char *candidate_name) {
    printf("Enter candidate name: ");
    scanf("%s", candidate_name);

    // Check if candidate already exists
    int candidate_index = -1;
    for (int i = 0; i < num_candidates; i++) {
        if (strcmp(candidates[i].name, candidate_name) == 0) {
            candidate_index = i;
            break;
        }
    }
    if (candidate_index == -1){
        candidates[num_candidates].votes = 0;
        strcpy(candidates[num_candidates].name, candidate_name);
        num_candidates++;
        printf("Candidate added successfully\n");
    } else {
        printf("Candidate already exists\n");
    }
    return 0;
}