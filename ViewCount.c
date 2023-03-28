//
// Created by joosh on 2023-03-23.
//
#include "Candidate.h"
#include "ViewCount.h"
#include "stdio.h"
#include "string.h"
int viewCount() {

    printf("Vote counts:\n");
    for (int i = 0; i < num_candidates; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
}


