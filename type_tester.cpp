#include "type_tester.hpp"

#include <unordered_map>
#include <fstream>
#include <string>
#include <stdexcept>
#include <exception>

using namespace std;

void
TypeTester::run() {
    times_up = false;

    get_params();
    get_words();

    gen_passage();

    while (!times_up || !force_quit) {
        get_input();
    }

    add_log();
}

void
TypeTester::get_params() {
    string params_file_name = "./param.properties";
    ifstream param_file(params_file_name);

    if (!param_file) 
    {
        throw invalid_argument(params_file_name + 
                " not found. Unable to initialize variables.");
    }

    unordered_map<string, pair<bool, unsigned *>> init_status;
    init_status["run_time"] = make_pair(false, &this->run_time);
    init_status["num_words_read"] = make_pair(false, &this->num_words_read);
    init_status["passage_len"] = make_pair(false, &this->passage_len);
    init_status["min_word_len"] = make_pair(false, &this->min_word_len);

    string line;
    while (getline(param_file, line)) 
    {
        istringstream iss(line);

        string param;
        string value;
        if (!(iss >> param >> value)) 
        {
            throw invalid_argument("Incorrect input parameter format.");
        }

        auto iter = init_status.find(param);
        if (iter == init_status.end()) 
        {
            throw invalid_argument("Unrecognized parameter: " + param + ".");
        }

        iter->second.first = true;
        *(iter->second.second) = stof(value);
    }

    for (auto iter = init_status.begin(); iter != init_status.end(); ++iter) 
    {
        if (!iter->second.first) 
        {
            throw invalid_argument(iter->first + " left uninitialized.");
        }
    }
}

void 
TypeTester::get_words() {
    string words_file_name = "./words.txt";
    ifstream words_file(words_file_name);

    if (!words_file) {
        throw invalid_argument(words_file_name + 
                " not found. Unable to fill dictionary");
}
