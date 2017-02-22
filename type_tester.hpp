#pragma once

#include <atomic>
#include <sstream>

/*
 * Global keeps all the global variables
 *
 * Singleton design, only one instance can be created
 *
 * When scope ends (program finish/Ctrl-c) the destructor will run
 */

typedef class TypeTester {
private:

    std::atomic<bool> times_up;
    std::atomic<bool> force_quit;

    unsigned run_time;
    unsigned num_words_read;
    unsigned passage_len;
    unsigned min_word_len;

    stringstream console_out;

public:

    void run();

private:

    TypeTester();

    /*
     * Get default parameters
     */
    void get_params();
    
    /*
     * Reads common word list
     */
    void get_words();

    /*
     * Builds the passage the user have to type up
     */
    void build_passage();

    /*
     * Get user input character from console
     */
    void get_input();

    /*
     * Print user prompt terminal
     */
    void print_console_prompt();

public:

    static TypeTester& get_inst() {
        static TypeTester inst;
        return inst;
    }

    TypeTester(TypeTester const&) = delete;
    void operator=(TypeTester const&) = delete;

} type_tester_t;
