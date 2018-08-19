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

#include "data.h"
#include <stdlib.h>
#include <inttypes.h>
#include <stdio.h>

uint32_t Data_StoreWord(const Word *entry)  {
	/* This function assumes that the parameter is well formed and does no
	 * error checking. Instead, it skips straight to storing the data. */

	FILE *dict = fopen("_database.txt", "a");
	if (NULL == dict) return DATA_FILE_ERR;

	/* Append this entry to the end of the file then close it */
	fprintf(dict, "%" PRIu32 " %s %s\n", entry->index, entry->french,
		   entry->english);
	fclose(dict);

	return DATA_OK;
}

uint32_t Data_RetrieveWord(Word *dst, const uint32_t index) {
	/* Open the word storage file and check for failure */
	FILE *dict = fopen("_database.txt", "r");
	if (NULL == dict) return DATA_ERR;

	char line_buffer[100];	// Buffer to read line data
	uint32_t cur_index;	// Stores the current index; used for comparisions

	/* Read a line of the file and search for the word with matching index */
	while (fgets(line_buffer, 100, dict) != NULL) {
		/* Skip this line if a valid index can't be found */
		cur_index = atoi(line_buffer);
		if (0 == cur_index) continue;

		/* If the desired index is found */
		if (cur_index == index) {
			/* Transmit the values to the variables */
			sscanf(line_buffer, "%" SCNu32 " %s %s", &dst->index, dst->french,
				   dst->english);

				   /* We did good */
				   return DATA_OK;
		}

		/* Keep searching! */
		else continue;
	}

	return DATA_OK;
}

uint32_t Data_CalculateWordEntries(uint32_t *num) {
	/* Set the initial value of num to zero */
	*num = 0;

	/* Open the dict.txt file and check for failure */
	FILE *dict = fopen("_database.txt", "r");
	if (NULL == dict) return DATA_FILE_ERR;

	char buffer[50];

	/* Start counting the lines */
	while (NULL != (fgets(buffer, 50, dict))) {
			(*num)++;
	}

	return DATA_OK;
}
