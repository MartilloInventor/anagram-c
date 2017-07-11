//
// Created by algotrader on 7/11/17.
//

#include <stdio.h>
#include <memory.h>
#include <time.h>

int main() {
    int instancearray[26];
    char src[12][10] = {
            "dfgjkdjdma",
            "dnjmfzjdma",
            "dfgdqdfdma",
            "dfgjkdjdma",
            "dfgsklaama",
            "dfsjkdjdma",
            "dfgjkdjdma",
            "rfglkwhyma",
            "dfgjkdjdma",
            "qqqjkdjqma",
            "dfgjkdqwea",
            "suxjkdjdma"
    };
    char trg[12][10] = {
            "fdjgdkdjma",
            "ndjmzjamda",
            "dgfqddfdma",
            "dfsjdkjmda",
            "fdgsklamaa",
            "dfjekjddma",
            "dfgjkdjdma",
            "rgfkflyhma",
            "dfgjkjdmad",
            "qqqjdgjqma",
            "dfgjkdqwea",
            "suxjdkhdma"
    };
    long count_fail = 0; // had to make this variable long
    int start_time = 0;
    int end_time = 0;
    int iterations = 0;
    int max = 0xFFFFFFF;
    int i = 0;
    int j = 0;


    start_time = (int) time(NULL);
    for (iterations = 0; iterations < max; ++iterations) {
        bzero(instancearray, 26*sizeof(int));
        for (i = 0; i < 12; ++i) {
            for (j = 0; j < 10; ++j) {
                ++instancearray[src[i][j] - 'a'];
            }
            for (j = 0; j < 10; ++j) {
                --instancearray[trg[i][j] - 'a'];
                if (instancearray[trg[i][j] - 'a'] < 0) {
                    ++count_fail;
                    break;    /* skip to next test */
                }
            }
        }
    }
    end_time = (int) time(NULL);
    printf("Total failures %ld in %d seconds %d iterations\n", count_fail, end_time - start_time, max);
}
