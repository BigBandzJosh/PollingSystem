#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "CandidateCheck.h"
#include "ViewCount.h"

#define MAX_CANDIDATES 100


int main() {
    int num_candidates = 0;
    struct Candidate candidates[MAX_CANDIDATES];

    bool on = true;

            char role[10];
            char username[20];
            char password[20];
            start:
    while (on) {
            printf("Enter your role (admin/user): ");
            scanf("%s", role);

            switch (strcmp(role, "admin")) {
                case 0:
                        printf("Enter your username: ");
                        scanf("%s", username);
                        if (strcmp(username, "admin") != 0) {
                            printf("Invalid username\n");
                            break;
                        }
                        printf("Enter your password: ");
                        scanf("%s", password);
                        if (strcmp(password, "adminPassword") != 0) {
                            printf("Invalid password\n");
                            break;
                        }

                    // code to handle admin login here
                    while (1) {
                        int action;
                        printf("\nAdmin actions:\n");
                        printf("1. Add candidate\n");
                        printf("2. Check vote count\n");
                        printf("3. Exit\n");
                        printf("4. Delete Candidate\n");
                        printf("Enter your choice: ");
                        scanf("%d", &action);

                        switch (action) {
                            case 1: {
                                char candidate_name[20];
                                printf("Enter candidate name: ");
                                scanf("%s", candidate_name);
                                // Check if candidate already exists
                                candidateCheck(candidate_name, num_candidates, candidates);
                                }
                                break;
                            }
                            case 2: {

                                viewCount(num_candidates, candidates);
                                break;
                            }
                            case 3: {
                                printf("Exiting admin mode\n");
                                goto start;
                            }
                            case 4: {
                                char candidate_name[20];
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
                                break;
                            }
                        }
                        break;
                        default:
                            printf("Enter your username: ");
                        scanf("%s", username);
                        printf("Enter your password: ");
                        scanf("%s", password);
                        // code to handle user login here
                        while (1) {
                            int action;
                            printf("\nUser actions:\n");
                            printf("1. Vote for candidate\n");
                            printf("2. Check vote count\n");
                            printf("3. Exit\n");
                            printf("Enter your choice: ");
                            scanf("%d", &action);

                            switch (action) {
                                case 1: {
                                    char candidate_name[20];
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
                                        candidates[candidate_index].votes++;
                                        printf("Vote cast successfully\n");
                                    }
                                    break;
                                }
                                case 2: {
                                    if (num_candidates == 0) {
                                        printf("No candidates added yet.\n");
                                    } else {
                                        printf("Candidate\tVotes\n");
                                        for (int i = 0; i < num_candidates; i++) {
                                            printf("%s\t\t%d\n", candidates[i].name, candidates[i].votes);
                                        }
                                    }
                                    break;
                                }
                                case 3: {
                                    printf("Exiting user mode\n");
                                    goto start;
                                    default:
                                        printf("Invalid choice");
                                }
                            }
                        }
                    }

            }

    }
    return 0;
}

