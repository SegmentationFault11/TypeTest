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
     * Promptly print console to terminal
     */
    void print_console();

public:

    static TypeTester& get_inst() {
        static TypeTester inst;
        return inst;
    }

    TypeTester(TypeTester const&) = delete;
    void operator=(TypeTester const&) = delete;

} type_tester_t;
