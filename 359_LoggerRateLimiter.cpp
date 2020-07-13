//
// Created by Chunbin lin on 7/11/20.
//

class Logger {
private:
    unordered_map<string, int> logHistory;
public:
    /** Initialize your data structure here. */
    Logger() {

    }

    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        if (!logHistory.count(message)) {
            logHistory[message] = timestamp;
            return true;
        } else {
            //we have the message
            if (timestamp - logHistory[message] >= 10) {
                //update history, and print
                logHistory[message] = timestamp;
                return true;
            }
        }

        return false;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */