//
// Created by Chunbin lin on 9/1/20.
//

/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int size = 0, read = 4;
        while (size < n && read == 4) {
            read = read4(buf+size);
            size += read;
        }
        return min(n, size);
    }

};