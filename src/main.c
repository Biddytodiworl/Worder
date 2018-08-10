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

/* This function contains most of the game logic */
void Main_PlayGame(uint32_t *, uint32_t);

/* This function lists the words in the game */
void Main_ListWords(void);

int main() {
	// Initialisation
	uint32_t num_entries;	// Number of entries
	uint32_t score = 0;	// The score during the game
	char buffer[50];	// Buffer for input
	int response;	// Response from buffer


	Prompt_GreetUser();
	Data_CalculateWordEntries(&num_entries);


	while (1) {
		Prompt_ListOptions();

		fgets(buffer, 50, stdin);
		response = atoi(buffer);

		switch (response) {
			case 0:
				Prompt_CallInputInvalid();
				break;

			case 1:
				Main_PlayGame(&score, num_entries);
				break;

			case 2:
				printf("%15s\t\t%15s\t %5s\n", "French", "English", "Index");
				Main_ListWords();
				break;

			case 3:
				Score_RetrievePointBalance(&score);
				printf("\nScore: %" PRIu32 "\n\n", score);
				break;

			case 4:
				exit(EXIT_SUCCESS);
			default:
				Prompt_CallInputInvalid();
		}
	}

	exit(EXIT_SUCCESS);
}

#include <string.h>

void Main_PlayGame(uint32_t *score, uint32_t number_of_entries) {
	char buffer[30];
	Word question = {0};

	for (int i = 1; i <= number_of_entries; ++i) {
		Data_RetrieveWord(&question, i);
		printf("What is the English for \'%s\'\n\n", question.french);

		fgets(buffer, 30, stdin);

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

/* This function can probably be implemented much better */
void Main_ListWords(void) {
	Word w = {0};	// Variable to store each record

	/* Open dict.txt and check for failure */
	FILE *dict = fopen("dict.txt", "r");
	if (NULL == dict) return;

	uint32_t num_of_entries;
	Data_CalculateWordEntries(&num_of_entries);

	for (int i = 1; i <= num_of_entries; i++) {
		Data_RetrieveWord(&w, i);
		printf("%15s\t\t%15s\t %5" PRIu32 "\n", w.french, w.english, w.index);
	}
	printf("\n\n");

	return;
}
