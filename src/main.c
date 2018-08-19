/* Worder - Learning application geared towards French improvement
 * MIT License
 *
 * Copyright (c) 2018 Brendon Henry
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "data.h"
#include "prompt.h"
#include "score.h"

/* These macros are specifically used by and for the Main_ReadYesNo
 * function */
#define MAIN_YES	1
#define MAIN_NO	0

/* These are the input options on the main screen */
#define MAIN_START 1
#define MAIN_VIEW_DB	2
#define MAIN_VIEW_SCORE	3
#define MAIN_EXIT	4

/* This function contains most of the app logic */
void Main_PlayGame(uint32_t *);

/* This function lists the words in the app */
void Main_ListWords(void);

/* This function reads a yes or no input */
uint32_t Main_ReadYesNo(void);

/* This function displays the score stored on record */
void Main_ShowScore(void);

int main() {
	// Initialisation
	uint32_t num_entries;	// Number of entries
	uint32_t score = 0;	// The score during the app
	char buffer[50];	// Buffer for input
	uint32_t response;	// Response from buffer
	uint32_t ret;	// Return value from Data_CalculateWordEntries

	Word w = {0};	// Adding records to the database

	Prompt_GreetUser();

	while (1) {
		Prompt_ListOptions();

		fgets(buffer, 50, stdin);
		response = atoi(buffer);

		switch (response) {
			case MAIN_START:
				Main_PlayGame(&score);
				break;

			case MAIN_VIEW_DB:
				/* Calculate the number of entries in the database file */
				ret = Data_CalculateWordEntries(&num_entries);

				if (DATA_FILE_ERR == ret) {
					Prompt_DeclareNoDatabase();

					/* Receive confirmation to create new database file. */
					response = Main_ReadYesNo();
					printf("\n");

					if (MAIN_YES == response) {
						/* Create a new file */
						FILE *new_file = fopen("_database.txt", "w");

						if (NULL == new_file)
							puts("\nFailed to create database file.\n");
						else {
							puts("Successfully created database.\n");
							fclose(new_file);
						}
					}
				}

				else if (0 == num_entries) {
					Prompt_DeclareDatabaseEmpty();

					/* Read response and add a line for organisation points */
					response = Main_ReadYesNo();
					puts("");

					if (MAIN_YES == response) {
						FILE *new_file = fopen("_database.txt", "w");
						if (NULL == new_file) puts("\nFailed to create data"
							"base file.\n");
						else {
							/* Continue adding records until the user says no */
							while (response == MAIN_YES) {
								w.index += 1;

								printf("Enter the English word: ");
								fgets(buffer, 30, stdin);
								sscanf(buffer, "%s", w.english);

								printf("Enter the French word: ");
								fgets(buffer, 30, stdin);
								sscanf(buffer, "%s", w.french);

								/* Attempt to store the word */
								ret = Data_StoreWord(&w);
								if (DATA_FILE_ERR == ret){
									printf("Failed to store record.\n");
									printf("Would you like to try again?");
								}
								else {
									printf("Successfully stored word. Do you want to store another"
									" (y/n)? ");
								}

								response = Main_ReadYesNo();
							}

							fclose(new_file);
						}
					}
				}
				else {
					Main_ListWords();
				}
				break;

			case MAIN_VIEW_SCORE:
				Main_ShowScore();
				break;

			case MAIN_EXIT:
				exit(EXIT_SUCCESS);
			default:
				Prompt_CallInputInvalid();
		}
	}

	exit(EXIT_SUCCESS);
}

#include <string.h>

void Main_PlayGame(uint32_t *score) {
	/* Find out how many entries are in the database. If it is zero do not
	 * continue. */
	uint32_t number_of_entries;
	Data_CalculateWordEntries(&number_of_entries);

	/* If the database is empty stop now */
	if (0 == number_of_entries ) {
		printf("\nDatabase is empty. You must have at least one record in your"
		" database to use the program.\n\n");
		return;
	}
	/* Buffer and Word structure for running the app */
	char buffer[30];
	Word question = {0};

	for (int i = 1; i <= number_of_entries; ++i) {
		/* Write to the Word variable and use it to question */
		Data_RetrieveWord(&question, i);
		printf("\nWhat is the English for \'%s\'\n\n", question.french);

		/* Gather the response */
		fgets(buffer, 30, stdin);

		/* Check for a correct answer */
		if (0 == strncmp(buffer, question.english, strlen(buffer) - 1)) {
			Prompt_Congratulate();
			Score_AwardPoints(score);
			Score_StorePointBalance(*score);
		}
		else {
			Prompt_CallAnswerWrong(question.english);
		}
	}


	return;
}

void Main_ListWords(void) {
	/* Open _database.txt and check for failure */
	FILE *dict = fopen("_database.txt", "r");
	if (NULL == dict) return;

	Word w = {0};	// Buffer variable to store each record

	/* Get the number of entries in the database */
	uint32_t num_of_entries;
	Data_CalculateWordEntries(&num_of_entries);

	/* If the database is empty say so, else print what is there */
	if (0 == num_of_entries ) {
		printf("\nDatabase is empty.\n\n");
		return;
	}

	printf("%15s\t\t%15s\t %5s\n", "French", "English", "Index");

	for (int i = 1; i <= num_of_entries; i++) {
		Data_RetrieveWord(&w, i);
		printf("%15s\t\t%15s\t %5" PRIu32 "\n", w.french, w.english, w.index);
	}

	return;
}

uint32_t Main_ReadYesNo(void) {
	/* Store the response in a 5 character buffer */
	char buffer[5];
	uint32_t response = MAIN_NO;

	/* Read the data and extract the response */
	fgets(buffer, 5, stdin);
	if ('y' == buffer[0] || 'Y' == buffer[0]) {
		response = MAIN_YES;
		return response;
	}
	else if ('n' == buffer[0] || 'N' == buffer[0]) {
		return response;
	}

	/* If the answer is not y/Y or n/N, it is assumed to be n/N. */
	return response;
}

void Main_ShowScore(void) {
	/* Attempt to read the _score.txt data file and handle the outcome. */
	uint32_t score;
	uint32_t ret = Score_RetrievePointBalance(&score);
	uint32_t response;

	if (SCORE_FILE_ERR == ret) {
		printf("\nThere is no score data file to read from. Do you want to create"
		" one (y/n)? 	");

		response = Main_ReadYesNo();
		if (MAIN_NO == response) {
			printf("\nOkay.\n\n");
		}
		else if (MAIN_YES == response) {
			ret = Score_StorePointBalance(0);
			if (SCORE_FILE_ERR == ret) {
				printf("\nUnable to create data file.\n\n");
				return;
			}
			else {
				printf("Okay. Data file created and score set to zero.\n\n");
				return;
			}
		}
		return;
	}
	else if (SCORE_ERR == ret) {
		printf("\nThere is no score data.\n\n");
		return;
	}
	else {
		printf("\nScore: %" PRIu32 "\n\n", score);
	}

	return;
}
