#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "candidate.h"
#include "CandidateAdd.h"
#include "ViewCount.h"
#include "DeleteCandidate.h"
#include "UserVote.h"


#define MAX_CANDIDATES 100
#define MAX_NAME_LENGTH 20

int action;

int main() {
    num_candidates= 0;
    memset(candidates, 0, sizeof(candidates));



    char role[10];
    char username[20];
    char password[20];
    start:
    while (1) {
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
                if (strcmp(password, "pass123") != 0) {
                    printf("Invalid password\n");
                    break;
                }

                // code to handle admin login here
                while (1) {

                    printf("\nAdmin actions:\n");
                    printf("1. Add candidate\n");
                    printf("2. Check vote count\n");
                    printf("3. Exit\n");
                    printf("4. Delete Candidate\n");
                    printf("Enter your choice: ");
                    scanf("%d", &action);

                    switch (action) {
                        case 1: {
                            char candidate_name[MAX_NAME_LENGTH];
                            candidateAdd(candidate_name);
                            break;
                        }
                        case 2: {
                            viewCount();
                            break;
                        }
                        case 3: {
                            printf("Exiting admin mode\n");
                            goto start;
                        }
                        case 4: {
                            char candidate_name[MAX_NAME_LENGTH];
                            deleteCandidate(candidate_name);
                            break;
                        }
                    }
                }
                    default:
                        printf("Enter your username: ");
                    scanf("%s", username);
                    printf("Enter your password: ");
                    scanf("%s", password);
                    // code to handle user login here
                    while (1) {
                        printf("\nUser actions:\n");
                        printf("1. Vote for candidate\n");
                        printf("2. Check vote count\n");
                        printf("3. Exit\n");
                        printf("Enter your choice: ");
                        scanf("%d", &action);

                        switch (action) {
                            case 1: {
                                char candidate_name[MAX_NAME_LENGTH];
                                printf("Enter candidate name: ");
                                scanf("%s", candidate_name);
                                userVote(candidate_name);
                                break;
                            }
                            case 2:
                                viewCount();
                                break;

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