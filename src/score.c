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

#include "score.h"
#include <stdio.h>
#include <inttypes.h>

uint32_t Score_AwardPoints(uint32_t *tally) {
	/* Award the points */
	*tally += SCORE_QUANTITY;

	return SCORE_OK;
}

uint32_t Score_StorePointBalance(const uint32_t balance) {
	/* Score data is stored in _score.txt */
	FILE *store = fopen("_score.txt", "w");

	/* Exit if unsuccessful */
	if (NULL == store) return SCORE_FILE_ERR;

	/* Write the point balance to disk */
	fprintf(store, "%" PRIu32 "\n", balance);

	/* Close the file */
	fclose(store);

	return SCORE_OK;
}

uint32_t Score_RetrievePointBalance(uint32_t *points) {
	/* Retrieve score data from _score.txt */
	FILE *store = fopen("_score.txt", "r");

	/* Exit if unsuccessful */
	if (NULL == store) return SCORE_FILE_ERR;

	/* Get the point balance from the file */
	if (1 != (fscanf(store, "%" SCNu32, points)) ) return SCORE_ERR;

	return SCORE_OK;
}
