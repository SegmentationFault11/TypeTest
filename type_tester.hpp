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

    unsigned run_time;

    stringstream console_out;

public:

    void run_type_tester();

private:

    TypeTester();

    /*
     * Reads common word list
     */
    void get_words();

    /*
     * Get default parameters
     */
    void get_params();

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
