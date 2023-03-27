cmake_minimum_required(VERSION 3.24)
project(PollingSystem C)

set(CMAKE_C_STANDARD 11)

add_executable(PollingSystem main.c CandidateAdd.h CandidateAdd.c ViewCount.c ViewCount.h DeleteCandidate.c DeleteCandidate.h UserVote.c UserVote.h Candidate.h)
