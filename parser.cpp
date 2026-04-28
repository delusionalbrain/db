#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> parse_resp(const string& raw) {
    vector<string> result;
    istringstream stream(raw);
    string line;

    getline(stream, line);

    while (getline(stream, line)) {
        if (line[0] == '$') {
            string word;
            getline(stream, word);
            if (!word.empty() && word.back() == '\r') word.pop_back();
            result.push_back(word);
        }
    }
    return result;
}