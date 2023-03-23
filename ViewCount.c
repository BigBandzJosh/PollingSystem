//
// Created by joosh on 2023-03-23.
//

#include "ViewCount.h"
#include "stdio.h"

int viewCount(int num_candidates, struct Candidate candidates[10]) {
    if (num_candidates == 0) {
        printf("No candidates added yet.\n");
    } else {
        printf("Candidate\tVotes\n");
        for (int i = 0; i < num_candidates; i++) {
            printf("%s\t\t%d\n", candidates[i].name, candidates[i].votes);
        }
    }
}

