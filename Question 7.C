#include <stdio.h>

#define MAX_FRAMES 3

int main() {
    int frames[MAX_FRAMES] = {0};
    int page_faults = 0;
    int references[] = {1, 2, 3, 2, 1, 5, 2, 1, 6, 2, 5, 6, 3, 1, 3, 6, 1, 2, 4, 3};
    int num_references = sizeof(references) / sizeof(references[0]);

    for (int i = 0; i < num_references; i++) {
        int page = references[i];
        int j, k;
        for (j = 0; j < MAX_FRAMES; j++) {
            if (frames[j] == page) {
                // Page is already in frame, so no page fault
                break;
            }
        }
        if (j == MAX_FRAMES) {
            // Page is not in frame, so we need to replace the LRU page
            int min_idx = 0;
            for (k = 1; k < MAX_FRAMES; k++) {
                if (frames[k] < frames[min_idx]) {
                    min_idx = k;
                }
            }
            frames[min_idx] = page;
            page_faults++;
        }
        // Update the age of the pages in the frames
        for (k = 0; k < MAX_FRAMES; k++) {
            if (frames[k] != 0) {
                frames[k]++;
            }
        }
        // Reset the age of the page that was just referenced
        for (k = 0; k < MAX_FRAMES; k++) {
            if (frames[k] == page) {
                frames[k] = 1;
            }
        }
    }

    printf("Number of page faults: %d\n", page_faults);

    return 0;
}
